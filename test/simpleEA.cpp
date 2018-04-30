#include <random>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "../include/SpectrumGlobalOptimizer.hpp"


int testRandomSpectrum(int N, std::default_random_engine g)
{
    std::normal_distribution<double> c(15, 2);
    std::normal_distribution<double> w(5, 2);
    std::normal_distribution<double> h(10, 5);
    std::normal_distribution<double> b(1, 0.5);

    double stdev = 0.05; // simulated measurement noise
    std::vector<Peak> peaks;
    for(int i=0; i<N; i++) {
        peaks.push_back( Peak{c(g), std::max(w(g), stdev), std::max(h(g), 0.0) } );
    }
    for(auto p: peaks) {
        printf("c=%g w=%g h=%g \n", p.getCenter(), p.getInvWidth(), p.getHeight());
    }


    Spectrum s(10, 20, b(g), peaks, stdev, g);

    std::cout << "Standard deviation error: " << stdev << std::endl;
    auto optimalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    SpectrumGlobalOptimizer opt;
    opt.optimize(s, stdev*1.1, 1000);
    auto finalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    double finalError = s.computeStandardDeviation();
    std::ofstream resultFile("Testing/fitresult.dat");
    std::ofstream errorFile("Testing/fiterror.dat");
    resultFile << finalParameters.transpose() << std::endl;
    errorFile  << s.getParameterErrorsAscending().matrix().transpose() << std::endl;
    // std::cout << "Final Error:        \n" << finalError        << std::endl;
    // std::cout << "Optimal Parameters: \n" << optimalParameters << std::endl;
    // std::cout << "Final Parameters:   \n" << finalParameters   << std::endl;
    // std::cout << "Deviation :         \n" << (finalParameters- optimalParameters).cwiseAbs() << std::endl;

    std::ofstream of("Testing/random.dat");
    dumpSpectrum(s, &of);
    of.close();
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
    if(argc > 2) {
        int N;
        std::istringstream(argv[2]) >> N;
        testRandomSpectrum(N, g);
    } else {
        testRandomSpectrum(3, g);
    }
}
