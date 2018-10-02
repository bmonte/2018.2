#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <iomanip>

class Fraction{
  private:
    int numerator;
    int denominator;
    int number;
    int mdc(int, int);
  public:
    Fraction();
    Fraction(int, int);
    int getNumerator();
    void setNumerator(int);
    int getDenominator();
    void setDenominator(int);
    bool isZero(void) const;
    bool isProper(void) const;
    bool isReduced(void);
    void reduce(void);
    void make_proper(void);
    //~Fraction();
    friend std::ostream & operator<<(std::ostream & os, const Fraction f);
};




#endif
