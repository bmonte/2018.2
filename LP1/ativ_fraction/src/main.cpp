#include "../include/fraction.h"

int main(void) {
  Fraction x(15, 4);

  if (!x.isZero())
    std::cout << x << " Denominador não é zero" << std::endl;
  else
    std::cout << x << " É zero" << std::endl;
  if (x.isProper())
    std::cout << x << " É propria" << std::endl;
  else
    std::cout << x << " É impropria" << std::endl;
    if (x.isReduced()){
      std::cout << x << " É reduzivel" << std::endl;
      x.reduce();
      std::cout << "Função reduzida: " << x <<'\n';
    }
    else
      std::cout << x << " Não é reduzivel" << std::endl;
  x.make_proper();
  std::cout << "Função mista: " << x <<'\n';
  return 0;
}
