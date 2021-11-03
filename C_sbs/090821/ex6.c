#include <stdio.h>
#include <stdlib.h> /* malloc, free 함수 쓰기 위해서 */

int main()
{
    int* p_num_list, count = 0, sum = 0, limit = 0, i;

    printf("사용할 최대 개수를 입력하세요 : ");
    scanf("%d", &limit);

    p_num_list = (int*)malloc(sizeof(int)*limit);

    while (count < limit)
    {
        printf("숫자를 입력하세요 (9999를 누르면 종료) : ");
        scanf("%d", p_num_list + count);
        if (*(p_num_list + count)==9999 )
            break;  
        count++;    /*입력된 횟수 계산*/
    }
    //입력된 횟수 계산
    for (i = 0; i< count; i++)
    {
        if (i>0) printf(" + ");     //숫자와 숫자 사이에 + 를 출력
        printf("%d", *(p_num_list + i));    //입력한 숫자 출력
        sum =sum + *(p_num_list);   //입력한 숫자들을 합산함
    }
    printf(" = %d\n", sum);  //합산 값을 출력
    free(p_num_list);   //사용했던 메모리를 제거
}