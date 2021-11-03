#include <iostream>
using namespace std;

// 반환할 때 만들어진 객체의 소멸 시점

// 임시 객체를 다음 행으로 넘어가면 바로 소멸된다
// 참조자에 참조되는 임시 객체는 바로 소멸되지 않는다

class Temporary
{
private:
    int num;
public:
    Temporary(int n) : num(n)
    {
        cout << "create obj: " << num << endl;
    }
    Temporary()
    {
        cout << "destroy obj: " << num << endl;
    }
    void ShowTempoInfo() const
    {
        cout << "My num is " << num << endl;
    }
};

int main(void)
{
    Temporary(100);
    cout << "********* after make!" << endl << endl;

    Temporary(200).ShowTempoInfo();
    cout << "********* after make!" << endl << endl;

    const Temporary& ref = Temporary(300);
    ref.ShowTempoInfo();
    cout << "********* after make!" << endl << endl;
    return 0;

}