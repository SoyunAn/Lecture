#include <iostream>
using namespace std;

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

struct Car
{
    char gamerID[CAR_CONST::ID_LEN]; // 소유자 ID
    int fuelGauge;  // 연료량
    int curSpeed;   // 현재 속도

    // 함께 선언된 변수에는 직접 접근이 가능하다. -> 매개 변수가 필요 없음

    void ShowCarState()
    {
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%"<< endl;
    cout << "현재 속도: " << curSpeed << "km/s"<< endl << endl;
    }
    void Accel()
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
    void Break()
    {
        if(curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;   // 현재 속도에서 10 감소
    }
};

int main(void)
{
    // struct 생략 가능
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    

    Car run77 = {"run77", 100, 0};
    run77.Accel();
    run77.ShowCarState();
    run77.Break();
    run77.ShowCarState();

    return 0;    
}