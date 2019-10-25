#include <iostream>
#include "primetest.h"

int main(int, char** argv)
{
    const auto exponent = static_cast<std::size_t>(std::atoi(argv[1]));
    std::cout << "p="  << exponent << " -> " << std::boolalpha << is_mersenne_prime(exponent) << std::endl;
    return 0;
}
