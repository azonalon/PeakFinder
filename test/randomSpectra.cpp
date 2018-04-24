#include <Eigen/Core>
#include "../include/Spectrum.hpp"
#include <fstream>

int main() {
    std::ofstream of("Testing/random.dat");
    std::default_random_engine generator;
    Spectrum s(10, 20, 0.1, std::vector<Peak> {Peak(15, 2, 1)},
                0.05, generator);
    s.peaks[0].setWidth(3);
    s.peaks[0].setCenter(14);
    s.peaks[0].setHeight(0.8);
    dumpSpectrum(s, &of);
    std::cout << "Chi Square Error: " << s.computePeakError() << std::endl;
    of.close();
}
