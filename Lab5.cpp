// Створити клас «смайлик», такий, що:
// а) його екземпляр містить розмір радіуса особи R і радіуса r очей.
// b) його конструктор без параметра створює екземпляр зі значенням 0, а
// конструктор з параметрами створює екземпляр з відповідним значенням
// R і r.
// c) його методи дозволяють отримувати і присвоювати значення R і r та
// обчислювати значення площі.
// d) операція «<<» перевантажена: виводить на екран значення R, r і площі
// (без площі очей).
// e) операція «+» перевантажена: для двох «смайликів» створює новий
// «смайлик» з параметрами (R = R1 + R2, r = r1 + r2).
// g) операція «++» збільшує радіус «обличчя» R і радіус r очей на одиницю.
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include<math.h>
using namespace std;
class Face {
    float R, r;
public:
    //конструктор
    Face() {
        R = 0;
        r = 0;
        cout << "Face created" << endl;
    };
    //конструктор копій
    Face(float radius_R, float radius_r) {
        R = radius_R;
        r = radius_r;
    }
    //деструктор
    ~Face() {
        cout << "Face destroyed" << endl;
    };
    //Заповнення класу інформацією та виведення площі 
    void Inputinfo() {
        cout << "Enter Face Radius" << endl;
        cin >> R;
        do {
            cout << "Enter eyes radius (must be less then Face Radius)" << endl;
            cin >> r;
            if (R < 4 * r)cout << "Wrong input \nInput correct radius" << endl;
        } while (R < 4 * r);
        float Area = pow(R, 2.00) * M_PI - 2 * (pow(r, 2.00) * M_PI);
        cout << "Face Area: " << Area << endl;
    }
    // Операція + перевантажена
    Face operator +(const Face& b) {
        cout << "Created new Face from 2 faces" << endl;
        Face c(R + b.R, r + b.r);
        return c;
    };
    //операція ++ перевантажена
    Face operator ++ () {
        cout << "R and r +1" << endl;
        R++;
        r++;
        return *this;
    };
    //Дружня функція для операції <<
    friend ostream& operator <<(ostream& os, Face& a);
};
//операція << перевантажена
ostream& operator <<(ostream& os, Face& a) {
    os << "Face Radius: " << a.R << endl;
    os << "Eyes radius: " << a.r << endl;
    os << "Fase Area(without eyes)" << pow(a.R, 2.00) * M_PI << endl;
    os << endl;
    return os;
}
int main()
{
    Face a, b;
    a.Inputinfo();
 
    cout << a;
    ++a;
    cout << a;
    b.Inputinfo();
    Face c = a + b;
    cout << c;
}
