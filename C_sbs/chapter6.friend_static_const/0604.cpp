#include <iostream>
using namespace std;

// 함수 friend 선언

class Point; // PointOP 멤버 함수에 사용이 됨으로 미리 선언

class Point; // PointOP 멤버 함수에 사용이ㅣ 됨으로 미리 선언

class PointOP
{
private:
    int opcnt;
public:
    PointOP() : opcnt(0)
    {   }

    Point PointAdd(const Point&, const Point&); // Point 클래스의 friend 함수 부분 때문에 미리 선언
    Point PointSub(const Point&, const Point&);
    ~PointOP()
    {
        cout << "Operation times: " << opcnt << endl;
    }
};

class Point
{
private:
    int x;
    int y;
public:
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos)
    {
        //
    }
    // 함수의 friend 선언

    // 이렇듯 클래스의 특정 멤버 함수를 대상으로도 friend 선언이 가능
    friend Point PointOP::PointAdd(const Point&, const Point&); // 다른 클래스의 멤버함수
    friend Point PointOP::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&); // 전역 함수, 선언의 역할도 함
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x + pnt2.x , pnt1.y + pnt2.y); // private 멤버 접근, friend 선언된 함수라서 가능
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x - pnt2.x , pnt1.y - pnt2.y); // private 멤버 접근, friend 선언된 함수라서 가능
}

int main(void)
{
    Point pos1(1,2);
    Point pos2(3,4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1,pos2));
    ShowPointPos(op.PointSub(pos2,pos1));
    return 0;
}

void ShowPointPos(const Point& pos)
{
    // private 멤버 접근
    cout << "x: " << pos.x << ",";
    cout << "y: " << pos.x << endl;
}