#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#define MAX_LEN 100 //Tamanho máximo do vetor inicial.

using namespace std;

int *filter(int *first, int *last);
bool isPositive(int i);

int main() {

        int v[MAX_LEN];
        short qntTest(0), TAM;
        string linha;

        getline(cin, linha);
        qntTest = stoi (linha);

        for (int i(0); i < qntTest; i++) {
                getline(cin, linha);
                TAM = stoi (linha);
                getline(cin, linha);
                istringstream iss(linha);
                for (int j(0); j < TAM; j++) {
                        iss >> v[j];
                }

                int* first = v;
                int* last = &v[TAM];

                last = filter(first, last);

                int cont(0);

                cout << "Vetor filtrado: [";
                for (int* p = first; p < last; p++){
                        cout << ' ' << *p;
                        cont++;
                      }
                cout << " ]" << " = " << cont << endl;
        }

        return 0;
}

bool isPositive(int i){
        return (i <= 0);
}

int *filter(int *first, int *last){
        last = remove_if (first, last, isPositive);
        return last;
}
