#include <iostream>
#include "primetest.h"
#include "karatsuba.h"

int main(int, char** argv) {
  const auto exponent = std::atoi(argv[1]);
  std::cout << "p="  << exponent << " -> " << std::boolalpha << is_mersenne_prime(exponent) << std::endl;

//  mpz_class value = exponent;
//  auto result = karatsuba_square(value);
//  std::cout<< result <<std::endl;

  return 0;
}
