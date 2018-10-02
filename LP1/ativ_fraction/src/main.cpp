#include "../include/fraction.h"

int main(void) {
  Fraction x(3, 4);

  if (!x.isZero()) {
    std::cout << x << " Não é zero" << '\n';
  }

  return 0;
}
