#include <iostream>
using namespace std;

//task 6
class Float {
private:
    float value;

public:
    Float() : value(0.0f) {}
    Float(float val) : value(val) {}

    float getValue() const {
        return value;
    }

    void setValue(float val) {
        value = val;
    }
};

class Complex {
private:
    Float Re;
    Float Im;

public:
    Complex(float re, float im) : Re(re), Im(im) {}
    //task 7
    Complex(const Complex& c)
    {
        cout << "Конструктор копирования" << endl;
        Re = c.Re;
        Im = c.Im;
    }
    //task 9
    explicit Complex(float re)
    {
        cout << "Конструктор с одним аргументом с запретом преобразований" << endl;
        Re = re;
        Im = 0.0f;
    }
    //task 10
    Complex& add(const Complex& other) {
        cout << "Сложение двух объектов" << endl;
        Re.setValue(Re.getValue() + other.Re.getValue());
        Im.setValue(Im.getValue() + other.Im.getValue());
        return *this; 
    }
    void print() const {
        cout << "Re: " << Re.getValue() << ", Im: " << Im.getValue() << endl;
    }
};

//task 8
Complex createComplex(float re, float im) { return Complex(re, im); };

int main() {
    setlocale(LC_ALL, "Russian");

    Complex c(3.5f, 2.7f);
    c.print();

    //task 7
    Complex c1(c);
    c1.print();

    //task 8
    Complex c2 = createComplex(1.5f, 1.7f);
    c2.print();

    //task 9
    Complex c3(1.0f);
    c3.print();

    //task 10
    c2.add(c1).print();


    return 0;
}
