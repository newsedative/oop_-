#include <iostream>
using namespace std;

class Test
{
public:
    int test; 

    Test() : test(0) {} 
    Test(int tst) : test(tst) {} 

    friend Test& operator++(Test& tst);

    friend Test operator++(Test& tst, int);

    void Out()
    {
        cout << " Test: " << test << endl;
    }
};

Test& operator++(Test& tst)
{
    ++tst.test;
    return tst;
}

Test operator++(Test& tst, int)
{
    Test temp = tst;
    ++tst.test; 
    return temp; 
}

int main()
{
    Test tst(200);

    ++tst;
    tst.Out(); 

    tst++;
    tst.Out(); 

    return 0;
}
