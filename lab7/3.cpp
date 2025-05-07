#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


class Device
{
public:
    void turn_on() {
        cout << "Devise on" << endl;
    }
};

class Computer: virtual public Device {};
class Monitor: virtual public Device {};

class Laptop: public Computer, public Monitor {
public:
    /*void turn_on() {
        cout << "Laptop on" << endl;
    }*/
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");


    Laptop my_laptop;
    my_laptop.turn_on();

    return 0;
}
