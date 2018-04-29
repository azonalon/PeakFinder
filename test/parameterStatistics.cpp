#include <random>
#include <fstream>
#include <algorithm>
#include "../include/SpectrumGlobalOptimizer.hpp"


int testRandomSpectrum(int N, std::default_random_engine g)
{
    std::normal_distribution<double> c(15, 2);
    std::normal_distribution<double> w(5, 2);
    std::normal_distribution<double> h(10, 5);
    std::normal_distribution<double> b(1, 0.5);

    std::vector<Peak> peaks;
    for(int i=0; i<N; i++) {
        peaks.push_back( Peak{c(g), std::max(w(g), 0.05), std::max(h(g), 0.0) } );
    }
    for(auto p: peaks) {
        printf("c=%g w=%g h=%g \n", p.getCenter(), p.getInvWidth(), p.getHeight());
    }


    Spectrum s(10, 20, b(g), peaks, 0.05, g);
    double initialError=s.computePeakError();
    std::cout << "Initial error: " << initialError << std::endl;
    auto optimalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    SpectrumGlobalOptimizer opt;
    opt.optimize(s, initialError, 100);
    auto finalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    double finalError = s.computePeakError();
    std::cout << "Final Error:        " << finalError << std::endl;
    std::cout << "Optimal Parameters: " << optimalParameters.transpose() << std::endl;
    std::cout << "Final Parameters:   " << finalParameters.transpose() << std::endl;
    std::cout << "Deviation :         " << (finalParameters.transpose() - optimalParameters.transpose()).cwiseAbs() << std::endl;
    std::ofstream of("Testing/random.dat");
    dumpSpectrum(s, &of);
    of.close();
    if(finalError > initialError) {
        return -1;
    }
    return 0;
}

int main(int argc, char** argv) {
    std::default_random_engine g;
    int seed;
    if(argc > 1) {
        std::istringstream(argv[1]) >> seed;
        std::cout << "Using seed " << seed << std::endl;
        g.seed(seed);
        rng.reseed(seed + 1);
    } else {
        g.seed(42);
        rng.reseed(46);
    }
    testRandomSpectrum(3, g);
}
