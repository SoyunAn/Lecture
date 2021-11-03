#include <iostream>
#include <cstring>
using namespace std;

// 클래스의 friend 선언
// friend 선언은 private 멤버의 접근을 허용하는 선언이다.
// friend 선언은 정보 은닉에 반하는 선언이기 때문에 매우 제한적으로 선언되어야 한다.

class Girl;

class Boy
{
private:
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len)
    { }
    void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
    char phNum[20];
public:
    Girl(const char* num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy& frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
    cout << "His height:  " << frn.height << endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1234-5678");

    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return 0;
}