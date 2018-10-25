#include <iostream>

int main() {
int valor, cont;

for (size_t i = 0; i < 5; i++) {
  std::cout << "Insira o " << i + 1 << " valor: " << '\n';
  std::cin >> valor;
  if (valor < 0) {
    cont++;
  }
}

std::cout << cont << " numeros negativos" << '\n';

  return 0;
}
