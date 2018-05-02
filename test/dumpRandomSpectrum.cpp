#include <Eigen/Core>
#include "../include/Spectrum.hpp"
#include <fstream>
#include <iostream>

#include <random>
#include <fstream>
#include <algorithm>

void dumpRandomSpectrum(int N, std::default_random_engine g, int n) {
    std::normal_distribution<double> c(15, 2);
    std::normal_distribution<double> w(5, 2);
    std::normal_distribution<double> h(10, 5);
    std::normal_distribution<double> b(1, 0.5);
    double stdev = 0.15; // simulated measurement noise

    std::ofstream of("Testing/randomSpectrum.dat");
    Eigen::MatrixXd m;
    for(int i=0; i<n; i++)
    {
        std::vector<Peak> peaks;
        for(int i=0; i<N; i++) {
            peaks.push_back( Peak{c(g), std::max(w(g), stdev), std::max(h(g), 0.0) } );
        }
        for(auto p: peaks) {
            printf("c=%g w=%g h=%g \n", p.getCenter(), p.getInvWidth(), p.getHeight());
        }
        Spectrum s(10, 20, b(g), peaks, stdev, g);
        if(i == 0) {
            m.resize(s.frequencies.size(), n);
            m.col(0) = s.frequencies;
            m.col(1) = s.actualSpectrum;
        } else {
            m.col(i) = s.actualSpectrum;
        }
    }
    // or:
    // m.col(0) = s.frequencies;
    // m.col(1) = s.actualSpectrum;
    // std::cout << m(1,2); dimensional error! that means rows are first index
    of << m;
    of.close();
}


int main(int argc, char** argv)
{
    std::default_random_engine g;
    int seed;
    if(argc > 1) {
        std::istringstream(argv[1]) >> seed;
        std::cout << "Using seed " << seed << std::endl;
        g.seed(seed);
        // rng.reseed(seed + 1);
    } else {
        g.seed(42);
        // rng.reseed(46);
    }
    if(argc > 3) {
        int N, n;
        std::istringstream(argv[2]) >> N;
        std::istringstream(argv[3]) >> n;
        dumpRandomSpectrum(N, g, n);
    } else {
        dumpRandomSpectrum(3, g, 1);
    }
}
