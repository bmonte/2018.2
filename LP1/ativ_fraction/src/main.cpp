#include "../include/fraction.h"

int main(void) {
  Fraction x(1, 2);
  Fraction y(3, 4);
  std::cout << "Função: " << x / y << std::endl;


  if (!x.isZero())
    std::cout << " Denominador não é zero" << std::endl;
  else
    std::cout<< " Denominador é zero" << std::endl;
  if (x.isProper())
    std::cout << " É propria" << std::endl;
  else
    std::cout << " É impropria" << std::endl;
    if (!x.isReduced()){
      std::cout << " Pode reduzir" << std::endl;
      x.reduce();
      std::cout << " Fração reduzida: " << x <<'\n';
    }
  return 0;
}
