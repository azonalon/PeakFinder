#include "../include/RandomNumbers.hpp"
// auto thread_local Random::mersenneTwisterEngine = std::mt19937(std::random_device{}());
std:: mt19937 thread_local Random::mersenneTwisterEngine = std::mt19937(0);
