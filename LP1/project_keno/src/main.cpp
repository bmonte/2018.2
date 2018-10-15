#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include "../include/kenoBet.h"

int main(int argc, char *argv[]) {

  KenoBet x;

/*  srand(time()); //Seed

  set_of_numbers_type random;

  auto cont;
  while (cont < 20) {
    auto number = (rand() %80) + 1;

    if (!std::binary_search (random.begin(), random.end(), number)){
      random.push_back(number);
      cont++;
    }
    std::sort (random.begin(), random.end());
  }*/

set_of_numbers_type random;

auto cont(0);
while (cont < 20) {
  // Seed with a real random value, if available
  std::random_device r;

  // Choose a random mean between 1 and 6
  std::default_random_engine e1(r());
  std::uniform_int_distribution<int> uniform_dist(1, 80);
  int number = uniform_dist(e1);

  if (!std::binary_search (random.begin(), random.end(), number)){
    random.push_back(number);
    cont++;
  }
  std::sort (random.begin(), random.end());
}


  for (size_t j = 0; j < 20; j++) {
    std::cout << random[j] << '\n';
  }

  return 0;
}
