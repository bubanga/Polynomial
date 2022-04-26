#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H


class Polynomial {
private:
    /**
     * minimalna wartosc dla coefficient
     */
    const int min = -10;

    /**
     * maksymalna wartosc dla coefficient
     */
    const int max = 10;

    /**
     * int n - stopień wielomianu
     */
    int degree;

    /**
     * double* coefficients - dynamicznie alokowana tablica współczynników wielomianu skonstruowana tak, że coefficients[0] oznacza wyraz wolny, coefficients[1] jest współczynnikiem przy pierwszej potędze x itd.
     */
    double* coefficients;

    /**
     * metoda generujaca losowe wartosci dla coefficients z zakresu [this->min, this->max]
     */
    void generateCoefficients();
public:
    /**
     * Konstruktor, przyjmujący jeden parametr typu całkowitego (określający stopień wielomianu) powinien przydzielić pamięć dla współczynników wielomianu oraz zainicjalizować te współczynniki wartościami losowym
     * @param degree n-stopien wielomianu
     */
    explicit Polynomial(int degree);

    /**
     * Konstruktor kopiujący
     * @param Polynomial
     */
    Polynomial(const Polynomial &other);

    /**
     * @param Polynomial
     * @return
     */
    Polynomial & operator=(const Polynomial &other);

    /**
     * Destruktor
     */
    ~Polynomial();

    /**
     * drukuj wielomian
     */
    void print();

    /**
     * zwraca wielomian będący pochodną argumentu
     * @return
     */
    Polynomial derivative();

    /**
     * Zwraca stopien wielomianu
     * @return stopien wielomianu
     */
    int getDegree() const;

    /**
     * Funkcja sluzy do wyzerowania wspolczynnikow wielomianu, potrzebne jest podczas mnozenia dwoch wielomianow
     */
    void resetPolynomial();

    double getCoefficient(int _degree) const;
    void setCoefficient(int _degree, double coefficient) const;
};

/**
 * suma 2 wielomianów
 * @param p1
 * @param p2
 * @return
 */
Polynomial add(const Polynomial& p1, const Polynomial& p2);

/**
 * iloczyn 2 wielomianów
 * @param p1
 * @param p2
 * @return
 */
Polynomial multiply(const Polynomial& p1, const Polynomial& p2);

#endif //POLYNOMIAL_POLYNOMIAL_H
