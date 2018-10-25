#include <iostream>
using namespace std;
#include "sapo.h"

int main() {
  srand(time(NULL));
  Sapo::corrida = (rand() % 90) + 10;
  Sapo a(1);
  Sapo b(2);
  Sapo c(3);

  //Corrida de sapos
  bool terminou = false;
  while(terminou == false){
    if (a.pular() >= Sapo::corrida) {
      cout << "Sapo " << a.getID() << " eh o ganhador" << endl;
      cout << "Distancia percorrida: " << a.getDistancia() <<'\n';
      cout << "Pulos dados: " << a.getQnt_pulo() << endl;
      terminou = true;}
    else if (b.pular() >= Sapo::corrida) {
      cout << "Sapo " << b.getID() << " eh o ganhador" << endl;
      cout << "Distancia percorrida: " << b.getDistancia() <<'\n';
      cout << "Pulos dados: " << b.getQnt_pulo() << endl;
      terminou = true;}
    else if (c.pular() >= Sapo::corrida) {
      cout << "Sapo " << c.getID() << " eh o ganhador" << endl;
      cout << "Distancia percorrida: " << c.getDistancia() <<'\n';
      cout << "Pulos dados: " << c.getQnt_pulo() << endl;
      terminou = true;}
    }
  return 0;
}
