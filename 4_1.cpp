#include <iostream>
using namespace std;

int composition(int* arr, int size) {
    int result = 1;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0) {
            result = result * arr[i];
        };
    }
    return result;
}

typedef int (*PF)(int*, int);
void example(PF ptr_func, int* arr, int size) {
    cout << "Результаn вызова функции через указатель: " << ptr_func(arr, size) << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    //указатель на переменную
    cout << "указатель на переменную" << endl;
    int a = 10;
    int* ptrInt = &a;
    cout << "Адрес:" << ptrInt << " Значение: " << *ptrInt << "\n" << endl;

    //указатель на перечисление
    cout << "указатель на перечисление" << endl;
    enum class Color { RED, BLUE, GREEN };
    Color color = Color::RED;
    const Color* ptrColor = &color;
    switch (*ptrColor) {
        case Color::BLUE:
            cout << "Синий";
            break;
        case Color::RED:
            cout << "Красный";
            break;
        case Color::GREEN:
            cout << "Зеленый";
            break;
    }
    cout << "\n" << endl;

    //указатель на структуру
    cout << "указатель на структуру" << endl;
    struct Man {
        string Name;
        int Age;
    };
    Man man1 = { "Misha", 23 };
    Man* ptrMan = &man1;
    cout << ptrMan->Name << " " << ptrMan->Age << "\n" << endl;

    //преобразование типа указателя
    /*cout << "преобразование типа указателя" << endl;
    char sym = 'f';
    char* ptrChar = &sym;
    int* ptrCharToInt = (int*)ptrChar;
    cout << ptrCharToInt << " " << ptrChar << '\n' << endl;*/

    //обработка массива через указатель
    cout << "обработка массива через указатель" << endl;
    const int N = 6;
    int mas[N] = { 4, -5, 9, -1, 2, 3 };
    int* begin = mas;
    int* end = mas + N - 1;
    while (begin < end) {
        while (begin < end && *begin >= 0) {
            *begin++;
        }
        while (begin < end && *end < 0) {
            *end--;
        }
        if (begin < end) {
            std::swap(*begin, *end);
            *begin++;
            *end--;
        }
    }
    for (int* ptr = mas; ptr <= &mas[N - 1]; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << "\n" << endl;
    
    //new delete


    //одномерный массив как параметр функции
    cout << "одномерный массив как параметр функции" << endl;
    cout << composition(mas, N) << '\n' << endl;

    //указатель на функцию
    example(composition, mas, N);

    //вывод значений объектов через указатель на тип void
    int b = 5;
    int* ptrB = &b;
    void* ptrVoidB = static_cast<void*>(&b);
    cout << *ptrB << " " << *(static_cast<double*>(ptrVoidB)) << endl;
};
