#include "../include/CLI11.hpp"
#include "../include/SpectralModelFitter.hpp"
#include "../include/MatrixIO.hpp"

int main(int argc, char** argv) {
    std::ofstream ofResults("Testing/mainResults.dat");
    std::ofstream ofErrors("Testing/mainResultErrors.dat");
    auto m = readMatrix("Testing/qwSpectra.dat");
    auto f = m.col(0);
    for(int i=1; i< m.cols(); i++) {
        auto v = m.col(i);
        SpectralModelFitter fit(f, v, 0.15, 4000, 1, 1);
        auto s = fit.findFit();
        ofResults << s.getPeaksAscending<Eigen::VectorXd>().transpose() << std::endl;
        ofErrors  << s.getParameterErrorsAscending().transpose() << std::endl;
        std::ostringstream fname;
        fname << "Testing/fit_col_" << i << ".dat";
        std::cout << "Filename " << fname.str() << std::endl;
        std::ofstream graphs(fname.str());
        graphs << s.computeSpectraForEachPeak();
        graphs.close();
    }
    ofResults.close();
    ofErrors.close();
}
