#include <iostream>
#include "src/Polynomial.h"

/**
 * Funkcja main() tworzy dwa obiekty typu Polynomial, p1 i p2, a następnie drukuje współczynniki wielomianów:
 *  p1(x)
 *  p2(x)
 *  p1'(x)
 *  p2'(x)
 *  p1(x) + p2(x)
 *  p1(x) * p2(x)
 * @return
 */
int main() {
    srand(time(nullptr));
    Polynomial p1 = Polynomial(4);
    Polynomial p2 = Polynomial(4);
    p1.print();
    p2.print();
    //add(p1, p2).print();
    return 0;
}