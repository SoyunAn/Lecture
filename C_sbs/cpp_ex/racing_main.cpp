#include "car.h"

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