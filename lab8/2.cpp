#include <iostream>
using namespace std;

template <typename T> class B {
public:
    T b;
    B() : b(1) {};
    B(T b_base) : b(b_base) {};
    virtual void print() {
        cout << "Base " << b << endl;
    }
};

template <typename T> class C : public B<T> {
public:
    T c;
    C() :c(2) {};
    C(T c_case, T b_base) : c(c_case), B<T>(b_base) {};
    void print() {
        cout << "Case " << c << endl;
    }
};

template <typename T> class D : public B<T> {
public:
    D() : d(3) {};
    D(T d_d, T b_base) : d(d_d), B<T>(b_base) {};
    void print() {
        cout << "Dase " << d << endl;
    }
private:
    T d;
};

void demo(D<int>& p) {
    try {
        B<int>& bb = dynamic_cast<B<int>&>(p);
        C<int>& cc = dynamic_cast<C<int>&>(bb);
        cc.print();
    }
    catch(...) {
        cout << "not";
    }
}

int main()
{
    C<int> c_c;
    B<int>& b_b = c_c;
    
    //demo((D<int>&) b_b);
    try {
        B<int>& bb = dynamic_cast<B<int>&>((D<int>&) b_b);
        C<int>& cc = dynamic_cast<C<int>&>(bb);
        cc.print();
    }
    catch (...) {
        cout << "not";
    }
        

    return 0;
}
