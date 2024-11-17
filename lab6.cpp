#include <iostream>
using namespace std;

class FamilyMember {
public:
    string surname;
    string name;
    string patronymic;
    int age;
    string status;
    void print() {
        cout << "ФИО: " << surname << " " << name << " " << patronymic << endl;
        cout << "Возраст: " << age << endl;
        cout << "Статус: " << status << endl;
    }
};

void print_all_members() {
    class FamilyMember {
    public:
        string surname;
        string name;
        string patronymic;
        int age;
        string status;
        void print() {
            cout << "ФИО: " << surname << " " << name << " " << patronymic << endl;
            cout << "Возраст: " << age << endl;
            cout << "Статус: " << status << endl;
        }
        class FamilyMemberLocal {
        public: 
            double profit;
            void print_profit() {
                cout << "Доход: " << profit << endl;
            }
        };
    };

    FamilyMember mom;
    mom.surname = "Савельева";
    mom.name = "Любовь";
    mom.patronymic = "Ивановна";
    mom.age = 50;
    mom.status = "рабочий";
    mom.profit = 12121212;
    mom.print();
    mom.print_profit();
}


int main()
{
    setlocale(LC_ALL, "Russian");

    //task 1
    FamilyMember mom;
    mom.surname = "Иванова";
    mom.name = "Любовь";
    mom.patronymic = "Ивановна";
    mom.age = 50;
    mom.status = "рабочий";
    mom.print();

    // task 2
    print_all_members();
}
