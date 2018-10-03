#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

class Fraction{
  private:
    int numerator;
    int denominator;
    int number;
    int mdc(int, int);
    int mmc(int, int);
  public:
    //Constructor
    Fraction();
    Fraction(int, int);
    //~Fraction();
    //Getters, Setters
    int getNumerator();
    void setNumerator(int);
    int getDenominator();
    void setDenominator(int);
    //Functions
    bool isZero(void) const;
    bool isProper(void) const;
    bool isReduced(void);
    void reduce(void);
    void make_proper(void);
    //Overload
    friend std::ostream & operator<<(std::ostream & os, const Fraction f);
    Fraction operator+(Fraction &sum);
    Fraction operator-(Fraction &sub);
    Fraction operator*(Fraction &mult);
    Fraction operator/(Fraction &mdiv);
};




#endif
