#include <iostream>
#include <iomanip>
using namespace std;

// task 5
class Number {
private:
    const int constValue;  
    int& refValue;          
    int normalValue;        

public:
    Number(int cv, int& rv, int nv) : constValue(cv), refValue(rv), normalValue(nv) {
        normalValue = nv; 
    }

    void printValues() const {
        cout << "constValue: " << constValue << ", refValue: " << refValue << ", normalValue: " << normalValue << endl;
    }
};

int main() {
    int value = 42;
    Number num(10, value, 100);
    num.printValues();

    return 0;
}
