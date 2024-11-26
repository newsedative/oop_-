#include <iostream>
using namespace std;


struct Stud
{
    string name;
    int age;
    Stud(int s)
    {
        age = s;
    }
    Stud(string s1, int s)
    {
        name = s1;
        age = s;
    }

    Stud operator + (const Stud& b)
    {
        return Stud{ age + b.age };
    };
    friend ostream& operator <<(ostream& os, const Stud& c) {
        os << "Name:" << c.name << " Age:" << c.age << endl;
        return os;
    };
    //friend ostream& operator << (ostream&, const Stud&);
};



template <typename T> T sum_2(T a, T b) {
    return a + b;
}

/*void print_stud(Stud s) {
    cout << s.age << " " << s.name << endl;
}*/

int main()
{
    setlocale(LC_ALL, "Russian");

    int b = 7;
    int a = 8;
    //cout << sum(1, 2) << endl;
    //cout << sum(&a, &b) << endl;
    //cout << sum(&a, &b, 3) << endl;

    Stud s1 = { "name", 21 };
    Stud s2 = { "name", 22 };

    cout << sum_2<Stud>(s1, s2) << endl;

    //Stud s = { "name", 21 };
    //print_stud(s);
};
