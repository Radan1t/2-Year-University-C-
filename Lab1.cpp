
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
//Створення класу 
class spher {
    float r;
public:
    spher();//Конструктор без параметрів
    ~spher();//Деструктор
    void print_val(float r);//Виведення радіусу та об'єму
};
//Визначення конструктора 
spher::spher() {
    r = 0;
    cout << "Куля створена. " << endl;
}
//Визначення деструктора 
spher::~spher(){
    cout << "Куля зруйнована. " << endl;
}

//Виведення радіусу та об'єму
void spher::print_val(float r) {
    float v = 4 / 3.00 * M_PI * pow(r, 3);
    cout << "Радiус кулi " << r << "\nОб'єм кулi " << v << endl;
}
int main()
{
    int q;
    setlocale(LC_ALL, "ukr");
    spher a,b;
    a.print_val(0);//Виведення об'єму для 1 кулі
    cout << "Введiть радiус кулi " << endl;//Запис радіусу для 2 кулі
    cin >> q;
    b.print_val(q);//Виведення об'єму для 2 кулі

}
