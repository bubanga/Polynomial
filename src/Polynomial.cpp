#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial(int degree) {
    this->degree = degree;
    this->coefficients = new double[degree+1];
    this->generateCoefficients();
}

Polynomial::Polynomial(const Polynomial &Polynomial) {}

Polynomial &Polynomial::operator=(const Polynomial &Polynomial) {
    return *this;
}

void Polynomial::print() {
    for (int i = this->degree; i >= 0; --i) {
        if (this->coefficients[i] == 0)
            continue;

        if (this->coefficients[i] > 0 && i != this->degree) {
            printf("+%f", this->coefficients[i]);
        } else {
            printf("%f", this->coefficients[i]);
        }

        if (i > 0) {
            printf("x");
        }

        if (i > 1) {
            printf("^%d", i);
        }
    }

    std::cout << std::endl;
}

/*
 * Nie rozumiem do czego mialoby to sluzyc
 */
Polynomial Polynomial::derivative() {
    return *this; //to ustawilem zeby bylo ale nie wiem co innego tu powinno sie robic
}

void Polynomial::generateCoefficients() {
    for (int i = 0; i <= this->degree; ++i) {
        this->coefficients[i] = this->min + (rand() % (this->max - this->min + 1));
    }
}

int Polynomial::getDegree() const {
    return this->degree;
}

/*
 * To moja metoda nie wymagana w zadaniu
 */
double Polynomial::getCoefficient(int _degree) const {
    if (this->degree < _degree || _degree < 0)
        return 0;

    return this->coefficients[_degree];
}

/*
 * To moja metoda nie wymagana w zadaniu
 */
void Polynomial::setCoefficient(int _degree, double coefficient) const {
    if (this->degree < _degree || _degree < 0)
        return;

    this->coefficients[_degree] = coefficient;
}


Polynomial::~Polynomial() = default;

/*
 * To jest moja wizja ale powinienem pewnie jakoś wykorzystac metode derivative() i nawet nie wiem jak i gdzie...
 */
Polynomial add(const Polynomial& p1, const Polynomial& p2)
{
    int maxDegree = (p1.getDegree() > p2.getDegree())? p1.getDegree() : p2.getDegree();
    Polynomial polynomial = Polynomial(maxDegree);
    for (int i = 0; i <= maxDegree; i++) {
        polynomial.setCoefficient(i, p1.getCoefficient(i) + p2.getCoefficient(i));
    }

    return polynomial;
}

Polynomial multiply(const Polynomial& p1, const Polynomial& p2)
{

}