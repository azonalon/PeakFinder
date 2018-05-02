#include <Eigen/Core>
#include "SpectrumGlobalOptimizer.hpp"

/**
 * `Class for fitting spectra with predetermined models`
 * @return [description]
 */
class SpectralModelFitter {
    Eigen::ArrayXd frequencies;
    Eigen::ArrayXd values;
    double goal;
    unsigned maxfev;
    unsigned nMin;
    unsigned nMax;

public:
    enum Status {
        SUCCESS=0,
        FAILURE=1,
    };

    /**
     * Vector1D needs to support size() and bracket indexing operator[] method
     * @param x         The frequencies
     * @param y         Values for given frequencies
     * @param stdevGoal The fitting procedure will try to produce the simplest
     *                  fit which has standard deviation
     *                  sigma=sqrt(SSQDev)/sqrt(x.size())
     *                  below this goal
     * @param maxfev    how many fits should be evaluated in maximum
     */
    template<class Vector1D>
    SpectralModelFitter(Vector1D x, Vector1D y, double stdevGoal, unsigned maxfev,
                     unsigned nMin, unsigned nMax):
    frequencies(x.size()), values(y.size()),
    goal(stdevGoal), maxfev(maxfev), nMin(nMin), nMax(nMax) {
        for(int i=0; i< frequencies.size(); i++) {
            frequencies(i) = x[i];
            values(i)      = y[i];
        }
    }

    Spectrum findFit() {
        Spectrum s(frequencies, values);
        for(int n=nMin; n<=nMax; n++) {
            SpectrumGlobalOptimizer opt;
            std::cout << "Optimizing for N=" << n << " peaks" << std::endl;
            opt.optimize(s, goal, maxfev, n);
            if(s.computeStandardDeviation() <= goal) {
                return s;
            }
        }
        return s;
    }
};
