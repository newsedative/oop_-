#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

/*class Human
{
protected:
    string name;
    string surname;
    int age;
public:
    Human() : name(""), surname(""), age(0) {};
    Human(string h_name, string h_surname, int h_age) : name(h_name), surname(h_surname), age(h_age) {};
    void print() {
        cout << "Human: " << name << " " << surname << " " << age << endl;
    }
};*/

class Human
{
protected:
    string name;
    string surname;
    int age;
public:
    Human() : name(""), surname(""), age(0) {
        cout << "dfasfg";
    };
    Human(string h_name, string h_surname, int h_age) : name(h_name), surname(h_surname), age(h_age) {
        cout << "dfasfg";
    };
    virtual void print() =0;
};

class Employee: public Human
{
protected:
    string specialization;
public:
    Employee() : specialization(""), Human() {};
    Employee(string e_specialization, string e_name, string e_surname, int e_age) : specialization(e_specialization), Human(e_name, e_surname, e_age) {};
    void print() override {
        cout << "Employee: " << specialization << " " << name << " " << surname << " " << age << endl;
    }
};

class Student : public Employee
{
    string group;
    float medium_ball;
public:
    Student() : group(""), medium_ball(0.0), Employee() {};
    Student(string s_group, float s_medium_ball, string s_name, string s_surname, int s_age) :
        group(s_group), medium_ball(s_medium_ball), Employee("", s_name, s_surname, s_age) {};
    Student(string s_group, float s_medium_ball, string s_specialization, string s_name, string s_surname, int s_age) :
        group(s_group), medium_ball(s_medium_ball), Employee(s_specialization, s_name, s_surname, s_age) {};
    void print() override {
        cout << "Student: " << group << " " << medium_ball << " " << specialization << " " << name << " " << surname << " " << age << endl;
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");


    Student dasha1("IVT", 4.7, "programming", "name1", "surname1", 10);
    dasha1.print();

    //преобразование
    Employee* d = new Employee("software", "Ivan", "Ivanov", 22);
    Student* s = static_cast<Student *> (d);
    s->print();

    Student* stud = new Student("ivt", 4.4, "name2", "surname2", 5);
    Employee* stud1 = dynamic_cast<Employee*>(stud);
    stud1->print();



    return 0;
}
