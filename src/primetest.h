#pragma once
#include <cassert>
#include "number.h"


inline
bool is_mersenne_prime(const int exponent) noexcept {
  assert(exponent > 2);
  const auto mersenne = number{exponent + 1} - 1;
  auto residue = number{3};
  for (int i = 0; i < exponent - 2; ++i) {
    residue.square();
    residue -= 2;
    residue.mod_mersenne(mersenne, exponent);
  }
  return residue == 0;
}
