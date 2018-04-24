#include <fstream>
#include "../include/SpectrumLocalOptimizer.hpp"
// #include <algorithm>

int main() {
    std::ofstream of("Testing/random.dat");
    std::default_random_engine generator;
    std::normal_distribution<double> d(10, 10);
    generator.seed(42);
    Spectrum s(10, 20, 0.1, std::vector<Peak> {Peak(15, 2, 1), Peak(13, 1, 3)},
                0.05, generator);

    auto optimalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    const int N = 100;
    std::cout << "Optimal Parameters: \n" << optimalParameters.transpose() << std::endl;

    double bestError = 1e9;
    SpectrumLocalOptimizer::Result r;
    for(int i=0; i < N; i++) {
        std::cout << "\nRun " << i << " " << std::endl;
        Eigen::VectorXd initialParameters(s.parameterCount());
        for(int i=0; i<s.parameterCount(); i++) {
            initialParameters[i] = abs(d(generator));
        }
        std::cout << "Initial Parameters: \n" << initialParameters.transpose()
                  << std::endl;
        auto opt = SpectrumLocalOptimizer(s);
        r = opt.optimize(initialParameters, 100);
        std::cout << "Iterations: " << r.nfev << " Error: " << r.chiSquareError << std::endl;
        bestError = std::min(bestError, r.chiSquareError);
    }

    dumpSpectrum(s, &of);
    auto finalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    std::cout << "Final Parameters: \n" << finalParameters.transpose() << std::endl;
    std::cout << "Parameter Deviation: \n" << (finalParameters - optimalParameters).transpose() << std::endl;
    std::cout << "Number of iterations: \n" << r.nfev << std::endl;
    std::cout << "Best Error: " << bestError << std::endl;
    of.close();
}
