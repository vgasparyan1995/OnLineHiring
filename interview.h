#pragma once

#include <cmath>

int interview(const std::vector<int>& interviewees)
{
    const int ignore_index = interviewees.size() / exp(1);
    int best_candidate = 0;
    int i = 0;
    for (; i < ignore_index; ++i) {
        if (interviewees[i] > best_candidate) {
            best_candidate = interviewees[i];
        }
    }
    for (; i < interviewees.size(); ++i) {
        if (interviewees[i] > best_candidate) {
            return interviewees[i];
        }
    }
    return interviewees.back();
}
