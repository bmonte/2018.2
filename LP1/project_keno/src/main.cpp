#include <iostream>
#include <string>

#include "../include/kenoBet.h"
#include "../include/functions.h"

int main(int argc, char *argv[]) {
  std::string bet_file = argv[1];
  KenoBet x;
  my::file_reader(bet_file, x);

  std::cout << "Dinheiro total: " << x.get_wage() << '\n';
  std::cout << "Quantidade de rodadas a ser disputada: " << x.get_rounds() << '\n';

  auto premio = 0;
  float dinheiro_turno = x.get_wage()/x.get_rounds();
  std::cout << "--------------------------------------------------" << '\n';
  for (auto turnos = 0; turnos < x.get_rounds(); turnos++)
  {

    set_of_numbers_type rando = set_random();
    set_of_numbers_type player_pick = x.get_spots();
    set_of_numbers_type acertos = x.get_hits(rando);
    std::cout << "Numeros randomicos: ";
        for (unsigned x = 0; x < rando.size(); x++)
          std::cout << rando[x] << " ";
    std::cout << std::endl;
    std::cout << "Escolhas do jogador: ";
        for (unsigned y = 0; y < player_pick.size(); y++)
          std::cout << player_pick[y] << " ";
    std::cout << std::endl;
    std::cout << acertos.size() << " numero(s) certos: ";
        for (unsigned z = 0; z < acertos.size(); z++)
          std::cout << acertos[z] << " ";
    std::cout << std::endl;

    std::cout << "Pagamento: " << x.get_payout(dinheiro_turno, acertos) << std::endl;
    std::cout << "--------------------------------------------------" << '\n';
    premio += x.get_payout(dinheiro_turno, acertos);

  }
    std::cout << "Saldo final: " << premio << std::endl;
    x.set_wage(premio);

  return 0;
}
