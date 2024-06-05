/*
Курсова була дуже проста тому оцінити по ній знання гарно не можливо але в курсовій по бд використовувася C# тому там видно що знань у мене більше  
1. Тема роботи: “Розробка програми для розрахунку вантажу пароплава”
2. Вихідні дані до роботи:
   Клас на ім'я Paroplav, що містить наступні властивості:
   - назва пункту призначення;
   - кількість пасажирів;
   - назва компанії;
   - тоннажність (т.);
   - функція, яка повертає 1, якщо пароплав перевантажений та 0 в інших випадках. (Середня вага одного пасажира 70 кг)

   Створення динамічного масиву об'єктів Paroplav, розмірність якого дорівнює кількості рядків у файлі;
   Читання з файлу in.txt даних у масив об’єктів Paroplav;
   Вивід на дисплей і у файл пункти призначення, куди пароплав не прибуде, тому що перевантажений, а також назву компанії, що здійснює таку перевозку. Записи мають бути впорядковані по алфавіту.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class Transport {
protected:
    string Destination;
public:
    //Transport() { cout << "Transport created" << endl; };
    //~Transport() { cout << "Transpord disapierd" << endl; };
   
};
class Paroplav : public Transport {
protected:
    string Company;
    int Number_Pasagirs;
    float Tonnage;
    int chek;
public:
    void Set_info(string Destinat, int Num, string Comp, float Tonnage) {
        this->Destination = Destinat;
        this->Number_Pasagirs = Num;
        this->Company = Comp;
        this->Tonnage = Tonnage;
    }
    void Drowned(){
        cout << "Paroplav that go to " << Destination << ",(from company " << Company << ") will not go to finish, because he drowned" << endl;
    }
    int Check_Ton() {
        if (Tonnage * 10000 >= Number_Pasagirs * 70) {
            chek = 0;
        }
        else chek = 1;
        return chek;
    }
    int Get_Chek() {
        return chek;
    }
    string Get_Dest() {
        return Destination;
    }
    string Get_Comp() {
        return Company;
    }
    bool operator<(const Paroplav& other) const {
        return Destination < other.Destination;
    }
};
int main()
{
    int counter = 0;
    string str;
    ifstream fin("in.txt");
    ofstream giv("Drowned.txt");
    if (fin) {
        while (!fin.eof()) 
        {
            getline(fin, str, '\n');
            counter++; 
        }
        Paroplav* Par = new Paroplav[counter];
        fin.clear();
        fin.seekg(0);
        for (int i = 0; i < counter; i++) {
            string det, comp;
            int Num;
            float Tonn;
            fin >> det;
            fin >> Num;
            fin >> comp;
            fin >> Tonn;
            Par[i].Set_info(det, Num, comp, Tonn);
            Par[i].Check_Ton();
        }
        sort(Par, Par + counter);
        for (int i = 0; i < counter; i++) {
            if (Par[i].Get_Chek() == 1) {
                Par[i].Drowned();
            }
        }
        if (giv) {
            for (int i = 0; i < counter; i++) {
                if (Par[i].Get_Chek() == 1) {
                    giv <<"Paroplav that goes to - " << Par[i].Get_Dest() << " from company (" << Par[i].Get_Comp() <<")" << endl;;
                }
            }
        }else { cout << "error 'info.txt'"; }

    }
    else { cout << "error 'in.txt'"; }
}
