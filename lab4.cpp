#include <iostream>
#include <random>
using namespace std;

int composition(int *arr, int size) {
    int result = 1;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0) {
            result = result * arr[i];
        };
    }
    return result;
};


int sum_of_first_and_end(int* arr, int size) {
    int sum_without_zero = 0;
    bool flag = false;

    for (int i = 0; i < size; i++) {
        if (flag) {
            if (arr[i] == 0) {
                break;
            };
            sum_without_zero += arr[i];
        };
        if (arr[i] == 0) {
            flag = true;
        };
    };
   return sum_without_zero;
}

typedef int (*PF)(int, int);

void example(PF ptr_func, int* arr, int size) {
    cout << "Вызов функции через указатель" << ptr_func(arr, size) << endl;
}

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
    Student s1 = { "Misha", 23, 8 };
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
    cout << "\n" << "\n" << endl;


    //task 6
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 30);

    int rows = 4;
    int cols = 4;

    int** dynamiс_mas{ new int* [rows] {} };

    for (int i = 0; i < rows; i++) {
        dynamiс_mas[i] = new int[cols] {dist(gen), dist(gen), dist(gen), dist(gen)};
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << dynamiс_mas[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Количество столбцов, содержащих хотя бы один нулевой элемент: ";
    int coutOfNull = 0;
    for (int i = 0; i < cols; i++) {
        bool flag = false;
        for (int j = 0; j < rows; j++) {
            if (dynamiс_mas[j][i] == 0) {
                flag = true;
            }
        }
        if (flag) {
            coutOfNull++;
            flag = false;
        }
    };
    cout << coutOfNull << endl;

    for (int i = 0; i < rows; i++) {
        delete dynamiс_mas[i];
    }
    cout << endl;

    
    //task 7
    const int nums = 7;
    int mas_task7[nums] = { 1, 2, 0, 4, 5, 6, 0 };
    cout << composition(mas_task7, nums) << endl;

    //task 8
    example(sum_of_first_and_end, mas_task7, nums);
    /*Определить функцию, обрабатывающую массив по пункту А) и подпункту 2, передав его в качестве параметра. Объявить указатель на эту функцию и передать 
    его некой другой функции, имеющей один из возможных параметров указатель на первую функцию.*/
    /*2.	сумму элементов массива, расположенных между первым и последним нулевым  элементами;*/

};
