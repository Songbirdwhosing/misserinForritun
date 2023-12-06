#include <iostream>
#include <string>
using namespace std;

class COne {
private:
  int n;
  string s;

public:
  // Конструктор умолчания
  COne() {
    n = 0;
    s = "";
  }

  // Конструктор с параметром
  COne(int num, string str) {
    n = num;
    s = str;
  }

  // Конструктор копирования
  COne(const COne &p) {
    n = p.n;
    s = p.s;
  }

  // Деструктор
  ~COne() { cout << "COne deleted" << endl; }

  // Перегруженный оператор присваивания
  COne operator=(COne other) {
    n = other.n;
    s = other.s;
    return *this;
  }

  // Методы доступа
  void set_n(int num) { n = num; }

  void set_s(string str) { s = str; }

  int get_n() { return n; }

  string get_s() { return s; }

  // Метод print()
  void print() { cout << n << endl << s << endl; }
};

class CTwo {
  string s;
  COne *p;

public:
  // Конструктор умолчания
  CTwo() : s(""), p(new COne) {}

  // Конструктор с параметром
  CTwo(string str, const COne &arg) : s(str), p(new COne(arg)) {}

  // Конструктор копирования
  CTwo(const CTwo &arg) : s(arg.s), p(new COne(*arg.p)) {}

  // Деструктор
  ~CTwo() {
    delete p;
    cout << "CTwo deleted" << endl;
  }

  // Перегруженный оператор присваивания
  CTwo operator=(CTwo other) {
    s = other.s;
    p = other.p;
    return *this;
  }

  // Методы доступы
  void set_s(string str) { s = str; }

  void set_p(COne &arg) {
    delete p;
    p = new COne(arg);
  }

  string get_s() { return s; }

  COne *get_p() { return p; }

  // Метод print()
  void print() {
    cout << s << endl;
    p->print();
  }
};

class CThree : public CTwo {
  int k;

public:
  // Конструктор умолчания
  CThree() : CTwo(), k(0) {}

  // Конструктор с параметром
  CThree(const CTwo &arg, int K) : CTwo(arg), k(K) {}

  // Конструктор копирования
  CThree(const CThree &arg) : CTwo(arg), k(arg.k) {}

  // Деструктор
  ~CThree() { cout << "CThree deleted" << endl; }

  // Методы доступа

  // Метод print()
  void print() {
    p->print();
    cout << k << endl;
  }
};

int main() {
  /*
    cout << "---проверка КПУ---" << endl;
    COne c1;
    c1.print();

    cout << "---проверка КСП---" << endl;
    COne c2(20231034, "jambalay");
    c2.print();

    cout << "---проверка KK---" << endl;
    COne c3(c2);
    c3.print();

    cout << "---проверка ПОП---" << endl;
    COne c4 = c3;
    c4.print();

    cout << "---проверка МД---" << endl;
    c4.set_n(66666666);
    c4.set_s("qwertyui");
    cout << c4.get_n() << endl << c4.get_s() << endl;

    cout << endl << ">>>проверка CTwo<<<" << endl << endl;

    cout << "---проверка КПУ---" << endl;
    CTwo c5;
    c5.print();

    cout << "---проверка КСП---" << endl;
    CTwo c6("kick", c4);
    c6.print();

    cout << "---проверка KK---" << endl;
    CTwo c7(c6);
    c7.print();

    cout << "---проверка ПОП---" << endl;
    CTwo c8 = c7;
    c7.print();

    cout << "---проверка МД---" << endl;
    c8.set_s("ffrfr");
    c8.set_p(c4);
    cout << c8.get_s() << endl << c8.get_p() << endl;
    */
  CTwo cl0;

  CThree cl1;
  CThree cl2(cl0, 10);

  cl2.print();

  return 0;
}
