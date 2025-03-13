#include "rng.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

unsigned int roll_dN(unsigned int N) {
  std::uniform_int_distribution<> dice(1, N);
  return dice(gen);
}

std::vector<unsigned> roll_xdN(unsigned int x, unsigned int N) {
  std::vector<unsigned> result;
  while (x > 0) {
    result.push_back(roll_dN(N));
    x--;
  }
  return result;
}
