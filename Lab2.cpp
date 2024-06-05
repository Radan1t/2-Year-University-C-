//Створити клас «хрест», такий, що:
//a) його екземпляр містить два розміри a і b.
//b) його конструктор без параметра створює екземпляр зі значенням 0, а
//конструктор з параметрами створює екземпляр з відповідним значенням
//a і b.
//c) його методи дозволяють отримувати і присвоювати значення a, b та
//обчислювати значення площі.
//d) функція print_sqrt () виводить на екран значення a, b та площі цієї
//фігури.
//e) дружня функція frd в якості параметрів отримує екземпляри двох хрестів
//і повертає новий хрест, два розміри сторін a і b якого дорівнюють сумам
//сторін цих двох хрестів.

#include <iostream>;
using namespace std;
class  Crest_Sum;
class Crest
{
public:
	Crest();//Констурктор
	~Crest();//Деструктор
	void Print_sqrt();//Виведення площі
	void Crest_Getinfo();//Заповнення класу
	friend Crest_Sum;//Дружній клас
protected:
	float a;
	float b;
};
//Створення конструктора 
Crest::Crest()
{
	a = 0, b = 0;
	cout << "Хрест створено" << endl;
}
//Створення деструктора
Crest::~Crest()
{
	cout << "Хрест зруйновано" << endl;
}
//Введення значень в клас
void Crest::Crest_Getinfo(){
	cout << "Введiть значення сторони а" << endl;
	cin >> a;
	cout << "Введiть значення сторони b" << endl;
	cin >> b;
}
//Функція для підрахунку площі хреста
void Crest::Print_sqrt() {
	float area_sqer = pow((2 * a + b),2);
	float area_crest = area_sqer - (pow(a, 2) * 4);
	cout << "Площа хреста зi сторонами " << a << ", " << b << endl;
	cout << area_crest << endl;
}
//Створення дружнього класу
class Crest_Sum
{
public://Функція яка створює новий хрест з двох
	void frd(Crest first,Crest second) {
		cout << "Крест утворений iз 2 iнших" << endl;
		cout << " Нова сторона а = " << first.a+second.a << ", нова сторона b = " << first.b+second.b << endl;
	}
};

int main() {
	setlocale(LC_ALL, "ukr");
	Crest a, b, c;
	a.Print_sqrt();//Виведеня площі без параметрів 
	b.Crest_Getinfo();//Заповнення параметирами
	b.Print_sqrt();//Виведення площі з парамектрами
	c.Crest_Getinfo();//Заповнення параметирами
	c.Print_sqrt();//Виведення площі з парамектрами
	Crest_Sum q;
	q.frd(b, c);//Виведення розмірів нового хреста 
}
