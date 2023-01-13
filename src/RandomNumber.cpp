#include "RandomNumber.h"
#include <random>

RandomNumber::RandomNumber() : generator(std::random_device{}()){}

int RandomNumber::getInt(int lowest, int highest) {
    return lowest + (generator() % (highest - lowest + 1));
}