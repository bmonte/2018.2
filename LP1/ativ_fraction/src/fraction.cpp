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

int Fraction::mmc(int n, int d){
  return (n*d)/mdc(n, d);
}

Fraction::Fraction(){
  numerator = 1;
  denominator = 1;
  number = 0;
}

Fraction::Fraction(int n, int d){
  numerator = n;
  denominator = d;
  if (numerator < 0 and denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }
  if(denominator == 0){
    throw std::invalid_argument("Denominator equals zero");
  }
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
  auto max = mdc(numerator, denominator);
  if (max == 1 or max == -1) return true;
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
  else if (f.number == 1)
      os << f.denominator << "/" << f.denominator;
  else
      os << f.number << " " << f.numerator << "/" << f.denominator;

  return os;
}

  Fraction Fraction::operator+(Fraction &sum){
      if (this->denominator == sum.getDenominator())
        numerator = this->numerator + sum.getNumerator();
      else{
        auto min = mmc(this->denominator, sum.getDenominator());
        numerator = ((min/this->denominator)*this->numerator) + ((min/sum.getDenominator()) * sum.getNumerator());
        denominator = min;
      }
    return Fraction(numerator, denominator);
  }

  Fraction Fraction::operator-(Fraction &sub){
    if (this->denominator == sub.getDenominator())
      numerator = this->numerator - sub.getNumerator();
    else{
      auto min = mmc(this->denominator, sub.getDenominator());
      numerator = ((min/this->denominator)*this->numerator) - ((min/sub.getDenominator()) * sub.getNumerator());
      denominator = min;
    }
  return Fraction(numerator, denominator);
  }

  Fraction Fraction::operator*(Fraction &mult){
    numerator = this->numerator * mult.getNumerator();
    denominator = this->denominator * mult.getDenominator();

    return Fraction(numerator, denominator);
  }
  Fraction Fraction::operator/(Fraction &divi){
    numerator = this->numerator * divi.getDenominator();
    denominator = this->denominator * divi.getNumerator();

    return Fraction(numerator, denominator);
  }
