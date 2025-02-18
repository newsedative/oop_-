#include <iostream>
#include <iomanip>
using namespace std;

class FamilyMember
{
private:
    string name;
    string surname;
    string patronymic;
    int age;
    char gender;
    string status;
public:
    void input_member_info() {
        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите отчество: ";
        cin >> patronymic;
        cout << "Введите возраст: ";
        cin >> age;
        cout << "Введите пол (М/Ж): ";
        cin >> gender;
        cout << "Введите статус (Студент/Рабочий/Пенсионер): ";
        cin >> status;
    };

    void print_member_info() {
        cout << "Фамилия: " << surname << " Имя: " << name << " Отчество: " << surname
            << " Возраст: " << age << " Пол: " << gender << " Статус: " << status << endl;
    };
};


int main()
{
    setlocale(LC_ALL, "Russian");

    //task1
    FamilyMember dad;
    dad.input_member_info();
    dad.print_member_info();

};
