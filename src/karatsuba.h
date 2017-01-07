#pragma once
#include <gmpxx.h>


inline
mpz_class karatsuba_square(const mpz_class& x) {
  const auto size = mpz_sizeinbase(x.get_mpz_t(), 2);

  if (x < 10)
    return x * x;

  const auto N = (size / 2) + (size % 2);

  mpz_class mers;
  mpz_ui_pow_ui(mers.get_mpz_t(), 2, N);
  mers -= 1;

  const mpz_class a = x >> N;
  const mpz_class b = x & mers;
  const mpz_class sum_ab = a + b;

  const mpz_class z2 = a * a;
  const mpz_class z0 = b * b;
  const mpz_class z1 = sum_ab * sum_ab - z2 - z0;

  return (z2 << (2*N)) + (z1 << N) + z0;
}
