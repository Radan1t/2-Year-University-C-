// Створити клас, конструктор якого генерує динамічний масив чисел (див. варіанти).
// Розмір масиву задається параметром конструктора. Деструктор звільняє пам’ять, що виділена під масив.
// Створити функцію, параметром якої є створений клас.
// Функція виконує дії над масивом певного типу відповідно варіанту (таблиця 4.1).
// Тип даних Дійсний. Вираз для обчислення елемента масиву: Пар і-3,8 , не Пар і+1,5
// Знайти суму всіх додатніх елементів 
#include <conio.h>
#include <iostream>
using namespace std;
class Lab4
{
public:
    Lab4(int arrsize);//Звичайний конструктор
    Lab4(const Lab4& ob);//Конструктор копій
    ~Lab4();//деструктор
    void ArrayOutput();//виведення масиву
    void ArrayinputandSum();//Заповнення масиву та обрахунок суми додатніх елементів
private:
    float* array;
    int size;
};
//Заповнення масиву та обрахунок суми додатніх елементів
void Lab4::ArrayinputandSum() {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            array[i] = i - 3.8;
        }
        else {
            array[i] = i + 1.5;
        }
    }
    for (int i = 0; i < size; i++)
        if (array[i] > 0) {
            sum += array[i];
        }
    cout << "Сума всiх додатнiх елементiв: " << sum << endl;
}
//Звичайний конструктор
Lab4::Lab4(int arrsize)
{
    size = arrsize;
    array = new float[size];
    cout << "Створенно масив чисел" << endl;
}

//Конструктор копій
Lab4::Lab4(const Lab4& ob) {
    size = ob.size;
    array = new float[size];
    for (int i = 0; i < size; i++) {
        array[i] = ob.array[i];
    }
    cout << "Створено копiю об'єкта" << endl;
}
//виведення масиву
void Lab4::ArrayOutput() {
    cout << "Масив чисел :" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
}
//деструктор
Lab4::~Lab4()
{
    cout << "Звiльнення пам'ятi" << endl;
    delete[] array;
}

int main()
{
    setlocale(0, "Ukr");
    Lab4 Array(13);//Конструктор звичайний
    Array.ArrayinputandSum();//Заповнення масиву та обрахунок суми додатніх елементів
    Array.ArrayOutput();//Виведення масиву
    Lab4 Arrayclone = Array;//Створення копії класу
    Arrayclone.ArrayOutput();//Виведення копії класу
    
}
