#include <iostream>
#include "point.h"
using namespace std;

// 함수만 한번 잘 정의되면 잘못된 접근은 원천적으로 차단된다
// 하지만 정보은닉을 하지 않는다면, 접근할 때마다 주의해야 한다

// 데이터의 조건 
// Point : x, y 좌표의 범위는 0이상 100이하.

Point::Point(const int& xpos, const int& ypos)
{
    if ((0 > xpos || xpos > 100) || (0 > ypos || ypos > 100))
    {
        cout << "벗어난 범위의 값 전달" << endl;
       // return false;
    }

    x = xpos;
    y = ypos;
}

// const 함수 내에서는 동일 클래스에 선언된 멤버변수의 값을 변경하지 못한다!
// const 함수는 const가 아닌 함수를 호출하지 못한다! 간접적인 멤버의 변경 가능성까지 완전히 차단!
int Point::GetX() const { 
    return x; 
}
int Point::GetY() const { 
    return y; 
}


bool Point::SetX(int xpos)
{
    // 범위를 벗어난 값 저장을 원천적으로 막고 있다
    if (0 > xpos || xpos > 100) 
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    x = xpos;
    return true;
}
bool Point::SetY(int ypos)
{
    if (0 > ypos || ypos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    y = ypos;
    return true;
}