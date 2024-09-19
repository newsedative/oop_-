// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number_1;
    char char_1;
    wchar_t wchar_1;
    bool bool_1;
    float float_1;
    double double_1;

    cout << "Количество байт для целого типа  int = " << sizeof(number_1) << endl;
    cout << "Количество байт для символьный типа  char = " << sizeof(char_1) << endl;
    cout << "Количество байт для расширенный символьный типа wchar_t = " << sizeof(wchar_1) << endl;
    cout << "Количество байт для логический типа bool = " << sizeof(bool_1) << endl;
    cout << "Количество байт для вещественный типа float = " << sizeof(float_1) << endl;
    cout << "Количество байт для вещественный с двойной точностью типа double = " << sizeof(double_1) << "\n" << endl;


    //структура 

    struct Students
    {
        char Letter;
        int Age;
        float Ball;
    };

    Students s;

    cout << "Количество байт для структуры s = " << sizeof(s) << endl;
    cout << "Количество байт для  символа в структуре = " << sizeof(s.Letter) << endl;
    cout << "Количество байт для возраста в структуре = " << sizeof(s.Age) << endl;
    cout << "Количество байт для балла в структуре = " << sizeof(s.Ball) << "\n" << endl;

    //преобразование

    number_1 = 5;
    cout << "number_1 = 5" << endl;
    cout << "Преобразование int number_1 в тип double: " << double(number_1) << endl;
    cout << "Преобразование int number_1 в тип char: " << char(number_1) << endl;
    cout << "Преобразование int number_1 в тип bool: " << bool(number_1) << "\n" << endl;

    // перечеслимый тип

    enum day { понедльник, вторник, среда };
    enum months { may=5, june=6, july=7 };

    day mn;
    mn = понедльник;
    cout << "присвоить значение переменной mn: " << mn << endl;
    cout << "Количество байт для enum с инициализацией констант: " << sizeof(day) << "\n" << "Количество байт для enum без инициализацией констант: " << sizeof(months) << endl;


    //Задание альтернативного имени

    cout << "\n";

    typedef  unsigned int UINT;
    UINT a = 3;
    cout << "Задание альтернативного имени UINT существующему типу unsigned in оператором typedef. Его размерность: " << sizeof(a) << endl;

    // Механизм определения типа объекта в реальном времени (RTTI)
    cout << "Имя типа = " << typeid(a).name() << endl;
}





// adding

// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()

{
	char char_1 = 'a';
	double new_d = 0;
	
	cout << char_1 + new_d << endl;

	enum Month { понедельник, вторник, среда };

	Month mn;
	mn = понедельник;
	cout << mn << endl;

	typedef enum { Male, Famale } TPol;

	struct Student {
		unsigned short Age;
		TPol pol;
		float Ball;
		
	};
	Student s;
	cout << sizeof(s.pol) << endl;
}



/*
    void calc(int n1, int n2, operations op);

    enum operations {Plus,  Minus, Divide };

    void calc(int n1, int n2, operations op)
    {
        switch (op)
        {
            case operations::Plus:
                return n1 + n2;
            case operations::Minus:
                return n1 - n2;
        }
    }
    cout << calc(1, 2, operations::Plus) << endl; */
