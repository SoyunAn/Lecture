#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
    Simple() // 생성자
    {
        cout << "I'm simple constructor!" << endl;
    }
};

int main(void)
{
    cout << "case 1 : ";
    Simple * sp1 = new Simple; // 생성자 실행이 안된다.

    cout << "case 2 : ";
    Simple * sp2 = (Simple*)malloc(sizeof(Simple) * 1); // 생성자 실행이 안된다/

    cout << endl << "end of main" << endl;
    delete sp1;
    free(sp2);
    return 0;
}
