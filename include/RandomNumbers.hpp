#include <random>
class Random {
public:
    thread_local static std::mt19937 mersenneTwisterEngine;
};
