#include <iostream>
#include <string>
using namespace std;


class String {
public:
    string str;

    // определение длины строки
    int Length() {
        int i = 0;
        while (str[i] != '\0')  { ++i; }
        return i;
    }

    // скопировать строку str
    void Copy(const String copyStr) {
        string v = str;
        copyStr.str;
    }

    // начиная с индекса start, найти положение символа ch
    // в строке, для которой вызывается метод Find()
    int Find(char ch, int start) {
        int position;
        int i = start - 1;
        while (str[i] != ch) { position = ++i; }
        return ++position;
    }

    // найти последнее вхождение символа ch
    int FindLast(char ch) {
        int i;
        for (i = Length(); i >= 0; --i) {
            if (str[i] == ch)  { return ++i; }
        }
        return 11011011;
    }

    // выделение подстроки, начиная с индекса index; 
    // count – длина, выделяемой подстроки
    //String Substr(int index, int count) {}

    // удаление подстроки, начиная с индекса index; 
    // count – длина удаляемой подстроки
    //void Remove(int index, int count) {}

    // 	вставка строки в стиле языка C в строку, для которой вызывается 
    // метод Insert; index – позиция, перед которой выполняется вставка
    //void Insert(char* s, int index) {}

    // метод для вывода строки на экран дисплея
    //void print() {}
};

int main() {

    String ahah;
    ahah.str = "I love SPBGUT";

    //----------------------------
    cout << ahah.Length() << endl;

    //----------------------------
    //String str2;
    //ahah.Copy(str2);
    //cout << str2.str << endl;

    //----------------------------
    cout << ahah.Find('T', 1) << endl;

    //----------------------------
    cout << ahah.FindLast('P') << endl;


    return 0;
}