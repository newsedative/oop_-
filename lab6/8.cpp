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
    
    // Перегрузка оператора вызова функции
    void operator()(const string& newName) {
        cout << "Renaming car from " << name << " to " << newName << endl;
        name = newName;
    }
    
    // Дополнительная перегрузка для изменения цены
    void operator()(int newPrice) {
        cout << "Changing price from " << price << " to " << newPrice << endl;
        price = newPrice;
    }
    
    // Перегрузка для изменения и имени и цены
    void operator()(const string& newName, int newPrice) {
        cout << "Renaming car and changing price (" 
             << name << " " << price << ") to (" 
             << newName << " " << newPrice << ")" << endl;
        name = newName;
        price = newPrice;
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
    
    Auto mazda6(mazda);
    mazda6.print();

    Auto movedMazda(mazda);

    Auto plus = mazda + mazda6;
    plus.print();

    // Использование перегруженного оператора ()
    mazda("Toyota");      // Изменяем имя
    mazda.print();
    
    mazda(350);           // Изменяем цену
    mazda.print();
    
    mazda("Honda", 400);  // Изменяем и имя и цену
    mazda.print();

    return 0;
}