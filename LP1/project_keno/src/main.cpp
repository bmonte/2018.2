#include <iostream>
#include <string>
#include "../include/kenoBet.h"
#include "../include/functions.h"

int main(int argc, char *argv[]) {
  std::string bet_file = argv[1];
  KenoBet x;
  my::file_reader(bet_file, x);

  std::cout << "wage: " << x.get_wage() << '\n';
    std::cout << "rounds: " << x.get_rounds() << '\n';

  set_of_numbers_type rando = set_random();
  set_of_numbers_type player_pick = x.get_spots();
  set_of_numbers_type acertos = x.get_hits(rando);

  for (unsigned x = 0; x < rando.size(); x++) {
    std::cout << rando[x] << " ";
  }
    std::cout << "Tam: " << rando.size() << '\n';

    for (unsigned y = 0; y < player_pick.size(); y++) {
      std::cout << player_pick[y] << " ";
    }
      std::cout << "Tam: " << player_pick.size() << '\n';


  for (unsigned a = 0; a < acertos.size(); a++) {
    std::cout << acertos[a] << '\n';
  }
  std::cout << "Tam: " << acertos.size() << '\n';

  return 0;
}
