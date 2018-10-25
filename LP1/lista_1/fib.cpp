#include <iostream>

using namespace std;

int main() {

int sequencia = 1, n1 = 1, n2 = 1, limite;

cout << "Digite o numero limite: ";
cin >> limite;

  while(sequencia < limite)
   {
    cout << sequencia << " ";
    sequencia = n1 + n2;
    n1 = n2;
    n2 = sequencia;
}

cout << endl;

  return 0;
}
