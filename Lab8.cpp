/*
Порядок виконання роботи

1. Створити шаблон заданого класу. Визначити конструктори, деструктор, перевантажену операцію присвоювання ("=") та операції, що задані у варіанті завдання.

2. Написати програму тестування, в якій перевіряється використання шаблону для стандартних типів даних.

3. Виконати тестування.

4. Визначити користувальницький клас, який буде використовуватися в якості параметра шаблону. Визначити в класі необхідні функції і перевантажені операції.

5. Написати програму тестування, в якій перевіряється використання шаблону для користувальницького типу.

6. Виконати тестування.
*/
#include <iostream>
#include <list>

using namespace std;

template <typename T>
class List {
    list<T> items;
    int maxSize;

public:
    List(int size) : maxSize(size) {
        if (size <= 0)
            throw out_of_range("Invalid size");
    }
    //функція для заповнення
    void push(const T& value) {
        if (items.size() < maxSize) {
            items.push_back(value);
        }
        else {
            cout << "Warning: Limit reached\n";
        }
    }
    //Функція для очищення
    void clear() {
        items.clear();
    }

    int length() const { return items.size(); }
    int maxLength() const { return maxSize; }
    //Перевантаження оператора для виведення даних
    T& operator[](int index) {
        if (index < 0 || index >= maxSize)
            throw out_of_range("Invalid index");

        auto it = items.begin();
        advance(it, index);
        return *it;
    }
    //Перевантаження оператора +
    List<T>& operator+(const T& value) {
        push(value);
        return *this;
    }
    //Перевантаження оператора -
    List<T>& operator--() {
        if (!items.empty()) {
            items.pop_back();
        }
        return *this;
    }
    //Перевантаження оператора !=
    bool operator!=(const List<T>& other) const {

        return (items != other.items) || (maxSize != other.maxSize);
    }
};
//Клас який буде використаний для шаблону
class Complex {
    int re;
    int im;

public:
    Complex() : re(0), im(0) {}
    Complex(int re, int im) : re(re), im(im) {}
    int getRe() const { return re; }
};

int main() {
    //Створення листів
    cout << "Creating lists\n";
    List<bool> bools(4);
    List<char> chars(4);
    List<short> shorts(4);
    List<int> ints(4);
    List<Complex> cmplxs(4);
    //Заповнення листів
    cout << "\nFilling lists for test []\n";
    bools.push(true);
    bools.push(false);
    chars.push('B');
    chars.push('O');
    shorts.push(135);
    shorts.push(33);
    ints.push(4);
    ints.push(29);
    cmplxs.push(Complex(3, 3));
    cmplxs.push(Complex(12, 5));
    //Виведення інформації
    cout << "\nUsing operator []\n";
    for (int i = 0; i < bools.length(); i++) cout << bools[i] << ' ';
    cout << endl;
    for (int i = 0; i < chars.length(); i++) cout << chars[i] << ' ';
    cout << endl;
    for (int i = 0; i < shorts.length(); i++) cout << shorts[i] << ' ';
    cout << endl;
    for (int i = 0; i < ints.length(); i++) cout << ints[i] << ' ';
    cout << endl;
    for (int i = 0; i < cmplxs.length(); i++) cout << cmplxs[i].getRe() << ' ';
    cout << endl;
    //Використання оператора +
    cout << "\nUsing operator +\n";
    bools + true + false;
    chars + 'B' + 'O';
    shorts + 135 + 33;
    ints + 4 + 29;
    cmplxs + Complex(3, 3) + Complex(12, 5);
    //Виведення інформ після оператора +
    cout << "\nUsing operator []\n";
    for (int i = 0; i < bools.length(); i++) cout << bools[i] << ' ';
    cout << endl;
    for (int i = 0; i < chars.length(); i++) cout << chars[i] << ' ';
    cout << endl;
    for (int i = 0; i < shorts.length(); i++) cout << shorts[i] << ' ';
    cout << endl;
    for (int i = 0; i < ints.length(); i++) cout << ints[i] << ' ';
    cout << endl;
    for (int i = 0; i < cmplxs.length(); i++) cout << cmplxs[i].getRe() << ' ';
    cout << endl;
    //Викорисатння оператора -
    cout << "\nUsing operator --\n";
    --bools;
    --chars;
    --shorts;
    --ints;
    --cmplxs;
    //Виведення інформ після опер -
    cout << "\nUsing operator []\n";
    for (int i = 0; i < bools.length(); i++) cout << bools[i] << ' ';
    cout << endl;
    for (int i = 0; i < chars.length(); i++) cout << chars[i] << ' ';
    cout << endl;
    for (int i = 0; i < shorts.length(); i++) cout << shorts[i] << ' ';
    cout << endl;
    for (int i = 0; i < ints.length(); i++) cout << ints[i] << ' ';
    cout << endl;
    for (int i = 0; i < cmplxs.length(); i++) cout << cmplxs[i].getRe() << ' ';
    cout << endl;
    //Знову викоритання шаблону щоб можна було порівняти за допомогою оператора !=
    List<bool> bool1(4);
    List<char> chars1(4);
    chars1.push('B');
    chars1.push('O');
    chars1.push('B');
    List<short> shorts1(4);
    List<int> ints1(4);
    ints1.push(4);
    ints1.push(29);
    ints1.push(4);
    if (bools != bool1) {
        cout << "bools and bool1 are not equal." << endl;
    }
    else {
        cout << "bool1 and bool1 are equal." << endl;
    }
    if (chars != chars1) {
        cout << "chars and chars1 are not equal." << endl;
    }
    else {
        cout << "chars and chars1 are equal." << endl;
    }
    if (shorts != shorts1) {
        cout << "shorts and shorts1 are not equal." << endl;
    }
    else {
        cout << "shorts and shorts1 are equal." << endl;
    }
    if (ints != ints1) {
        cout << "ints and ints1 are not equal." << endl;
    }
    else {
        cout << "ints and ints1 are equal." << endl;
    }


}
