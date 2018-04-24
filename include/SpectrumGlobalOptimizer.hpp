#include <random>
#include <fstream>
#include "../include/SpectrumLocalOptimizer.hpp"

#include <eoScalarFitness.h>
#include <eoVector.h>
#include <eoPop.h>
#include <utils/eoParser.h>
#include <utils/eoCheckPoint.h>
#include <eoEvalContinue.h>

#include <eoGenContinue.h>
#include <eoFitContinue.h>
#include <utils/eoStdoutMonitor.h>
#include <utils/eoStat.h>
#include <utils/eoTimedMonitor.h>

#include <eoMergeReduce.h>
#include <eoEasyEA.h>

#include <es/CMAState.h>
#include <es/CMAParams.h>
#include <es/eoCMAInit.h>
#include <es/eoCMABreed.h>

template <class EOT>
class RememberBest: public eoStat<EOT, typename EOT::Fitness>
{
public:
    using eoStat<EOT, typename EOT::Fitness>::value;

    typedef typename EOT::Fitness Fitness;

    RememberBest(std::string _description = "Best ")
        : eoStat<EOT, Fitness>(Fitness(), _description)
         , log("Testing/candidateLog.dat")
        {}

    void operator()(const eoPop<EOT>& _pop) {
        doit(_pop, Fitness() ); // specializations for scalar and std::vector
    }

    virtual std::string className(void) const { return "eoBestFitnessStat"; }
    EOT bestSoFar() {
        return bestEOT;
    }
private:
    Fitness bestFitnessSoFar;
    EOT bestEOT;
    std::ofstream log;
    int i=0;
    // default
    template<class T>
    void doit(const eoPop<EOT>& _pop, T)
    { // find the largest elements
      EOT eot = _pop.best_element();
      value() = eot.fitness();
      log << eot << std::endl;
      if(value() > bestFitnessSoFar || i == 0) {
          bestFitnessSoFar = value();
          bestEOT = eot;
      }
      i++;
    }

};

class SpectrumGlobalOptimizer {
    // typedef eoReal<eoMinimizingFitness> Candidate;
    typedef eoVector<eoMinimizingFitness, double> Candidate;
    eoValueParam<int> evals;


    class EvaluationFunctor: public eoEvalFunc<Candidate> {
    public:
        SpectrumLocalOptimizer& s;
        eoValueParam<int>& evals;
        EvaluationFunctor(SpectrumLocalOptimizer& s,
                          eoValueParam<int>& evals): s(s), evals(evals) {
        }
        void operator()(Candidate& c) {
            if(c.invalid()) {
                auto r = s.optimize(c, 30);
                c.fitness(r.chiSquareError);
                // std::cout << "Candidate: " <<  c << std::endl;
                ++evals.value();
            }
        }
    };

public:
    SpectrumGlobalOptimizer():
        evals(0,"Function Evals","Number of Evaluations") {};

    void optimize(Spectrum& s, double tolerance, int maxGen) {

        double f1=s.frequencies[0], f2=s.frequencies[s.frequencies.size()-1];
        double fRange = abs(f1-f2);
        double min = s.actualSpectrum.minCoeff(), max = s.actualSpectrum.maxCoeff();

        SpectrumLocalOptimizer opt(s);

        // CONFIGURE CMA-ES SETTINGS
        char* tmp = new char[1] {'\0'};
        char** x = &tmp;
        eoParser parser(0, &tmp);
        delete[] tmp;
        eo::CMAParams params(parser, s.parameterCount());
        params.maxgen = maxGen;
        std::vector<double> initialCMAPoint(params.n, 0.0);
        for(int i=0; i<s.peaks.size(); i++) {
            // dont go below the resoltion
            params.minStdevs[3*i + 0] = abs(f1-f2)/s.frequencies.size();
            params.minStdevs[3*i + 1] = abs(f1-f2)/s.frequencies.size();
            params.minStdevs[3*i + 2] = 0;
            // cover the whole area
            params.initialStdevs[3*i + 0] = max/2;
            params.initialStdevs[3*i + 1] = max/2;
            params.initialStdevs[3*i + 2] = max/2;
            initialCMAPoint[3*i + 0] = (f1+f2)/2.0;
            initialCMAPoint[3*i + 1] = abs(f2-f1)/2.0;
            initialCMAPoint[3*i + 2] = max/2;
        }

        initialCMAPoint[s.peaks.size()] = min;
        params.minStdevs[s.peaks.size()] = 0;
        params.initialStdevs[s.peaks.size()] = max/2;

        // eoEsMutate<Candidate> mutator;
        // eoEsMutationInit initMutator;
        eo::CMAState state(params, initialCMAPoint);
        eoCMAInit<eoMinimizingFitness> init(state);
        eoPop<Candidate> pop(params.mu, init);
        EvaluationFunctor eval(opt, evals);
        eoCMABreed<eoMinimizingFitness> breed(state, params.lambda);

        for (unsigned i = 0; i < pop.size(); ++i) {
        	eval(pop[i]);
        }

        eoEPReplacement<Candidate> comma(10);
        eoGenContinue<Candidate> gen(params.maxgen);
        eoFitContinue<Candidate> fit(tolerance); // TODO find good terminating condition
        eoCheckPoint<Candidate> checkpoint(gen);
        checkpoint.add(fit);
        RememberBest<Candidate> stat;

        eoStdoutMonitor mon;
        mon.add(stat);
        mon.add(evals);

        eoTimedMonitor timed(1);// 1 seconds
        timed.add(mon); // wrap it

        checkpoint.add(timed);
        checkpoint.add(stat);

        eoEasyEA<Candidate> algo(
    	    checkpoint,
    	    eval,
    	    breed,
    	    comma);

        algo(pop);
        Candidate best = stat.bestSoFar();
        opt.optimize(best, 200);
        std::cout << best << std::endl;
        std::cout << "Best Fitness achieved = " << best.fitness() << std::endl;
        std::cout << "Function evaluations = " << evals.value() << std::endl;
    }
};
