#include "rng.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  unsigned int die[] = {4, 6, 8, 10, 12, 20, 100};
  for (unsigned int size : die) {
    std::cout << "1d" << size << ": " << roll_dN(size) << std::endl;
  }

  for (unsigned int size : die) {
    auto rolls = roll_xdN(size, size);
    std::cout << size << "d" << size << ": { ";
    for (unsigned roll : rolls) {
      std::cout << roll << " ";
    }
    std::cout << "}" << std::endl;
  }
  return 0;
}
