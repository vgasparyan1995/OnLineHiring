#pragma once

#include <vector>
#include <utility>
#include <random>

class RandomPermutator
{
private:
    typedef std::pair<int, int> TranspositionUnit;
    typedef std::vector<TranspositionUnit> Transposition;

    static std::random_device s_rd;
    static std::mt19937 s_generator;
    
    static int uniform_random(const int from, const int to);

public:
    static std::vector<int> get_one(const int size);
};
