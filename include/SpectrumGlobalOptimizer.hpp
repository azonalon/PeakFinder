#include <random>
#include <fstream>
#include "../include/SpectrumLocalOptimizer.hpp"
#include "../include/RandomNumbers.hpp"

#include <eoScalarFitness.h>
#include <eoVector.h>
#include <utils/eoRealVectorBounds.h>
#include <eoPop.h>
#include <utils/eoParser.h>
#include <utils/eoCheckPoint.h>
#include <eoEvalContinue.h>
#include <es/eoRealInitBounded.h>

#include <eoGenContinue.h>
#include <eoFitContinue.h>
#include <utils/eoStdoutMonitor.h>
#include <utils/eoStat.h>
#include <utils/eoTimedMonitor.h>

#include <eoEasyEA.h>

#include <es/eoEsMutate.h>
#include <es/eoEsMutationInit.h>
#include <es/eoNormalMutation.h>
#include <eoG3Replacement.h>
#include <eoReduceMerge.h>
#include <eoGeneralBreeder.h>


typedef eoVector<eoMinimizingFitness, double> Candidate;

template<class EOT> class Mutate:
  public eoNormalMutation<EOT>, public eoUpdatable
{
public:
    using eoNormalMutation< EOT >::Sigma;
    typedef typename EOT::Fitness Fitness;

  Mutate(eoEvalFunc<EOT> & _eval, double& _sigmaInit, eoRealVectorBounds& _bounds,
                     unsigned _windowSize = 2, double _updateFactor=0.83,
                     double _threshold=0.2):
    eoNormalMutation<EOT>(_bounds, _sigmaInit), eval(_eval),
    // eoNormalMutation<EOT>(_sigmaInit), eval(_eval),
    threshold(_threshold), updateFactor(_updateFactor),
    nbMut(_windowSize, 0), nbSuccess(_windowSize, 0), genIndex(0)
  {
    // minimal check
  }

  virtual std::string className() const { return "eoOneFifthMutation"; }

  bool operator()(EOT & _eo)
    {
      if (_eo.invalid())           // due to some crossover???
        eval(_eo);
      Fitness oldFitness = _eo.fitness(); // save old fitness

      // call standard operator - then count the successes
      if (eoNormalMutation<EOT>::operator()(_eo)) // _eo has been modified
        {
          _eo.invalidate();        // don't forget!!!
          nbMut[genIndex]++;
          eval(_eo);               // compute fitness of offspring

          // if (double(_eo.fitness()) < 0.99*double(oldFitness))
          if (_eo.fitness() > oldFitness)
            nbSuccess[genIndex]++;          // update counter
        }
      return false;                // because eval has reset the validity flag
    }

  void update()
  {
    unsigned totalMut = 0;
    unsigned totalSuccess = 0;
    // compute the average stats over the time window
    for ( unsigned i=0; i<nbMut.size(); i++)
      {
        totalMut += nbMut[i];
        totalSuccess += nbSuccess[i];
      }

    // update sigma accordingly
    double prop = double(totalSuccess) / totalMut;
    if (prop > threshold) {
        Sigma() /= updateFactor;     // increase sigma
        std::cout << "success rate: " << prop << " increase sigma: " << Sigma() << std::endl;
    }
    else
    {
        Sigma() *= updateFactor;           // decrease sigma
        std::cout << "success rate: " << prop << " decrease sigma: " << Sigma() << std::endl;
    }
    genIndex = (genIndex+1) % nbMut.size() ;
    nbMut[genIndex] = nbSuccess[genIndex] = 0;

  }
private:
  eoEvalFunc<EOT> & eval;
  double threshold;               // 1/5 !
  double updateFactor;            // the multiplicative factor
  std::vector<unsigned> nbMut;    // total number of mutations per gen
  std::vector<unsigned> nbSuccess;// number of successful mutations per gen
  unsigned genIndex;              // current index in std::vectors (circular)
};


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

template <class EOT>
class Replacement : public eoReplacement<EOT>
{
    public:
        void operator()(eoPop<EOT>& _parents, eoPop<EOT>& _offspring)
        {
          if (_parents.size() != _offspring.size() || (_offspring.size()%2 != 0))
            throw std::logic_error("Reduce Merge: Sizes invalid, should be equal and multiple of two!\n");
            merge(_parents, _offspring); // parents untouched, result in offspring
            reduce(_offspring, _parents.size());
            _parents.swap(_offspring);
        }
    private :
        eoPlus<EOT> merge;
        eoTruncate<EOT> reduce;
};

class SpectrumGlobalOptimizer {
    // typedef eoReal<eoMinimizingFitness> Candidate;
    eoValueParam<int> evals;
    int mu=10;
    class Breed: public eoBreed<Candidate> {
        Candidate recombine(const Candidate& parent1, const Candidate& parent2) {
            int nPeaks = parent1.size()/3;
            Candidate c(parent1.size());
            for(int i=0; i<parent1.size()/3; i++) {
                if(rng.rand() % 2) {
                    c[3*i + 0] = parent1[3*i + 0];
                    c[3*i + 1] = parent1[3*i + 1];
                    c[3*i + 2] = parent1[3*i + 2];
                } else {
                    c[3*i + 0] = parent2[3*i + 0];
                    c[3*i + 1] = parent2[3*i + 1];
                    c[3*i + 2] = parent2[3*i + 2];
                }
            }
            if(rng.rand() % 2) {
                c[parent1.size()-1] = parent1[parent1.size()-1];
            } else {
                c[parent1.size()-1] = parent2[parent1.size()-1];
            }
            return c;
        }

