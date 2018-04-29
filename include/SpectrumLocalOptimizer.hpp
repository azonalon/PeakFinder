#pragma once
#include <Eigen/Core>
#include <unsupported/Eigen/NonLinearOptimization>
#include "../include/Spectrum.hpp"
#include <fstream>
#include <Eigen/StdVector>

class SpectrumLocalOptimizer {
    template<typename _Scalar, int NX=Eigen::Dynamic, int NY=Eigen::Dynamic>
    struct Functor
    {
      typedef _Scalar Scalar;
      enum {
        InputsAtCompileTime = NX,
        ValuesAtCompileTime = NY
      };
      typedef Eigen::Matrix<Scalar,InputsAtCompileTime,1> InputType;
      typedef Eigen::Matrix<Scalar,ValuesAtCompileTime,1> ValueType;
      typedef Eigen::Matrix<Scalar,ValuesAtCompileTime,InputsAtCompileTime> JacobianType;

      const int m_inputs, m_values;

      Functor() : m_inputs(InputsAtCompileTime), m_values(ValuesAtCompileTime) {}
      Functor(int inputs, int values) : m_inputs(inputs), m_values(values) {}

      int inputs() const { return m_inputs; }
      int values() const { return m_values; }

      // you should define that in the subclass :
    //  void operator() (const InputType& x, ValueType* v, JacobianType* _j=0) const;
    };

    struct LeastSquaresFunctor : Functor<double>
    {
        Spectrum& spectrum;
        LeastSquaresFunctor(Spectrum& spectrum):
            Functor(spectrum.parameterCount(),
                    spectrum.frequencies.size()), spectrum(spectrum)  {}
        int operator()(const Eigen::VectorXd &x, Eigen::VectorXd &fvec) const
        {
            spectrum.setPeaks(x);
            fvec = -spectrum.actualSpectrum + spectrum.computePeakSpectrum();
            return 0;
        }
        int df(const Eigen::VectorXd &x, Eigen::MatrixXd &fjac) const
        {
            spectrum.setPeaks(x);
            spectrum.computeJacobian(fjac);
            return 0;
        }
    };
public:
    struct Result {
        long nfev;
        double chiSquareError;
    };
    Spectrum& s;
    SpectrumLocalOptimizer(Spectrum& s) : s(s) {
        // TODO: determine ftol and stuff from actualSpectrum
    };

    template<class _arrayType>
    Result optimize(_arrayType& x, int maxfev) {
        // If you dont have the derivatives in Functor class:
        //      NumericalDiff<LeastSquaresFunctor> numDiff(functor);
        //      LevenbergMarquardt<NumericalDiff<LeastSquaresFunctor>> lm(numDiff);
        // auto x = s.getPeaks<Eigen::VectorXd>();
        // s.setPeaks(x);
        LeastSquaresFunctor functor(s);
        Eigen::LevenbergMarquardt<LeastSquaresFunctor> lm(functor);
        lm.parameters.maxfev=maxfev;
        Eigen::VectorXd xx(x.size());
        double errTest = s.computePeakError();
        for(int i=0; i< x.size(); i++) {
            xx[i] = x[i];
        }
        auto status = lm.minimize(xx);
        // do {
        //     std::cout << "Optimize parameters: " << xx << std::endl;
        //     status = lm.minimizeOneStep(xx);
        // } while(status == Eigen::LevenbergMarquardtSpace::Running);
        s.setPeaks(xx);

        double err = s.computePeakError();
        if(err == errTest) {
            fprintf(stderr, "Status: %d\n", status);
            // throw std::runtime_error("yeah");
            err = 1e33;
        }
        // for(int i=0;i < xx.size()/3; i++) {
        //     if(xx[3*i+2] < 0) {
        //         err = 1e33;
        //         return Result{lm.nfev, err};
        //     }
        // }
        return Result{lm.nfev, err};
    }
};
