#ifndef __CAR_H__
#define __CAR_H__

// C++에서의 파일 분할
// 클래스의 선언은 일반적으로 헤더 파일에 삽입한다
// 객체 생성문 및 멤버의 접근 문장을 컴파일 하기위해서 필요
// 클래스의 이름을 따서 Car.h 로 헤더 파일의 이름을 정의 하기도 한다

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

class Car
{
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

#endif