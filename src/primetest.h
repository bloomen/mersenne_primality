#pragma once
#include <cassert>
#include <chrono>
#include "number.h"

#define PROFILE 1

inline
bool is_mersenne_prime(const int exponent) noexcept {
  const auto start = std::chrono::high_resolution_clock::now();
#if PROFILE == 1
  std::chrono::microseconds square{};
  std::chrono::microseconds mod{};
#endif
  assert(exponent > 2);
  const auto mersenne = number{exponent} - 1;
  auto residue = number{2};
  for (int i = 0; i < exponent - 2; ++i) {
#if PROFILE == 1
    const auto s1 = std::chrono::high_resolution_clock::now();
#endif
    residue.square();
#if PROFILE == 1
    const auto e1 = std::chrono::high_resolution_clock::now();
    square += std::chrono::duration_cast<std::chrono::microseconds>(e1 - s1);
#endif
    residue -= 2;
#if PROFILE == 1
    const auto s2 = std::chrono::high_resolution_clock::now();
#endif
    residue.mod_mersenne(mersenne, exponent);
#if PROFILE == 1
    const auto e2 = std::chrono::high_resolution_clock::now();
    mod += std::chrono::duration_cast<std::chrono::microseconds>(e2 - s2);
#endif
  }
  const auto end = std::chrono::high_resolution_clock::now();
  const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
#if PROFILE == 1
  std::cout << "Square duration = " << square.count() / 1e6 << std::endl;
  std::cout << "Mod duration = " << mod.count() / 1e6 << std::endl;
#endif
  std::cout << "Total duration = " << duration.count() / 1e6 << std::endl;
  return residue == 0;
}
