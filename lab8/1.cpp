#include <iostream>
using namespace std;

template <typename T> class Base {
public:
    T base;
    Base(T b_base) : base(b_base) {};
    void print() {
        cout << "Base " << base << endl;
    }
};

template <typename T> class C : public Base<T> {
public:
    T c;
    C(T c_case, T b_base) : c(c_case), Base<T>(b_base) {};
    void print() {
        cout << "Case " << c << endl;
    }
};

template <typename T> class D : public Base<T> {
public:
    D(T d_d, T b_base) : d(d_d), Base<T>(b_base) {};
    void print() {
        cout << "Dase " << d << endl;
    }
private:
    T d;
};

int main()
{
    Base<int> base_class(10);
    base_class.print();

  
    C<int>* c_c = new C<int>(4, 5);
    Base<int>* b_b = dynamic_cast<Base<int>*>(c_c);

    b_b->print();

    return 0;
}
