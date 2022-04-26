#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial(int degree) {
    this->degree = degree;
    this->coefficients = (double *) malloc(sizeof(double) * degree + 1);
    this->generateCoefficients();
}

Polynomial::Polynomial(const Polynomial &other) {
    this->degree = other.degree;
    this->coefficients = (double *) malloc(sizeof(double) * degree + 1);
    for(int i = 0; i <= other.degree; i++) {
        this->coefficients[i] = other.coefficients[i];
    }
}

Polynomial &Polynomial::operator=(const Polynomial &Polynomial) {
    return *this;
}

void Polynomial::print() {
    bool firstChar = false;
    for (int i = 0; i <= this->degree; i++) {
        if (this->coefficients[i] == 0)
            continue;

        if (this->coefficients[i] > 0 && firstChar) {
            printf(" + %f", this->coefficients[i]);
        } else {
            printf(" %f", this->coefficients[i]);
        }

        firstChar = true; //Sluzy do sprawdzania czy juz wystapil jakas liczba tak aby nie dodawac znaku + na poczatku wyrazenia

        if (i > 0) {
            printf("x");
        }

        if (i > 1) {
            printf("^%d", i);
        }
    }

    std::cout << std::endl;
}

Polynomial Polynomial::derivative() {
    return *this; //todo trzeba to jeszcze skonczyc
}

void Polynomial::generateCoefficients() {
    for (int i = 0; i <= this->degree; ++i) {
        this->coefficients[i] = this->min + (rand() % (this->max - this->min + 1));
    }
}

int Polynomial::getDegree() const {
    return this->degree;
}

double Polynomial::getCoefficient(int _degree) const {
    if (this->degree < _degree || _degree < 0)
        return 0;

    return this->coefficients[_degree];
}

void Polynomial::setCoefficient(int _degree, double coefficient) const {
    if (this->degree < _degree || _degree < 0)
        return;

    this->coefficients[_degree] = coefficient;
}


Polynomial::~Polynomial() {
    if(this->coefficients != nullptr) {
        free(this->coefficients);
    }
}

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
    int maxDegree = p1.getDegree() + p2.getDegree();
    Polynomial polynomial = Polynomial(maxDegree);
    for (int i = 0; i <= p1.getDegree(); i++) {
        for (int j = 0; j <= p2.getDegree(); j++) {
            polynomial.setCoefficient(i+j, p1.getCoefficient(i) * p2.getCoefficient(j));
        }
    }

    return polynomial;
}
