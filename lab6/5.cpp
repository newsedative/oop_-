#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int age;
    static unsigned count;
    class Schoolarship
    {
    public:
        int stip;
        Schoolarship() { stip = 0; }
        Schoolarship(int s_stip) : stip(s_stip) {}
    };
    Schoolarship stipendiya;
public:
    Student() : name(""), age(0), stipendiya(0) {};
    Student(string s_name, int s_age) {
        name = s_name;
        age = s_age;
        count++;
    }
    Student(string s_name, int s_age, int s_stip) {
        name = s_name;
        age = s_age;
        stipendiya = s_stip;
    }
    void print() {
        cout << name << " " << age << " " << count << " " << stipendiya.stip;
    }
};

unsigned Student::count = 0;

int main() {
    Student dasha("dasha", 20, 111111);
    dasha.print();

    return 0;
}