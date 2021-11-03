#include <iostream>
using namespace std;

// 생성자의 이해
// 1) 클래스의 이름과 동일한 이름의 함수이면서 nd
// 2) 반환형이 선언되지 않았고
// 3) 실제로  반환하지 않는 함수를 가리켜 생성자라고 한다!

class SimpleClass
{
    int num1;
    int num2;

public:
    // 생성자는 객체 생성 시 딱 한번 호출됨. 따라서 멤버 변수의 초기화에 사용할 ㅅ 있다
    // 생성자도 함수의 일종이므로, 오버로딩이 가능하고 디폴트 값 설정이 가능하다.
    SimpleClass()
    {
        num1 = 0;
        num2 = 0;
    }
    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }
    SimpleClass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }
    /*
    // 생성자도 함수의 디폴트 값 설정이 가능하다.
    SimpleClass(int n1 = 0, int n2 = 0)
    {
        num1 = n1;
        num2 =n2;
    }
    */

   void ShowData() const
   {
       cout << num1 << ' ' << num2 << endl;
   }
};

int main(void)
{
    //SimpleClass sc1(); // 다른 의미 -> 함수 선언
    // SimpleClass * ptr1 = new SimpleClass;
    // SimpleClass * ptr1 = new SimpleClass();
    SimpleClass sc1;
    sc1.ShowData();

    SimpleClass sc2(100);
    sc2.ShowData();

    SimpleClass sc3(100,200);
    sc3.ShowData();
    return 0;
}