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
  ~COne() {
    s1_.clear();
    cout << "COne was deleted." << endl;
  }

  // Перегруженный оператор присваивания
  COne operator=(COne arg) {
    n_ = arg.n_;
    s1_ = arg.s1_;
    return *this;
  }

  // Методы доступа
  const int &get_n() const { return n_; }

  const string &get_s1() const { return s1_; }

  void set_n(int n) { n_ = n; }

  void set_s1(string s) { s1_ = s; }

  // Метод print()
  virtual void print() const {
    cout << "n = " << n_ << endl;
    cout << "s = " << s1_ << endl;
  }

  friend class CTwo;
  friend class CThree;
  friend class CFour;
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
  const string &get_s2() const { return s2_; }

  const COne &get_p() const { return p_; }

  void set_s2(string s) { s2_ = s; }

  void set_p(COne p) { p_ = p; }

  // Метод print()
  virtual void print() const {
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
  virtual void print() const {
    cout << "b = " << b_ << endl;
    CTwo ::print();
  }
};

class CFour : public CThree {
  int g_;

public:
  // Конструктор умолчания
  CFour() : g_(0) {}

  // Конструктор с параметром
  CFour(int g, double b, string s, const COne &arg)
      : g_(g), CThree(b, s, arg) {}

  // Конструктор копирования
  CFour(const CFour &arg) : g_(arg.g_), CThree(arg) {}

  // Деструктор
  ~CFour() { cout << "CFour was deleted." << endl; }

  // Перегруженный оператор присваивания
  CFour operator=(const CFour &arg) {
    if (this == &arg)
      return *this;
    CThree ::operator=(arg);
    return *this;
  }

  // Метод print()
  void print() {
    cout << "g = " << g_ << endl;
    CThree ::print();
  }
};

void PrintAll(CTwo **P, int N) {
  for (int i = 0; i < N; ++i) {
    P[i]->print();
    cout << endl;
  }
}

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
  cls3.set_s1("OTHER");
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
  cls7.set_s2("Iceland");
  cls7.set_p(cls2);
  COne cls8 = cls7.get_p();
  cout << "s = " << cls7.get_s2() << endl;
  cls8.print();

  cout << endl;
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
  */

  cout << "ПРОВЕРКА CFour" << endl;
  cout << "Конструктор умолчания" << endl;
  CFour cls13;
  cls13.print();

  cout << "Конструктор с параметром" << endl;
  COne tempCOne(1977, "Led Zeppelin");
  CFour cls14(4, 20.23, "gobolelebidiguk", tempCOne);
  cls14.print();

  cout << "Конструктор копирования" << endl;
  CFour cls15(cls14);
  cls15.print();

  cout << "Перегруженный оператор присваивания" << endl;
  CFour cls16 = cls15;
  cls16.print();

  cout << endl;
  cout << "Проверка PrintAll()" << endl;
  CTwo *Array[3];
  Array[0] = new CTwo("first", tempCOne);
  Array[1] = new CThree(721.514, "second", tempCOne);
  Array[2] = new CFour(2005, 1315.777904, "Led Zeppelin IV", tempCOne);
  PrintAll(Array, 3);

  return 0;
}
