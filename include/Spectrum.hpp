#pragma once
#include <Eigen/Core>
#include <vector>
#include <utils/eoRNG.h>
#include <cassert>
#include <random>
#include <fstream>

enum PeakType {GAUSSIAN};

class Peak {
    PeakType type=GAUSSIAN;
    double center=0;
    double height=0;
    double invWidth=1;
public:
    double getCenter() {
        return center;
    }
    double getInvWidth() {
        return invWidth;
    }
    double getHeight() {
        return height;
    }
    void setHeight(double h) {
        this->height = h;
    }
    void setInvWidth(double w) {
        invWidth = w;
    }
    void setCenter(double c) {
        this->center = c;
    }

    Peak(double center, double invWidth, double height) :
        center(center), height(height) {
        setInvWidth(invWidth);
    }
    inline double computeValueAt(double x) {
        if(type == GAUSSIAN) {
            return abs(height)*exp(-(x-center)*(x-center)*invWidth);
        } else {
            throw std::runtime_error("the given peak type is not defined");
        }
        return 0;
    }
    inline Eigen::ArrayXd computeSpectrum(Eigen::ArrayXd x) {
        if(type == GAUSSIAN) {
            auto xx = x-center;
            return abs(height)*Eigen::exp(-(xx*xx)*invWidth);
        } else {
            throw std::runtime_error("the given peak type is not defined");
        }
    }
    inline double signum(double x) {
        return x < 0? -1 : 1;
    }

    inline void computeJacobian(Eigen::ArrayXd frequencies,
                                Eigen::MatrixXd& jac, int offset) {
        if(type == GAUSSIAN) {
            for(int i=0; i < frequencies.size(); i++) {
                auto xx = frequencies[i]-center;
                double xs = xx*xx;
                double tmp1 = exp(-xs*invWidth);
                jac(i, offset+0) = height*tmp1* xx*2*(invWidth);
                jac(i, offset+1) = height*tmp1*(-xs);
                jac(i, offset+2) = tmp1 * signum(height);
                // signum here because there is an abs around height
            }
        } else {
            throw std::runtime_error("the given peak type is not defined");
        }
    }
};


class Spectrum {
public:
    Eigen::ArrayXd frequencies;
    Eigen::ArrayXd actualSpectrum;
    std::vector<Peak> peaks;
    double background=0;

    Eigen::ArrayXd computePeakSpectrum() {
        Eigen::ArrayXd s(frequencies.size());
        s = background;
        for(Peak p: peaks) {
            s += p.computeSpectrum(frequencies);
        }
        return s;
    }
    void computeJacobian(Eigen::MatrixXd& fjac) {
        for(int i=0; i<peaks.size(); i++) {
            peaks[i].computeJacobian(frequencies, fjac, 3*i);
        }
        for(int i=0; i<frequencies.size(); i++) {
            fjac(i, 3*peaks.size()) = 1;
        }
        // fjac.block(0, 3*peaks.size(), frequencies.size(), 1) =
        //     Eigen::VectorXd::Constant(frequencies.size(), 0);
    }

    double computePeakError() {
        Eigen::ArrayXd s = computePeakSpectrum() - actualSpectrum;
        double e = (s*s).sum();
        return e;
    }

    Spectrum(double f0, double f1, double background, std::vector<Peak> peaks,
             double noiseLevel, std::default_random_engine gen) {
        this->background = background;
        this->peaks = peaks;
        frequencies = Eigen::ArrayXd::LinSpaced(200, 10, 20);
        std::normal_distribution<double> d(0, noiseLevel);
        actualSpectrum = computePeakSpectrum();
        for(int i=0; i<actualSpectrum.size(); i++) {
            actualSpectrum[i] += d(gen);
        }
    }

    Spectrum(Eigen::ArrayXd frequencies, Eigen::ArrayXd spectrum) :
        frequencies(frequencies), actualSpectrum(spectrum) {}

    template<class _arrayType>
    _arrayType getPeaks() {
        _arrayType v(3*peaks.size() + 1);
        for(int i=0; i<peaks.size(); i++) {
            v[3*i+0] = (peaks[i].getCenter());
            v[3*i+1] = (peaks[i].getInvWidth());
            v[3*i+2] = (peaks[i].getHeight());
        }
        v[3*peaks.size()] = background;
        return v;
    }

    template<class _arrayType>
    _arrayType getPeaksAscending() {
        std::vector<Peak> p = peaks;
        std::sort(p.begin(), p.end(), [](Peak p1, Peak p2) -> bool {
            return p1.getCenter() > p2.getCenter();
        });
        _arrayType v(3*p.size() + 1);
        for(int i=0; i<p.size(); i++) {
            v[3*i+0] = (p[i].getCenter());
            v[3*i+1] = (p[i].getInvWidth());
            v[3*i+2] = (p[i].getHeight());
        }
        v[3*p.size()] = background;
        return v;
    }

    int parameterCount() {
        return 3*peaks.size() + 1;
    }

    template<class _arrayType>
    void setPeaks(_arrayType gen) {
        assert(gen.size() == parameterCount());
        for(int i=0; i<peaks.size(); i++) {
            this->peaks[i].setCenter(gen[3*i + 0]);
            this->peaks[i].setInvWidth(gen[3*i + 1]);
            this->peaks[i].setHeight(gen[3*i + 2]);
        }
        this->background = gen[peaks.size()*3];
    }
};

void dumpSpectrum(const Spectrum& s, std::ofstream* of) {
    for(int i=0; i < s.actualSpectrum.size(); i++) {
        *of << s.frequencies[i] << " " << s.actualSpectrum[i] << " "
            << s.background << " ";
        double y=s.background;
        for(Peak p: s.peaks) {
            double v = p.computeValueAt(s.frequencies[i]);
            y += v;
            *of << v + s.background << " ";
        }
        *of << y << std::endl;
    }
}
