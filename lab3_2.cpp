
// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 4;
    int mas[N][N] = { {1, 1, 3, 4}, {5, 6, 0, 8}, {0, 11, 11, 11}, {13, 14, 15, 16} };

    int composition = 1;

    cout << "Заданный массив: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    };

    cout << "Количество столбцов, содержащих хотя бы один нулевой элемент: ";
    int coutOfNull = 0;
    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (mas[j][i] == 0) {
                flag = true;
            }
        }
        if (flag) {
            coutOfNull++;
            flag = false;
        }
    };
    cout << coutOfNull << endl;


    cout << "Номер строки, в которой находится самая длинная серия одинаковых элементов: ";
    int stroka;
    int max_s = 0;
    for (int i = 0; i < N; i++) {
        int current = 0;
        for (int j = 1; j < N; j++) {
            if (mas[i][j] == mas[i][j - 1]) {
                current++;
            }
        }
        if (current > max_s) {
            max_s = current;
            stroka = i;
        }
        current = 0;
    };
    cout << stroka + 1 << endl;
};
