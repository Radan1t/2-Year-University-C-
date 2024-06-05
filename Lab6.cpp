// 1. Визначити ієрархію класів (відповідно до варіанта). Для визначення
// ієрархії класів зв'язати ставленням спадкування класи, наведені для заданого
// варіанта, з цих класів обрати один, який буде стояти на чолі ієрархії.
// 2. Реалізувати класи. Визначити в класах всі необхідні конструктори і
// деструктор.
// 3. Написати демонстраційну програму, в якій створюються об'єкти різних
// класів.
// 4. Побудувати діаграму класів.
// Дуб, рослина, дерево, очерет;

#include <iostream>
#include <string>
using namespace std;
//Створення класу рослини
class Plant {
    int Age;
    string name;
public:
    Plant() {
        cout <<"Plant is growing"  << endl;
    }
    ~Plant() {
        cout <<"Plant is disapier" << endl;
    }
    void set_Age(int year) {
        Age = year;
    }
    void set_Name(string Nam) {
        name = Nam;
    }
    int get_Age() {
        return Age;
    }
    string get_Name() {
        return name;
    }
};
//Створення класу дерева який є частиною класу рослини
class Tree : public Plant {
    string type;
public:
   Tree() {
        cout << "Tree is growing" << endl;
    }
    ~Tree() {
        cout<< type << " Tree is disapier" << endl;
    }
    void set_type(string t) {
        type = t;
    }
    string get_type() {
        return type;
    }
};
//Створення класу дуб який є частиною класу дерева
class Oak : public Tree {
    int order;
public:
    //Oak() {
    //    cout << "Oak is growing" << endl;
   // }
   // ~Oak() {
     //   cout << "Oak is disapier" << endl;
    //}
    void set_order(int number) {
        order = number;
    }
    void show() {
        cout << "Oak # " << order << ". Has name - " << get_Name() << " and " << get_Age() << " old." << endl;
    }
};
class Cedrus : public Tree {
    int order;
public:
    //Cedrus() {
      //  cout << "Cedrus is growing" << endl;
    //}
   // ~Cedrus() {
     //   cout << "Cedrus is disapier" << endl;
    //}
    void set_order(int number) {
        order = number;
    }
    void show() {
        cout << "Cedrus # " << order << ". Has name - " << get_Name() << " and " << get_Age() << " old." << endl;
    }
};
class Cane : public Plant {
public:
    //Cane() {
    //    cout << "Cane is growing" << endl;
    //}
    //~Cane() {
      //  cout << "Cane is disapier" << endl;
    //}
    void show() {
        cout << "Cane: " << get_Name() << " is " << get_Age() << " years old" << endl;
    }
};
int main()
{  
    Oak b;
    Cedrus c;
    Cane a;
    b.set_Name("Big oak");
    b.set_Age(75);
    b.set_order(1);
    b.set_type("Deciduous");
    b.show();
    c.set_Name("Atlantic");
    c.set_Age(45);
    c.set_type("Conifer");
    c.set_order(2);
    c.show();
    a.set_Name("Sugar Cane");
    a.set_Age(2);
    a.show();

}
