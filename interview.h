#pragma once

#include <cmath>

int interview(const std::vector<int>& interviewees)
{
    auto reject_until = interviewees.begin() + interviewees.size() / exp(1);
    return *std::find_if(reject_until,
                         interviewees.end() - 1,
                         [best_so_far = *std::max_element(interviewees.begin(), reject_until)] (int candidate) {
                             return candidate > best_so_far;
                         });
}
