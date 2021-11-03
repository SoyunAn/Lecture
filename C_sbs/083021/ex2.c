#include <stdio.h>

//재귀함수

int Recursive(int num)
{
    if (num<=0)
        return;

    printf("Recursive call! %d \n", num);
    Recursive(num-1);
}

int main()
{
    Recursive(3);
    //Recursive call!3
    //Recursive call!2
    //Recursive call!1
    return 0;
}
//에러뜸..