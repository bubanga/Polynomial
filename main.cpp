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
    std::cout << "\np1(x)" << std::endl;
    p1.print();
    std::cout << "\np2(x)" << std::endl;
    p2.print();
    std::cout << "\np1(x) + p2(x)" << std::endl;
    add(p1, p2).print();
    std::cout << "\np1(x) * p2(x)" << std::endl;
    multiply(p1, p2).print();
    return 0;
}
