#include <iostream>

using namespace std;

int main() {

int x;
int cont_1 = 0, cont_2 = 0, cont_3 = 0, cont_4 = 0;

cout << " Entre com valores inteiros ( Ctrl + d p / encerrar ): " << endl ;

while ( cin >> x ) {

  if (x >= 0 && x < 25)
    cont_1++;
  else if (x <= 50)
    cont_2++;
  else if (x <= 75)
    cont_3++;
  else if (x <=100)
    cont_4++;

}

std::cout << "[0, 25) = " <<  cont_1 << endl;
std::cout << "[25, 50) = " <<  cont_2 << endl;
std::cout << "[50, 75) = " <<  cont_3 << endl;
std::cout << "[75, 100] = " <<  cont_4 << endl;

  return 0;
}
