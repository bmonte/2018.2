#include <iostream>

using namespace std;

int main() {

int x;

while (cin >> x) {

  int inicio, quantidade, fim, soma = 0;

  cout << "Insira dois pares: " << endl;
  cin >> inicio >> quantidade;

  fim = inicio + quantidade;

    for (inicio; inicio < fim; inicio++) {
      soma += inicio;
  }

  std::cout << "Soma = " << soma << '\n';

}
  return 0;
}
