#pragma once
#include <unordered_map>
#include <functional>

#include "Enum.hpp"

using namespace std;

struct pairHash : unary_function<const string&, size_t> {
    size_t operator()(argument_type arg) const {
        unsigned int h = 0;
        for (int i = 0; i < arg.length(); i++)
        {
            h = (h << 3) | (h >> 5);
            h += (unsigned int)arg[i];
        }
        return h;
    }
};


struct pairEquals : binary_function<const string, const string, bool> {
    result_type operator()(first_argument_type lhs, second_argument_type rhs) const
    {
        return lhs == rhs;
    }
};