#ifndef INCLUDE_RNG_H_
#define INCLUDE_RNG_H_

#include <vector>

unsigned int roll_dN(unsigned int N);
std::vector<unsigned> roll_xdN(unsigned int x, unsigned int N);
unsigned int sum_roll_xdN(unsigned X, unsigned N);

#endif // INCLUDE_RNG_H_
