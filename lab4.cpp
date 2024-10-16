#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //на 32-разрядных платформах размер адресов равен 4 байтам, а на 64-разрядных - 8 байтам

    //task 1
    int num = 12;
    int* ptr_num = &num;
    cout << "Значение указателя ptr_num - " << *ptr_num << ", Адрес указателя - " << ptr_num << endl;

    bool flag = true;
    bool* ptr_flag = &flag;
    cout << "Значение указателя ptr_flag - " << *ptr_flag << ", Адрес указателя - " << ptr_flag << endl;

    float fnum = 0.1;
    float* ptr_fnum = &fnum;
    cout << "Значение указателя ptr_fnum - " << *ptr_fnum << ", Адрес указателя - " << ptr_fnum << endl;


    //task 2
    /*enum days { Monday, Tuesday, Wednesday };
    typedef days* ptr_days = &days;
    cout << *ptr_days << endl;*/


    //task 3
    struct Student
    {
        string Name;
        int Age;
        float Ball;
    };
    Student s1 = {"Misha", 23, 8};
    Student* ptr_student = &s1;
    cout << "Имя: " << ptr_student->Name << " Возраст: " << (*ptr_student).Age << " Балл: " << (*ptr_student).Ball << endl;
    cout << endl;


    //task 4
    int number = 10;
    int* ptr = &number;
    double* doublePtr = (double*)ptr; 
    cout << ptr << ' ' << *doublePtr << endl;
    cout << endl;


    //task 5
    const int N = 20;
    int mas[N] = { 3, 9, -4, 3323, 0, 1, 2, 3, 4, 5, 0, 667, 9, -3, 0, 78, 6, -23, 19, 0 };
    int* begin = mas;
    int* end = mas + N - 1;
    while (begin < end) {
        while (begin < end && *begin >= 0) {
            begin++;
        }
        while (begin < end && *end < 0) {
            end--;
        }
        if (begin < end) {
            std::swap(*begin, *end);
            begin++;
            end--;
        }
    }
    for (int* ptr = mas; ptr <= &mas[N - 1]; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;

};
