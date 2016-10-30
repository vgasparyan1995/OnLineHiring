#include <iostream>

#include "RandomPermutator.h"
#include "interview.h"

typedef std::vector<int> Result;

Result get_hiring_result(const int number_of_trials, const int number_of_interviewees)
{
    Result res(number_of_interviewees, 0);
    for (auto i = 0; i < number_of_trials; ++i) {
        const auto random_interviewee_permutation = RandomPermutator::get_one(number_of_interviewees);
        const auto chosen_one = interview(random_interviewee_permutation);
        ++res[chosen_one];
    }
    return res;
}

void print_result(const Result& res, const int number_of_trials)
{
    for (int i = 0; i < res.size(); ++i) {
        std::cout << i << '\t' << res[i] << '\t' << double(res[i]) * 100.0 / double(number_of_trials) << "%\n";
    }
}

int main()
{
    auto number_of_trials = 0;
    auto number_of_interviewees = 0;
    std::cout << "Insert the number of trials: ";
    std::cin >> number_of_trials;
    std::cout << "Insert the number of interviewees: ";
    std::cin >> number_of_interviewees;

    const auto result = get_hiring_result(number_of_trials, number_of_interviewees);
    print_result(result, number_of_trials);
}
