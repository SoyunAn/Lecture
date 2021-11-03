#include <iostream>
using namespace std;

// 이니셜라이저를 이용한 변수 및 상수의 초기화
// 이니셜라이저는 선언과 동시에 초기화된다

class FruitSeller // 과일 장수
{
    const int APPLE_PRICE; // 사과 가격 - 상수가 들어가면 
    int myMoney; // 판매수익
    int numOfApples; // 가지고 있는 사과 갯수

public:
    FruitSeller(int price, int num, int money)
        :APPLE_PRICE(price), numOfApples(num), myMoney(money) // - 이니셜라이즈로 넣어야 됨
    {
     //   APPLE_PRICE = price;
     //   numOfApples = num;
     //   myMoney = money;
    }
    int SaleApples(int money) // 사과 판매
    {
        int num = money/APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult()
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer // 나 
{
    int myMoney;        // private: // 지갑에 있는 돈
    int numOfApples;    // private:

public:
    FruitBuyer(int money)
        :myMoney(money), numOfApples(0)
    {

    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SaleApples(money); // seller 의 맴버 변수 호출
        myMoney -= money;
    }
    void ShowBuyResult()
    {
        cout<<"현재 잔액: " << myMoney << endl;
        cout<<"사과 개수: "<<numOfApples<<endl<<endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0); // 사과 가격, 가지고 있는 사과 갯수, 판매수익
    //seller.numOfApples = -10;

    FruitBuyer buyer(5000); // 현재 잔액
    buyer.BuyApples(seller, 2000);

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();
    return 0;
}