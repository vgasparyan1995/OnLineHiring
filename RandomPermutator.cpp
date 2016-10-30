#include "RandomPermutator.h"

#include <algorithm>

#define pow_3(n) ((n)*(n)*(n))

std::random_device RandomPermutator::s_rd;
std::mt19937 RandomPermutator::s_generator(s_rd());

int RandomPermutator::uniform_random(const int from, const int to)
{
    std::uniform_int_distribution<> distributor(from, to);
    return distributor(s_generator);
}

std::vector<int> RandomPermutator::get_one(const int size)
{
    std::vector<int> permutation;
    RandomPermutator::Transposition transposition;
    for (int i = 0; i < size; ++i) {
        transposition.push_back(
                std::make_pair(i, uniform_random(1, pow_3(size))));
    }
    std::sort(transposition.begin(), transposition.end(),
            [] (const TranspositionUnit& lhs,
                const TranspositionUnit& rhs) -> bool {
                    return lhs.second < rhs.second;
            });
    for (const auto& unit : transposition) {
        permutation.push_back(unit.first);
    }
    return permutation;
}
