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

Polynomial &Polynomial::operator=(const Polynomial &other) {
    return *this;
}

void Polynomial::print() {
    for (int i = 0; i <= this->degree; i++) {
        if (this->coefficients[i] == 0)
            continue;

        printf(" %f", this->coefficients[i]);

        if (i > 0) {
            printf("x");
        }

        if (i > 1) {
            printf("^%d", i);
        }

        if (this->degree >= i+1 && this->coefficients[i+1] > 0) {
            printf(" +");
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
    free(this->coefficients);
}

void Polynomial::resetPolynomial() {
    for (int i = 0; i <= this->getDegree(); i++)
        this->coefficients[i] = 0;
}

Polynomial add(const Polynomial& p1, const Polynomial& p2) {
    int maxDegree = (p1.getDegree() > p2.getDegree())? p1.getDegree() : p2.getDegree();
    Polynomial polynomial = Polynomial(maxDegree);
    for (int i = 0; i <= maxDegree; i++) {
        polynomial.setCoefficient(i, p1.getCoefficient(i) + p2.getCoefficient(i));
    }

    return polynomial;
}

Polynomial multiply(const Polynomial& p1, const Polynomial& p2) {
    int maxDegree = p1.getDegree() + p2.getDegree();

    Polynomial p3 = Polynomial(maxDegree);

    //Resetowanie wspolczynnikow, dlatego ze sa wylosowane losowo a algorytm musi dodawac do juz istniejacych
    //Przez mnozenie stopni wspolcznnikow zdarza sie ze przypisuje wartosc do wspolczynniku o n-stopniu wiecej niz jeden raz
    //dlatego musi pobrac juz istniajaca wartosc i dodac lub odjac wynik z mnozenia wspolcznnikow
    p3.resetPolynomial();

    for (int i = 0; i <= p1.getDegree(); i++) {
        if (p1.getCoefficient(i) == 0) //Pomijanie wspolczynnikow rownych 0
            continue;

        for (int j = 0; j <= p2.getDegree(); j++) {
            if (p2.getCoefficient(j) == 0) //Pomijanie wspolczynnikow rownych 0
                continue;

            p3.setCoefficient(i+j, p3.getCoefficient(i+j) + p1.getCoefficient(i) * p2.getCoefficient(j));
        }
    }

    return p3;
}
