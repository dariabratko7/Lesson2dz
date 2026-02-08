#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int den) {
    numerator = num;
    denominator = (den != 0) ? den : 1;
}

void Fraction::setNumerator(int num) {
    numerator = num;
}

void Fraction::setDenominator(int den) {
    if (den != 0)
        denominator = den;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::input() {
    cout << "Введіть чисельник: ";
    cin >> numerator;

    do {
        cout << "Введіть знаменник (не 0): ";
        cin >> denominator;
    } while (denominator == 0);
}

void Fraction::print() const {
    cout << numerator << "/" << denominator << endl;
}

Fraction Fraction::add(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
}

Fraction Fraction::subtract(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    );
}

Fraction Fraction::multiply(const Fraction& other) const {
    return Fraction(
        numerator * other.numerator,
        denominator * other.denominator
    );
}

Fraction Fraction::divide(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator,
        denominator * other.numerator
    );
}