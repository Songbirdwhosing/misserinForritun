#include <iostream>
#include <string>
using namespace std;

class COne {
  int n_;
  string s1_;

public:
  // Конструктор умолчания
  COne() : n_(0), s1_("") {}

  // Конструктор с параметром
  COne(int n, string s) : n_(n), s1_(s) {}

  // Конструктор копирования
  COne(const COne &arg) : n_(arg.n_), s1_(arg.s1_) {}

  // Деструктор
  ~COne() { cout << "COne was deleted." << endl; }

  // Перегруженный оператор присваивания
  COne operator=(COne arg) {
    n_ = arg.n_;
    s1_ = arg.s1_;
    return *this;
  }

  // Методы доступа
  int get_n() { return n_; }

  string get_s() { return s1_; }

  void set_n(int n) { n_ = n; }

  void set_s(string s) { s1_ = s; }

  // Метод print()
  void print() {
    cout << "n = " << n_ << endl;
    cout << "s = " << s1_ << endl;
  }
};

class CTwo {
  string s2_;
  COne p_;

public:
  // Конструктор умолчания
  CTwo() : s2_(""), p_() {}

  // Конструктор с параметром
  CTwo(string s, const COne &arg) : s2_(s), p_(arg) {}

  // Конструктор копирования
  CTwo(const CTwo &arg) : s2_(arg.s2_), p_(arg.p_) {}

  // Деструктор
  ~CTwo() {
    s2_.clear();
    cout << "CTwo was deleted." << endl;
  }

  // Перегруженный оператор присваивания
  CTwo operator=(CTwo arg) {
    s2_ = arg.s2_;
    p_ = arg.p_;
    return *this;
  }

  // Методы доступа
  string get_s() { return s2_; }

  COne get_p() { return p_; }

  void set_s(string s) { s2_ = s; }

  void set_p(COne p) { p_ = p; }

  // Метод print()
  void print() {
    cout << "s = " << s2_ << endl;
    p_.print();
  }
};

class CThree : public CTwo {
  double b_;

public:
  // Конструктор умолчания
  CThree() : b_(.0), CTwo() {}

  // Конструктор с параметром
  CThree(double b, string s, const COne &arg) : b_(b), CTwo(s, arg) {}

  // Конструктор копирования
  CThree(const CThree &arg) : b_(arg.b_), CTwo(arg) {}

  // Деструктор
  ~CThree() { cout << "CThree was deleted." << endl; }

  // Методы доступа

  // Перегруженный оператор присваивания
  CThree operator=(const CThree &arg) {
    if (this == &arg)
      return *this;
    CTwo ::operator=(arg);
    return *this;
  }
  // Метод print()
  void print() {
    cout << "b = " << b_ << endl;
    CTwo ::print();
  }
};

int main(int argv, char *argc[]) {
  /*
  cout << "ПРОВЕРКА COne" << endl;
  cout << "Конструктор умолчания" << endl;
  COne cls1;
  cls1.print();

  cout << "Конструктор с параметром" << endl;
  COne cls2(13243546, "Text");
  cls2.print();

  cout << "Конструктор копирования" << endl;
  COne cls3(cls2);
  cls3.print();

  cout << "Перегруженный оператор присваивания" << endl;
  cls3 = cls1;
  cls3.print();

  cout << "Методы доступа" << endl;
  cls3.set_n(777);
  cls3.set_s("OTHER");
  cls3.print();

  cout << endl;
  cout << "ПРОВЕРКА CTwo" << endl;
  cout << "Конструктор умолчания" << endl;
  CTwo cls4;
  cls4.print();

  cout << "Конструктор с параметром" << endl;
  CTwo cls5("Rejkyavik", cls3);
  cls5.print();

  cout << "Конструктор копирования" << endl;
  CTwo cls6(cls5);
  cls6.print();

  cout << "Перегруженный оператор присваивания" << endl;
  CTwo cls7 = cls6;
  cls7.print();

  cout << "Методы доступа" << endl;
  cls7.set_s("Iceland");
  cls7.set_p(cls2);
  COne cls8 = cls7.get_p();
  cout << "s = " << cls7.get_s() << endl;
  cls8.print();
  */

  cout << "ПРОВЕРКА CThree" << endl;
  cout << "Конструктор умолчания" << endl;
  CThree cls9;
  cls9.print();

  cout << "Конструктор с параметрами" << endl;
  COne tempCls;
  CThree cls10(3.14, "ahaha", tempCls);
  cls10.print();

  cout << "Конструктор копирования" << endl;
  CThree cls11(cls10);
  cls11.print();

  cout << "Перегруженный оператор присваивания" << endl;
  CThree cls12 = cls11;
  cls12.print();

  return 0;
}
