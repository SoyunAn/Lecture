#include <iostream>
#include <cstring>
#include "car.h"

using namespace std;


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