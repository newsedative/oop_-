#include <iostream>
using namespace std;


class Auto
{
    string name;
    int year;
    static unsigned count;
public:
    class Price
    {
    public:
        double price;
        static unsigned count_p;
        void friend set_p(Auto::Price&);
        Price() : price(0) {}
        Price(double p_price) : price(p_price) {}
    };
    Price auto_price;
    Auto() : name(""), year(0) {}
    Auto(string a_name, int a_year) : name(a_name), year(a_year) {
        count++;
    }
    Auto(string a_name, int a_year, double a_price) : name(a_name), year(a_year), auto_price(a_price) {
        count++;
    }
    Auto(const Auto& a) {
        cout << "copy" << endl;
        name = a.name;
        year = a.year;
    }
    Auto(Auto&& a) {
        cout << "move" << endl;
        name = move(a.name);
        year = a.year;
        a.year = 0;
    }
    Auto(const char* a_name) : name(a_name), year(0) 
    { 
        cout << "transfrom" << endl;
        count++; 
    }
    Auto(int a_year) : name("plus"), year(a_year) {}
    void print() {
        cout << name << " " << year << " " << set_counter() << " " << auto_price.price << endl;
    }
    static unsigned set_counter() { return count; }
    Auto operator + (const Auto& a) 
    {
        return Auto( year + a.year );
    }
    bool operator == (const Auto& a)
    {
        return name == a.name;
    }
    Auto operator ++ ()
    {
        return ++year;
    }
    void operator () (const string& newName) {
        name = newName;
    }
};

unsigned Auto::count = 0;

unsigned Auto::Price::count_p = 0;

void set_p(Auto::Price& p) {
    cout << p.price << endl;
}


int main()
{
    Auto mazda("mazda6", 2000, 1023800);
    mazda.print();
    /*set_p(mazda.auto_price);

    Auto mazda6(mazda);
    mazda6.print();

    Auto movedm(move(mazda));
    movedm.print();

    Auto toyot = "Toyota";
    toyot.print();*/

    Auto nisan("nisan", 2111, 122222);

    ++nisan;
    nisan.print();
    nisan("lada");
    nisan.print();


    Auto plus = mazda + nisan;
    plus.print();

    bool sravn = mazda == nisan;
    cout << sravn << endl;

    Auto mazda6(mazda);
    bool sravn1 = mazda == mazda6;
    cout << sravn1 << endl;



    

    return 0;
}
