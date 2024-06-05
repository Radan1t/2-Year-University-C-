/*
Опір, активний опір, ємнісний опір, індуктивний опір. Поліморфна
функція повертає значення опіру для відповідного типу і виводить
повідомлення про тип опіру. Ланцюг змінного струму включає в себе певну
кількість активних, ємнісних і індуктивних елементів.
*/
#include <iostream>
using namespace std;
//Клас опору
class Resistanc {
public:
	virtual void Resist_Out() = 0;//віртуальна функція
};
//Клас активного опору
class Active : public Resistanc {
public:
	float ro = 0.7, S = 2, l = 4;
	void Resist_Out() {
		cout << "Active Resist: " << ro * l * S << endl;
	}
};
//Клас ємнісного опору
class Capactive : public Resistanc {
	float w= 1.5, C=1.7;
	void Resist_Out() {
		cout << "Active Resist: " << 1/(w*C)<< endl;
	}
};
//Клас індуктивного опору
class Inductive : public Resistanc {
	float w = 1.5, L = 0.9;
	void Resist_Out() {
		cout << "Active Resist: " << w*L << endl;
	}
};
int main() {
	Resistanc* Res[3];//створення 3 класів Опору
	Active first;//Створення активного
	Capactive second;//Створення Ємнісного
	Inductive third;//Створення індуктивного
	Res[0] = &first;//присвоєння значення до класу опору 
	Res[1] = &second;
	Res[2] = &third;
	for (int i = 0; i < 3; i++) {
		Res[i]->Resist_Out();//Використання віртуальної функц
	}
}
