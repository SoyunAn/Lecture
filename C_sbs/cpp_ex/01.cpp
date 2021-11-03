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
};

void ShowCarState(const Car &car)
{
    cout << "소유자ID: " << car.gamerID << endl;
    cout << "연료량: " << car.fuelGauge << "%"<< endl;
    cout << "현재 속도: " << car.curSpeed << "km/s"<< endl << endl;
}

void Accel(Car &car)
{
    if(car.fuelGauge <= 0) // 연료 없는 경우
        return;
    else    
        car.fuelGauge -= FUEL_STEP;

        if(car.curSpeed + ACC_STEP >= MAX_SPD)
        {
            car.curSpeed = MAX_SPD;
            return;
        }

        car.curSpeed += ACC_STEP; // 현재 속도에 10 증가
    
}

void Break(Car &car)
{
    if(car.curSpeed < BRK_STEP)
    {
        car.curSpeed = 0;
        return;
    }

    car.curSpeed -= BRK_STEP;   // 현재 속도에서 10 감소
}

int main(void)
{
    // struct 생략 가능
    Car run99 = {"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    // 소유자ID: run99
    // 연료량: 96%
    // 현재 속도: 20km/s
    Break(run99);
    ShowCarState(run99);

    Car run77 = {"run77", 100, 0};
    Accel(run77);
    ShowCarState(run77);

    Break(run77);
    ShowCarState(run77);

    return 0;
}