#include <iostream>
#include <cstring>
using namespace std;

// 클래스와 구조체의 유일한 차이점
// enum 상수 선언
namespace CAR_CONST
{
    enum
    {
        ID_LEN  =20,
        MAX_SPD =200,
        FUEL_STEP  =2,
        ACC_STEP   =10,
        BRK_STEP   =10,

    };
}

// 키워드 struct를 대신해서 clas 사용한 것이 유일한 외형적 차이점
// 단순히 키워드만 class로 바꾸면 선언된 멤버의 접근이 불가능ㄹ
// 따라서 별도의 접근 제어와 관련된 선언을 추가ㅎ해야한다

class Car
{
    // 접근 제어 지시자
    // public: 어디서든 접근 허용
    // protected 상속관계에 놓여있을 때 유도 클래스에서의 접근 허용
    // private 클래스 내 (클래스 내에 정의된 함수) 에서만 접근 하용
    private:
        char gamerID[CAR_CONST::ID_LEN]; // 소유자 ID
        int fuelGauge;  // 연료량
        int curSpeed;   // 현재 속도
    public:
        void InitMembers(const char * ID, int fuel);
        void ShowCarState() ;  // 여기서 car 관련된 것 선언
        void Accel();
        void Break();

};
    void Car::InitMembers(const char * ID, int fuel)
    {
        strcpy(gamerID, ID);
        fuelGauge = fuel;
        curSpeed = 0;
    };
    void Car::ShowCarState()    //Car:: 붙여서 가져오기
    {
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%"<< endl;
    cout << "현재 속도: " << curSpeed << "km/s"<< endl << endl;
    }
    void Car::Accel()
    {
        if(fuelGauge <= 0) // 연료 없는 경우
             return;
        else    
             fuelGauge -= CAR_CONST::FUEL_STEP;

        if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
        {
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }

        curSpeed += CAR_CONST::ACC_STEP; // 현재 속도에 10 증가
    }
    void Car::Break()
    {
        if(curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;   // 현재 속도에서 10 감소
    }


int main(void)
{
    // struct 생략 가능
    Car run99;
    run99.InitMembers("run99",100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    
    return 0;    
}