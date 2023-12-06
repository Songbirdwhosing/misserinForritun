#include <iostream>
using namespace std;

class String {
  char *string_ = nullptr;
  size_t size_ = 0;

  size_t len(const char *str) {
    size_t i = 0;
    if (str) {
      ++i;
      while (*str != '\0') {
        ++str;
        ++i;
      }
    }
    return i;
  }

public:
  // Конструктор умолчания
  String() = default;

  // Конструктор с параметром
  String(char *string) : string_(string) {}

  // Длина (без учета символа '\0')
  size_t Lenght() const { return (size_ > 1) ? (size_ - 1) : 0; }

  void Copy(const String &arg) {
    // for (int i = 0; i < arg.Lenght(); ++i) {
    //   string_[i] = arg.string_[i];
    // }
  }

  // String Substr(int index, int count) {}

  // void Remove(int index, int count) {}

  // void Insert(char *s, int index) {}

  // void trim() {}

  // void read() {}

  // void print() {}
};

int main(int argc, char *argv[]) {
  String str1("Iceland");
  String str2("Sigur Ros");
  cout << str1.Lenght() << endl;

  return 0;
}
