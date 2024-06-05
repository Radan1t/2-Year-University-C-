// Створить текстовий файл на ім’я data.txt, с довільною кількістю рядків,
// але не меньше 10 зі студентами та їх оцінками з трьох предметів:
// математики, фізики, інформатики. Формат файлу: кожний рядок містить
// прізвище, ім'я та три числа. Дані в рядку розділені одним пробілом або
// символом «Tab». Оцінки приймають значення від 1 до 5.
// Створить масив екземплярів класу та зчитати дані з файлу data.txt для
// визначення відповідних полів. Виконати завдання відповідно варіанту.
// Завдання до варіанту
// Вивести успішність для певного студента, ім’я якого буде задано з клавіатури.
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Student // початок оголошення класу
{
	string name; // ім'я студента
	int Math,Phisic,Informatic; // бали
public:
	void Set(string surname, int Math, int Phisic, int Informatic);//Присвоєння екземплярів
	string GetName();//Повернення імені із класу
	int GetScores();//Повернення імені із класу
	void Print();//Виведення інформації про студента
};

//Присвоєння екземплярів
void Student::Set(string surname, int Math, int Phisic, int Informatic) {
	this->name = surname;
	this->Math = Math;
	this->Phisic = Phisic;
	this->Informatic = Informatic;
}
//Повернення імені із класу
string Student::GetName() {
	return  name;
}
//Повернення імені із класу
int Student::GetScores() {
	return Math, Phisic, Informatic;
}
//Виведення інформації про студента
void Student::Print() {
	cout << "Студент(ка) " << name << " має\n " << Math << " балiв з математики \n " << Phisic << " балiв з фiзики \n " << Informatic << " балiв з iнформатики" << endl;
}

int main() {
	setlocale(LC_ALL, "Ukr");
	int q = 0;//створення лічильника на потім
	string str,srcStudent;
	ifstream fin("data.txt"); // створення потоку читання файлу
	if (fin)
	{
		while (!fin.eof()) // поки не кінець файлу
		{
			getline(fin, str, '\n');// зчитуємо рядок
			q++; // підраховуємо кількість рядків
		}
		// створюється масив об’єктів
		Student *P = new Student[q];
		fin.clear();
		fin.seekg(0); 
		//Заповнення класу Студентами
		for (int i = 0; i < q; i++)
		{
			string name;
			int b,c,d;
			fin >> name;
			fin >> b;
			fin >> c;
			fin >> d;
			P[i].Set(name, b,c,d); // виклик методу Set для i-го студента
		}
		//отримання імені студенту якого шукаєте
		cout << "Введiть iм'я студента якого шукаєте(Англsйською) " << endl;
		cin >> srcStudent;

		for (int i = 0; i < q; i++) {
			if (srcStudent == P[i].GetName())//Виведеня інформації якщо найшло цього студента
				P[i].Print();

		}
		fin.close(); // закриття потоку
		delete[]P; // звільнення динамічної пам’яті
	}
	else
		cout << "Unable to open file";
}
