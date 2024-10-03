#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //на 32-разрядных платформах размер адресов равен 4 байтам, а на 64-разрядных - 8 байтам

    //task 1
    int num = 12;
    int *ptr_num = &num;
    cout << "Значение указателя ptr_num - " << *ptr_num << ", Адрес указателя - " << ptr_num << endl;

    bool flag = true;
    bool* ptr_flag = &flag;
    cout << "Значение указателя ptr_flag - " << *ptr_flag << ", Адрес указателя - " << ptr_flag << endl;

    float fnum = 0.1;
    float* ptr_fnum = &fnum;
    cout << "Значение указателя ptr_fnum - " << *ptr_fnum << ", Адрес указателя - " << ptr_fnum << endl;


    //task 2
    enum days { Monday, Tuesday, Wednesday };
    typedef days* ptr_days = &days;
    cout << *ptr_days << endl;

    
    //task 3
    struct Student 
    {
        string Name;
        int Age;
        float Ball;
    };
    Student stud = {'Ben', 19, 5};
    Student* ptr_stud = &stud;
};
