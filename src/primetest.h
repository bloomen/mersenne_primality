#pragma once
#include <cassert>
#include "number.h"


inline
bool is_mersenne_prime(const std::size_t exponent) noexcept
{
    assert(exponent > 2);
    number mersenne{exponent};
    mersenne -= 1;
    number residue{2};
    for (std::size_t i = 0; i < exponent - 2; ++i)
    {
        residue.square();
        residue -= 2;
        residue.mod_mersenne(mersenne, exponent);
    }
    return residue == 0;
}
