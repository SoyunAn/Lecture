#include <iostream>
using namespace std;

// 복사 생성자가 호출되는 시점
// 1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화 하는 경우
// 2. call-by-value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
// 3. 객체를 반환하되, 참조 형으로 반환하지 않는 경우

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }
    SoSimple& AddNum(int n) // 참조형 반환
    {

        num +=n;
        return *this;
    }
    void ShowData()
    {
        cout << "num: " << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    // 매개 변수 전달 과정에서 복사 생성자 호출
    // 2. Call-by-value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우

    cout << "return 이전" << endl;

    // 3. 객체를 반환하되, 참조형으로 반환하지 않는 경우
    return ob;
}

int main(void)
{
    // SimpleFuncObj에서 반환된 객체를 대상으로 AddNum() 호출, AddNum() 가 반환하는 참조 값을 대상으로 ShoeData() 호출
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    
    obj.ShowData();
    return 0;
}