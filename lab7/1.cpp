#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Word
{
protected:
    string word;
public:
    static int counter;
    Word() : word("") {
        ++counter;
        cout << "Конструктор по умолчанияю Word" << endl;
    };
    Word(string w_word) : word(w_word) {
        cout << "Конструктор с параметром Word" << endl;
    };
    ~Word() {
        cout << "Деструктор Word" << endl;
    }
    void print() {
        cout << word << " " << counter << endl;
    }
    friend ostream& operator <<(ostream&, const Word&);
};

int Word::counter = 1;
ostream& operator <<(ostream&out, const Word& wtf) {
    out << "Word: " << wtf.word << endl;
    return out;
}

class Stroka: public Word
{
    int len_str;
public:
    Stroka() : Word(""), len_str(0) {
        cout << "Конструктор по умолчанияю Stroka" << endl;
    };
    Stroka(string s, int s_len) : Word(s), len_str(s_len) {
        cout << "Конструктор с параметром Stroka" << endl;
    };
    ~Stroka() {
        cout << "Деструктор Stroka" << endl;
    }
    void print() {
        cout << len_str << endl;
    }
    friend ostream& operator <<(ostream&, const Stroka&);
};
ostream& operator <<(ostream& out, const Stroka& wtf1) {
    out << "Stroka: " << wtf1.word << endl;
    return out;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    Word a("Hello");
    Stroka b("Hello world", 2);

    a.print();
    b.print();

    cout << a;
    cout << b;

    return 0;
}
