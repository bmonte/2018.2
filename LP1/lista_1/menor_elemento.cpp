#include <iostream>
#define TAM 20

using namespace std;

int main() {

        int v[TAM], menor, posicao;

        for (size_t i = 0; i < TAM; i++) {
                cin >> v[i];
        }

        menor = v[0];
        posicao = 0;

        std::cout << "Vetor: [ ";

        for (size_t i = 0; i < TAM; i++) {
                cout << v[i] << " ";
                if(v[i] < menor)
                {
                        menor = v[i];
                        posicao = i + 1;
                }
        }

        cout << "];" << endl;
        std::cout << "Menor numero é " << menor << " na posição " << posicao << endl;

        return 0;
}
