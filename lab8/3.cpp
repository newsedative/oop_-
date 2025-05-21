#include <iostream>
using namespace std;

template<typename T> class A {
public:
    T name;
    A() : name("dasha") {};
    A(T a_name) : name(a_name) {};
    template<class T> friend ostream& operator<< <>(ostream& os, const A<T>);
};

template<class T> ostream & operator <<(ostream & os, const A<T> a) {
    os << a.name;
    return os;
}

template <template<class>class A, typename T> class B {
public:
    A<T> a_t;
    T b_1;
    B() : a_t(1) {};
    B(T b_base) : a_t(b_base) {};
    
    void print() {
        cout << "Base " << a_t << endl;
    }
    template<class T> friend ostream& operator<< <>(ostream& os, const B<A, T>);
};

template<class T> ostream& operator<<(ostream& os, const B<A, T> p) {
    os << p.a_t;
    return os;
}

int main()
{
    /*B<int> b_b(10);
    b_b.print();*/

    //A<string> b_a("werty");
    B<A, string> b_a1("rswr");
    //B<A, int> b_a2(12, 122);
    cout << b_a1;


    return 0;
}
