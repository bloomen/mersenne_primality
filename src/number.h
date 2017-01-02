#pragma once
#include <cstddef>
#include <gmpxx.h>
#include "modulo_mersenne.h"


class number {
public:

  explicit
  number(const int exponent) noexcept
  : num_(0)
  {
    if (exponent > 0) {
      const auto value = "1" + std::string(exponent - 1, '0');
      num_ = mpz_class(value, 2);
    }
  }

  bool operator==(const number& other) const noexcept {
    return num_ == other.num_;
  }

  bool operator==(const int value) const noexcept {
    return num_ == value;
  }

  number operator-(const int value) const noexcept {
    return number{num_ - value};
  }

  void operator-=(const int value) noexcept {
    num_ -= value;
  }

  void square() noexcept {
    num_ *= num_;
  }

  void mod_mersenne(const number& mersenne, const int exponent) noexcept {
    modulo_mersenne(num_, mersenne.num_, exponent);
  }

private:

  explicit
  number(mpz_class num) noexcept
  : num_(std::move(num))
  {}

  mpz_class num_;
};
