#include <fstream>
#include "../include/SpectrumLocalOptimizer.hpp"

int main() {
    std::ofstream of("Testing/random.dat");
    std::default_random_engine generator;
    Spectrum s(10, 20, 0.1, std::vector<Peak> {Peak(15, 2, 1), Peak(13, 1, 3)},
                0.05, generator);
    auto optimalParameters = s.getPeaksAscending<Eigen::VectorXd>();
    s.peaks[0].setCenter(13);
    s.peaks[0].setInvWidth(1);
    s.peaks[0].setHeight(2.0);
    s.peaks[1].setCenter(14);
    s.peaks[1].setInvWidth(0.3);
    s.peaks[1].setHeight(0.8);
    s.background = 0;
    // auto initialParameters = s.getPeaksAscending<Eigen::VectorXd>();
    std::vector<double> initialParameters{2.62256, 9.16698, 18.3274, 10.6951, 26.5033, 8.71243, 11.2555};
    std::cout << "Optimal Parameters: \n" << optimalParameters.transpose() << std::endl;
    // std::cout << "Initial Parameters: \n" << initialParameters << std::endl;
    auto opt = SpectrumLocalOptimizer(s);
    auto lm = opt.optimize(initialParameters, 100);
    dumpSpectrum(s, &of);
    auto finalParameters = s.getPeaks<Eigen::VectorXd>();
    std::cout << "Final Parameters: \n" << finalParameters.transpose() << std::endl;
    std::cout << "Parameter Deviation: \n" << (finalParameters - optimalParameters).transpose() << std::endl;
    std::cout << "Number of iterations: \n" << lm.nfev << std::endl;
    std::cout << "Chi Square Error: " << s.computePeakError() << std::endl;
    of.close();
}
