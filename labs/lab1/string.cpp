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
        str = copyStr.str;
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
    String Substr(int index, int count) {
        int i;
        String result (*this);
        result.str = "";
        for (i = index; i < index+count; ++i) {
            result.str += str[i];
        }
        return result;
    }

    // удаление подстроки, начиная с индекса index; 
    // count – длина удаляемой подстроки
    void Remove(int index, int count) {
        str.erase(index, count); 
    }

    // 	вставка строки в стиле языка C в строку, для которой вызывается 
    // метод Insert; index – позиция, перед которой выполняется вставка
    void Insert(char *s, int index) {
        str.insert(index, s);
    }

    // метод для вывода строки на экран дисплея
    void print() {
        cout << str << endl;
    }
};

int main() {

    String ahah;
    ahah.str = "I love SPBGUT";

    //----------------------------
    cout << ahah.Length() << endl;

    //----------------------------
    String blupblup;
    blupblup.str = "I don't love SPBGUT";
    ahah.Copy(blupblup);
    cout << ahah.str << endl;

    //----------------------------
    cout << ahah.Find('T', 1) << endl;

    //----------------------------
    cout << ahah.FindLast('P') << endl;

    //----------------------------
    cout << ahah.Substr(2, 4).str << endl;
    
    //----------------------------
    ahah.Remove(2, 4);
    cout << ahah.str << endl;

    //----------------------------
    ahah.Insert("love", 2);
    cout << ahah.str << endl;

    //----------------------------
    cout << "And finally -> "; ahah.print();


    return 0;
}