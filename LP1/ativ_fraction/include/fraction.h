#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction{
  private:
    int numerator;
    int denominator;
    //int mdc(int, int);
  public:
    Fraction();
    Fraction(int, int);
    int getNumerator();
    void setNumerator(int);
    int getDenominator();
    void setDenominator(int);
    bool isZero(void) const;
    /*bool isProper();
    int reduce();
    int make_proper();
    ~Fraction();*/
    friend std::ostream & operator<<(std::ostream & os, const Fraction f);
};




#endif
