#include <iostream>
#include <iomanip>

using namespace std;

struct result {
	double epowx;
	int n;
};


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


void main() {
	double x_start, x_end, dx, e;
	cin >> x_start >> x_end >> dx >> e;
	cout << "Calculating e^(-x) from " << x_start << " to " << x_end << " with step " << dx << endl;
	cout << setw(10) << "x" << setw(10) << "e^(-x)" << setw(10) << "n" << endl;
	while (x_start <= x_end) {
		result a = calc(x_start, e);
		cout << setw(10) << x_start << setw(10) << a.epowx << setw(10) << a.n << endl;
		x_start += dx;
	}
}
