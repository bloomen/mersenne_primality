#pragma once
#include <gmpxx.h>


inline
void modulo_mersenne(mpz_class& value, const mpz_class& mersenne, const int exponent) noexcept
{
    while (mpz_sizeinbase(value.get_mpz_t(), 2) > static_cast<const std::size_t>(exponent))
    {
        value = (value & mersenne) + (value >> exponent);
    }
    if (value == mersenne)
    {
        value = 0;
    }
}
