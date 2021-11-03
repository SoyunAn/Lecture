#include <iostream>
using namespace std;

// static
// 전역 변수에 선언된 static의 의미 -> 선언된 파일 내에서만 참조를 혀용하겠다는 의미
// 함수 내에 선언된 static의 의미 -> 한번만 초기화 되고,
// 지역 변수와는 달리 함수를 빠져 나가도 소멸 되지 않는다.

void Counter()
{
    static int cnt;
    cnt++;
    cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
    for (int i=0; i < 10; i++)
    {
        Counter();
    }
    return 0;
}