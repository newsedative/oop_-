#include <iostream>
#include <iomanip>

using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	struct Students {
		char name[20];
		int age;
		void print() {
			cout << name << " " << age << endl;
		};
	};

	Students Dasha{ "Dasha", 19};
	Students Sasha{ "Sasha", 19};

	Students stud[]{ Dasha, Sasha };

	stud[0].print();

}
