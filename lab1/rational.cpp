#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Rational {
    int p, q;

    Rational reduce() {
	    auto g = gcd(p < 0 ? -p : p, q);
	    p /= g;
	    q /= g;
        return *this;
    }

    int gcd(int a, int b) {
	while (a) {
	    auto t = b % a;
	    b = a;
	    a = t;
	}
	return b;
    }

public:
    // конструктор умолчания
        Rational() {
	    p = 0;
	    q = 1;
    }

    // конструктор с параметрами
    Rational(int num, int den) {
	    p = num;
	    q = den;
    }

	// геттеры
	int getNum() const {
		return p;
	}

	int getDen() const {
		return q;
	}

    // сложение
    Rational operator + (const Rational &other) const {
    	return Rational( p*other.q + other.p*q, q*other.q ).reduce();
    }

    // вычитание
    Rational operator - (const Rational &other) const {
    	return Rational( p*other.q - other.p*q, q*other.q ).reduce();
    }

    // умножение
    Rational operator * (const Rational &other) const {
	    return Rational( p*other.p, q*other.q );
    }
    
    // деление
    Rational operator / (const Rational &other) const {
        return Rational( p*other.q, q*other.p ).reduce();
    }

    // сравнениe на равенствo
    bool operator == (const Rational &other) const {
        return ( p == other.p and q == other.q );
    }

    // сравнениe на неравенство
    bool operator != (const Rational &other) const {
        return ( p != other.p and q != other.q );
    }

    // отношения
    bool operator > (const Rational &other) const {
        return ( p*other.q > other.p*q );
    }

    bool operator < (const Rational &other) const {
        return ( p*other.q < other.p*q );
    }

    bool operator >= (const Rational &other) const {
        return ( p*other.q >= other.p*q );
    }

    bool operator <= (const Rational &other) const {
        return ( p*other.q <= other.p*q );
    }
    // вывод рационального числа на экран дисплея
    void printRational() {
        cout << p/(double)q << endl;
    }

};

int
main() {
    Rational i(2, 5), j(4, 5);
    i.printRational();
    j.printRational();

    Rational k; 
    k = i + j;

    //сложение
    cout << "Сложение: " << endl;
    k.printRational();
    //cout << k.getNum() << endl << k.getDen() << endl;

    // вычитание
    cout << "Вычитание: " << endl;
    k = k - j;
    k.printRational();

    // умножение
    cout << "Умножение: " << endl;
    k = k * j;
    k.printRational();
    cout << k.getNum() << endl << k.getDen() << endl;

    // деление
    cout << "Деление: " << endl;
    k = k * i;
    k.printRational();
    cout << k.getNum() << endl << k.getDen() << endl;

    // сравнение ==
    cout << "Сравнение ==: " << endl;
    Rational h(16, 125);
    cout << (k == h) << endl;

    // сравнение !=
    cout << "Сравнение !=: " << endl;
    cout << (k != h) << endl;

    // сравнение !=
    cout << "Сравнение >: " << endl;
    Rational f(15, 125);
    cout << (k > f) << endl;


    return 0;
}
