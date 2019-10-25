#pragma once
#include <cstddef>
#include <gmpxx.h>
#include "modulo_mersenne.h"


class number
{
public:

    explicit number(const std::size_t exponent) noexcept
    {
        mpz_ui_pow_ui(num_.get_mpz_t(), 2, exponent);
    }

    bool operator==(const std::size_t value) const noexcept
    {
        return num_ == value;
    }

    void operator-=(const std::size_t value) noexcept
    {
        num_ -= value;
    }

    void square() noexcept
    {
        num_ *= num_;
    }

    void mod_mersenne(const number& mersenne, const std::size_t exponent) noexcept
    {
        modulo_mersenne(num_, mersenne.num_, exponent);
    }

private:
    mpz_class num_;
};
