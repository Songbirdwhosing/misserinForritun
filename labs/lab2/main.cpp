#include <string>
#include <iostream>
using namespace std;

class CWheel {
    float Diam; // Диаметр, например – 23.5
    string NameBr; // Имя производителя колёс, например – Michelin
};

class CCar {
    string Brand; // Бренд, например – LADA
    CWheel* W;
};