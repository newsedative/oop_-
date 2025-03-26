#include <iostream>
#include <string>
using namespace std;

class Auto;

class Person
{
    string name;
public:
    Person(string p_name): name(p_name) {}
    void drive(const Auto&);
};

class Auto
{
    friend void Person::drive(const Auto&);
private:
    string name;
    int price;
public:
    Auto(int a_price): name("none"), price(a_price) {}
    Auto(string a_name, int a_price): name(a_name), price(a_price) {}
    Auto(const Auto& a) {
        cout << "constr of copy" << endl;
        name = a.name;
        price = a.price;
    }
    //delete
    //Auto(const Auto& a) = delete;
    Auto(Auto&& a) {
        cout << "constr of move" << endl;
        name = move(a.name);
        price = a.price;
        a.price = 0;
    }
    Auto operator + (const Auto& a) 
    {
        return Auto(price + a.price);
    }
    void print() {
        cout << name << " " << price << endl;
    }
};

void Person::drive(const Auto& car) {
    cout << name << " drive " << car.name << endl;
}

int main() {
    Auto mazda("mazda", 220);
    Person dasha("dasha");
    //dasha.drive(mazda);

    Auto mazda6(mazda);
    mazda6.print();

    Auto movedMazda(mazda);

    Auto plus = mazda + mazda6;
    plus.print();

    return 0;
}