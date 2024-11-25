
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
using namespace std;

struct result {
	double epowx;
	int n;
};

const int N = 4;

double factorial(int x) {
	double f = 1;
	for (int i = 2; i <= x; ++i)
	{
		f = f * i;
	}
	return f;
}

result calc(float x, float e) {
	int n = 0;
	double res = 0;
	double add = 0;
	do {
		add = pow(-1, n) * pow(x, n) / factorial(n);
		res += add;
		n++;
	} while (abs(add / res) >= e);
	return result{ res, n };
}

result proccess_calc(struct result(*ptr)(float, float), float x, float e) {
	return (*ptr)(x, e);
}

int composition(int* arr, int len) {
	int composition = 1;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ", ";
		if (i % 2 == 0) {
			composition *= arr[i];
		};
	};
	return composition;
}

double composition(double* arr, int len) {
	double composition = 1;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			composition *= arr[i];
		};
	};
	return composition;
}

int count_of_didgit(char s[]) {
	int count = 0;
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			count += 1;
		};
	};
	return count;
}

int col_without_zero(int(*arr)[N]) {
	int coutOfNull = 0;
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == 0) {
				flag = true;
			}
		}
		if (flag) {
			coutOfNull++;
			flag = false;
		}
	};
	return coutOfNull;
}

struct a {
	int a_int;
	char a_char;
	double a_double;
};

void print_struct(struct a s) {
	cout << s.a_int << " " << s.a_char << " " << s.a_double << endl;
}

void sort(int* ptr, int n) {
	if (n == 1)return;
	for (int i = 0; i < n; i++) {
		if (*ptr > *(ptr + 1))
		{
			int tmp = *ptr;
			*ptr = *(ptr + 1);
			*(ptr + 1) = tmp;
		}
		sort(ptr + 1, n - 1);
	}
}

template <typename T>
int countColumnsWithZero(const std::vector<std::vector<T>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	int count = 0;
	for (int j = 0; j < cols; ++j) {
		bool hasZero = false;
		for (int i = 0; i < rows; ++i) {
			if (matrix[i][j] == 0) {
				hasZero = true;
				break;
			}
		}
		if (hasZero) {
			count++;
		}
	}
	return count;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //task 1
	double x_start, x_end, dx, e;

	cout << "Введите знач:";
	cin >> x_start >> x_end >> dx >> e;
	cout << "Вычислить значения от Хнач=" << x_start << " до Xкон=" << x_end << " с шагом=" << dx << endl;
	cout << setw(10) << "x" << setw(10) << "e^(-x)" << setw(10) << "n" << endl;

	while (x_start <= x_end) {
		result a = calc(x_start, e);
		cout << setw(10) << x_start << setw(10) << a.epowx << setw(10) << a.n << endl;
		x_start += dx;
	}

	//task 2
	cout << 2 << endl;
	x_start = 0;
	struct result(*ptr_calc)(float, float) = &calc;
	cout << "Вычислить значения от Хнач=" << x_start << " до Xкон=" << x_end << " с шагом=" << dx << endl;
	cout << setw(10) << "x" << setw(10) << "e^(-x)" << setw(10) << "n" << endl;
	while (x_start <= x_end) {
		result a = proccess_calc(ptr_calc, x_start, e);
		cout << setw(10) << x_start << setw(10) << a.epowx << setw(10) << a.n << endl;
		x_start += dx;
	}

	// task 3
	const int N1 = 20;
	int mas[N1] = { 3, 9, -4, 3323, 2, 1, 2, 3, 4, 5, 8, 667, 9, -3, 4, 78, 6, -23, 19, 9 };
	cout << "Произведение: " << composition(mas, N1) << endl;

	// task 4
	char slovo[] = "What3 is going34 on8!";
	cout << "количество числовых символов: " << count_of_didgit(slovo) << endl;

	// task 5
	int masm[N][N] = { {1, 1, 3, 4}, {5, 6, 0, 8}, {0, 11, 11, 11}, {13, 14, 15, 16} };
	int(*masmPtr)[N] = masm;
	cout << col_without_zero(masmPtr) << endl;

	//task6
	a s_a = { 1, 'a', 8.8 };
	print_struct(s_a);

	//task 7
	const int N = 6;
	int array_to_sort[N] = { 9, 8, 7, 3, 4, 1 };
	sort(array_to_sort, N);
	for (int i = 0; i < N; i++)
		cout << array_to_sort[i] << ' ';
	cout << endl;

	//task 8
	const int N2 = 5;
	double mas2[N2] = { 3.1, 9, -4, 3323.1, 2};
	cout << "Произведение: " << composition(mas2, N2) << endl;

	//task 9
	std::vector<std::vector<int>> intMatrix = {
	{1, 2, 0},
	{4, 0, 6},
	{7, 8, 9}
	};
	int intResult = countColumnsWithZero(intMatrix);
	std::cout << "Количество столбцов с нулями (int): " << intResult << std::endl;


	std::vector<std::vector<double>> doubleMatrix = {
	  {1.1, 2.2, 0.0},
	  {4.4, 0.0, 6.6},
	  {7.7, 8.8, 9.9}
	};
	double result = countColumnsWithZero<double>(doubleMatrix);
	std::cout << "Количество столбцов с нулями (double): " << result << std::endl;

}
