#include <stdio.h>

int main()
{
    int i, * p, arr[] = { 5,10,15,20,25 };
    int ptr;

    printf("arr[0] is %d. \n", arr[0]); //arr[0] is 5.
    printf("*arr is %d. \n", *arr);  //* arr is 5.

    p =arr;
    for(i = 0; i<5; i++)
        printf("%d\t %p\t ", *(p+i), p); // 5     10      15      20      25
    printf("\n");

    p = arr;
    for (i=0; i<5; i++)
        printf("%d\t %p\t", *p++,p); // 5    10      15      20      25
    printf("\n");

    p = arr;
    for (i=0; i<5; i++)
        printf("%d\t %p\t", (*p)++, p); // 5    6    7     8     9
    printf("\n");

    return 0;

}