#pragma once
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:

    Fraction();
    Fraction(int num, int den);

    void setNumerator(int num);
    void setDenominator(int den);

    int getNumerator() const;
    int getDenominator() const;

    void input();
    void print() const;

    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
};
