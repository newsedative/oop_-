#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


class A
{
protected:
    int a;
public:
    A() : a(1) {};
    virtual void print() {};
};

class B : public A
{
protected:
    int b;
public:
    B() : b(2), A() {};
    void print1() {
        cout << "B: " << a << endl;
    }
};

class C : public A
{
    int c;
public:
    C() : c(3), A() {};
    void print2() {
        cout << "C: " << a << endl;
    }
};

/*void demo(C& p) {
    B& b = dynamic_cast<B&>(p);
    b.print();
}*/

void demo(C* p) {
    B* b = dynamic_cast<B*>(p);
    if (b) b->print1();
    else cout << "not work";
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");


    A* a = new B;
    demo(*a);
    

    return 0;
}
