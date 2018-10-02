#include "../include/fraction.h"

int Fraction::mdc(int n, int d){
int r; //Resto
  while (d != 0){
      r = n % d;
      n = d;
      d = r;
  }
  return n;
}

Fraction::Fraction(){
  numerator = 1;
  denominator = 1;
  number = 0;
}

Fraction::Fraction(int n, int d){
  numerator = n;
  denominator = d;
  number = 0;
}

void Fraction::setNumerator(int n){
  numerator = n;
}

int  Fraction::getNumerator(){
  return numerator;
}

void Fraction::setDenominator(int d){
  denominator = d;
}

int Fraction::getDenominator(){
  return denominator;
}

bool Fraction::isZero(void) const{
  return numerator == 0 and denominator !=0;
}

bool Fraction::isProper(void) const{
  return numerator < denominator;
}

bool Fraction::isReduced(void){
  auto num = mdc(numerator, denominator);
  if (num != 1)
    return true;
  else
    return false;
}

void Fraction::reduce(void){
  auto divisor = mdc(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;
}

void Fraction::make_proper(void){
  number = numerator/denominator;
  numerator = numerator - (number * denominator);
}

std::ostream & operator<<(std::ostream & os, const Fraction f){
  if (f.number == 0)
      os << f.numerator << "/" << f.denominator;
  else
      os << f.number << " " << f.numerator << std::endl << std::setw(17) << f.denominator;

  return os;
}
