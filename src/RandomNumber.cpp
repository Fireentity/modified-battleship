#include "RandomNumber.h"
#include <random>

RandomNumber RandomNumber::instance{};

RandomNumber::RandomNumber() : generator_(std::random_device{}()){}

int RandomNumber::get_int(int lowest, int highest) {
    return lowest + (generator_() % (highest - lowest + 1));
}

RandomNumber &RandomNumber::get_instance() {
    return instance;
}
