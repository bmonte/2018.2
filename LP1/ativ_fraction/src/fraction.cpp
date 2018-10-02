#include "../include/fraction.h"

Fraction::Fraction(){
  numerator = 1;
  denominator = 1;
}

Fraction::Fraction(int n, int d){
  numerator = n;
  denominator = d;
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

std::ostream & operator<<(std::ostream & os, const Fraction f){
  os << f.numerator << "/" << f.denominator;
  return os;
}
