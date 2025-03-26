#include <iostream>
#include <string>
using namespace std;

class Auto
{
    string name;
    int price;
public:
    Auto(string a_name, int a_price): name(a_name), price(a_price) {}
    friend void drive(const Auto&);
};

void drive(const Auto& car) {
    cout << car.name << " driven ";
}

int main() {
    Auto mazda("mazda", 220);
    drive(mazda);

    return 0;
}