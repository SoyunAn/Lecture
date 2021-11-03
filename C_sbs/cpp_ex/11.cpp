#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

// new & delete

char * MakeStrAdr(int len)
{
    // malloc 대신하는 메오리 동적 할당 방법!
    // 크기를 바이트 단위로 계산하는 일을 거치지 않아도 된다
  //  char * str = (char*)malloc(sizeof(char)*len);
    char * str = new char[len];
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy");
    cout << str << endl;

    // free  대신하는 메모리 해제 방법!
    // new 연산자로 할당 된 메모리 공간은 반드시 delete 함수 호출을 통해서 소멸해야 한다.
    // free(str);

    delete []str; // 배열이 소멸
    return 0;
}