// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 20;
    int mas[N] = { 3, 9, -4, 3323, 0, 1, 2, 3, 4, 5, 0, 667, 9, -3, 0, 78, 6, -23, 19, 0 };

    int composition = 1;

    cout << "Заданный массив: ";
    for (int i = 0; i < N; i++) {
        cout << mas[i] << ", ";
        if (i % 2 == 0) {
            composition *= mas[i];
        };
    };
    cout << endl;
    cout << "Произведение: " << composition << endl;

    int sum_without_zero = 0;
    bool flag = false;

    for (int i = 0; i < N; i++) {
        if (flag) {
            if (mas[i] == 0) {
                break;
            };
            sum_without_zero += mas[i];
        };
        if (mas[i] == 0) {
            flag = true;
        };
    };
    cout << endl;
    cout << "Сумма элементов массива, расположенных между первым и последним нулевым элементами: " << sum_without_zero << endl;

    cout << endl;
    cout << "Преобразованый массив: ";

    int startIndex = 0;
    int endIndex = N - 1;

    while (startIndex < endIndex) {
        while (mas[startIndex] > 0 && startIndex < endIndex) {
            startIndex++;
        }
        while (mas[endIndex] <= 0 && startIndex < endIndex) {
            endIndex--;
        }
        if (startIndex < endIndex) {
            swap(mas[startIndex], mas[endIndex]);
            startIndex++;
            endIndex--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << mas[i] << ", ";
    };
    cout << endl;
};
