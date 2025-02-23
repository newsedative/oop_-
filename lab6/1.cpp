#include <iostream>
#include <iomanip>
using namespace std;

// task 1
class FamilyMember
{
private:
    string name;
    string surname;
    string patronymic;
    int age;
    char gender;
    string status;
    class Salary
    {
    public:
        // task 2
        double income;
        Salary() : income(0) {}
        Salary(double s_income)
        {
            income = s_income;
        };
        void input_salary() {
            cout << "Введите зарплату: ";
            cin >> income;
        }
    };
    Salary salary;
public:
    FamilyMember() : name(""), surname(""), patronymic(""), age(0), gender(' '), status(""), salary(0) {};
    // task 2, 3
    FamilyMember(string f_name, string f_surname, string f_patronymic, int f_age, char f_gender, string f_status, double f_salary)
        : name(f_name), surname(f_surname), patronymic(f_patronymic), age(f_age), gender(f_gender), status(f_status), salary(f_salary) {}
    // task 4
    FamilyMember(string f_name, string f_surname, int f_age)
        : name(f_name), surname(f_surname), patronymic(""), age(f_age), gender(' '), status(""), salary(0) {}
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
        salary.input_salary();
    };

    void print_member_info() const
    {
        cout << "\n" << "Вывод информации: " << "\n"
            << "Фамилия: " << surname << "\n"
            << "Имя: " << name << "\n"
            << "Отчество: " << surname << "\n"
            << "Возраст: " << age << "\n"
            << "Пол: " << gender << "\n"
            << "Статус: " << status << "\n"
            << "Зарплата: " << salary.income << endl;
    };
};


int main()
{
    setlocale(LC_ALL, "Russian");

    //task1
    FamilyMember dad;
    dad.input_member_info();
    dad.print_member_info();


    //task 3
    const FamilyMember mom = { "Inna", "Ivanova", "Ivanovna", 47, 'W', "Worker", 122222 };
    mom.print_member_info();

    //task 4
    FamilyMember son("Misha", "Mishin", 18);
    son.print_member_info();

};
