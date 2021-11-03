#include <iostream>
using namespace std;

// C++에서의 구조체 변수 선언
// C++에서는 구조체 변수 선언 시, struct 키워드의 생략을 위한 typedef 선언이 불필요하다.
// 데이터 뿐만 아니라, 해당 데이터와 연관된 함수 모임들도 함께 그룹을 형성하기 때문에 
// 함수도 하나로 묶는 것에 대해 나름의 가치를 부여할 수 있다.

#define ID_LEN  20
#define MAX_SPD 200
#define FUEL_STEP  2
#define ACC_STEP   10
#define BRK_STEP   10

struct Car
{
    char gamerID[ID_LEN]; // 소유자 ID
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
             fuelGauge -= FUEL_STEP;

        if(curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP; // 현재 속도에 10 증가
    }
    void Break()
    {
        if(curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;   // 현재 속도에서 10 감소
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