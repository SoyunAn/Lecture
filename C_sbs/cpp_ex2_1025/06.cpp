#include <iostream>
using namespace std;

class SimplClass
{
    int num1;
    int num2;

public:
    SimplClass(int n1 = 0, int n2 = 0)
    {
        num1 = n1;  
        num2 = n2;  
    }

    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void)
{
    SimplClass sc1();

    SimplClass mysc = sc1();
    mysc.ShowData();
    return 0;
}

SimplClass sc1()
{
    SimplClass sc(20,30);
    return sc;
}