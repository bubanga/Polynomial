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
    Polynomial p1 = Polynomial(2);
    Polynomial p2 = Polynomial(2);
    std::cout << "\nWielomian 1" << std::endl;
    p1.print();
    std::cout << "\nWielomian 2" << std::endl;
    p2.print();
    std::cout << "\nSuma wielomianu 1 i 2" << std::endl;
    add(p1, p2).print();
    std::cout << "\nIloczyn wielomianu 1 i 2" << std::endl;
    multiply(p1, p2).print();
    return 0;
}
