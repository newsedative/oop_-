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
    void print() {
        cout << "B: " << b << endl;
    }
};

class C : public A
{
    int c;
public:
    C() : c(3), A() {};
    void print() {
        cout << "C: " << c << endl;
    }
};

/*void demo(C& p) {
    B& b = dynamic_cast<B&>(p);
    b.print();
}*/

/*void demo(C* p) {
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(a);
    if (b) b->print();
    else cout << "not work";
}*/

void demo(C& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        B& b = dynamic_cast<B&>(a);
        b.print();
    }
    catch (...) {
        cout << "not work";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    B a_m;
    A& a = a_m;
    demo((C&)a);


    return 0;
}
