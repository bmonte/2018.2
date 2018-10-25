#include <iostream>
#define TAM 6

using namespace std;

int main() {

int v[TAM], temp, j;

  for (size_t i = 0; i < TAM; i++) {
    cin >> v[i];
  }

  for (size_t i = 0; i < TAM; i+=2) {
    j = i + 1;
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