        double sigma;
        Mutate<Candidate> mutate;
        eoRealVectorBounds bounds;
        double offspringRatio=2;
        eoEvalFunc<Candidate>& eval;

        std::string className() {return "Spectrum Parameter Breeder";}
        void operator()(const eoPop<Candidate>& parents, eoPop<Candidate>& offspring) {
            // std::cout << "breeder called " << parents.size() << " " << offspring.size() << std::endl;
            std::vector<const Candidate*> parentsPtr(parents.size());
            std::transform(parents.begin(), parents.end(), parentsPtr.begin(),
                            [](auto& x){return &x;});
            for(int j=0; j < offspringRatio; j++) {
                std::random_shuffle(parentsPtr.begin(), parentsPtr.end(),
                    [](uint32_t n) -> uint32_t {return rng.random(n);});

                for(int i=0; i<parents.size()/2; i++) {
                    auto p1=parentsPtr[2*i + 0], p2=parentsPtr[2*i + 1];
                    Candidate child = recombine(*p1, *p2);
                    // std::cout << "c value: " << child[child.size()-1] << std::endl;
                    eval(child);
                    if(child.fitness() > p2->fitness() && child.fitness() > p1 ->fitness()) {
                        printf("Recombination produced something! (%g , %g) -> %g \n",
                            (double)p1->fitness(), (double)p2->fitness(), (double)child.fitness());
                    } else {
                        mutate(child);
                    }
                    std::cout << "New candidate " << child.fitness() << std::endl;
                    offspring.push_back(child);
                }
            }
            mutate.update();
        }
    public:
        Breed(eoEvalFunc<Candidate>& eval, eoRealVectorBounds& bounds,
                std::vector<double> initialStdevs, int _offspringRatio, int _oneFifthWindow):
            sigma(initialStdevs[0]), mutate(eval, sigma, bounds, _oneFifthWindow, 0.83),
            bounds(bounds), offspringRatio(2*_offspringRatio), eval(eval) {
        }
    };


    class EvaluationFunctor: public eoEvalFunc<Candidate> {
    public:
        int nLocalIterations = 50;
        SpectrumLocalOptimizer& s;
        eoValueParam<int>& evals;
        EvaluationFunctor(SpectrumLocalOptimizer& s,
                          eoValueParam<int>& evals): s(s), evals(evals) {
        }
        void operator()(Candidate& c) {
            if(c.invalid()) {
                auto r = s.optimize(c, nLocalIterations);
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

        int nParameters = s.parameterCount();
        std::vector<double> initialParameters(nParameters);
        std::vector<double> lowerBounds(nParameters);
        std::vector<double> upperBounds(nParameters);
        std::vector<double> initialStdevs(nParameters);

        for(int i=0; i< nParameters/3; i++) {
            // dont go below the resoltion
            // minStdevs[3*i + 0] = abs(f1-f2)/s.frequencies.size();
            // minStdevs[3*i + 1] = abs(f1-f2)/s.frequencies.size();
            // minStdevs[3*i + 2] = 0;
            // cover the whole area
            lowerBounds[3*i + 0] = std::min(f1, f2) - abs(f1-f2);
            lowerBounds[3*i + 1] = abs(f1-f2)/s.frequencies.size();
            lowerBounds[3*i + 2] = 0.0;
            upperBounds[3*i + 0] = std::max(f1, f2) + abs(f1-f2);
            upperBounds[3*i + 1] = abs(f1-f2)*2;
            upperBounds[3*i + 2] = max;
            initialStdevs[3*i + 0] = abs(f1-f2)/2.0;
            initialStdevs[3*i + 1] = 1.0/abs(f1-f2)/2;
            initialStdevs[3*i + 2] = abs(max-min)/2;
            initialParameters[3*i + 0] = (f1+f2)/2.0;
            initialParameters[3*i + 1] = 1.0/abs(f2-f1)/2.0;
            initialParameters[3*i + 2] = (max+min)/2;
        }
        initialParameters[nParameters-1] = min;
        lowerBounds[nParameters-1] = min;
        upperBounds[nParameters-1] = max;
        initialParameters[nParameters-1] = min;
        // minStdevs[nParameters] = 0;
        initialStdevs[nParameters-1] = max/2;

        eoRealVectorBounds bounds(lowerBounds, upperBounds);
        eoRealInitBounded<Candidate> initPopulation(bounds);
        eoPop<Candidate> pop(mu, initPopulation);
        std::cout << "Initial population: " << pop << std::endl;
        EvaluationFunctor eval(opt, evals);

        for (unsigned i = 0; i < pop.size(); ++i) {
        	eval(pop[i]);
        }

        Breed breed(eval, bounds, initialStdevs, 1, 2);
        // eoG3Replacement<Candidate> comma(pop.size());
        Replacement<Candidate> comma;
        eoGenContinue<Candidate> gen(maxGen);
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
