#include <iostream>
#define TAM 20

using namespace std;

int main() {

int v[TAM], temp, j;

  for (size_t i = 0; i < TAM; i++) {
    cin >> v[i];
  }

  for (size_t i = 0; i < TAM/2; i++) {
    j = (TAM - i - 1);
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
  }

  cout << "Vetor trocado: [ ";
    for (size_t i = 0; i < TAM; i++) {
      cout << v[i] << " ";
    }
  cout << "]" << endl;
  return 0;
}
