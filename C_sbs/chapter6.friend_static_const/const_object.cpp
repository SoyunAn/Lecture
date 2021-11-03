#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    //const로 선언된 객체를 대상으로는 const 선언 되지 않는 멤버 함수의 호출이 불가능하다
    void ShowData() const
    {
        cout << "num: " << num << endl;
    }
};

int main(void)
{
    // const 로 선언된 객체
    const SoSimple obj(7);

    obj.ShowData();

    // const 로 선언된 객체를 대상으로는 const로 선언된 멤버함수 만 호출이 가능
    return 0;
}