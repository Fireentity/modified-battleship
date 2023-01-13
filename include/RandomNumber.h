#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <random>

class RandomNumber {
public:
    RandomNumber();
    int getInt(int lowest, int highest);

private:
    std::mt19937 generator;
};

#endif //RANDOMNUMBER_H