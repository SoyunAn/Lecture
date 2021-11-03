#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//구조체 변수 선언
struct Sample
{
    int num;
    char name[25];
};

int main()
{
    //구조체 포인터 선언
    struct Sample * data;
    int count =0, i;
    data = (struct Sample*)malloc(sizeof(struct Sample) * 10);

    //구조체에 번호 입력
    printf("번호: ");
    scanf("%d", &data->num);

    //입력된 값이 0이 아니면 반복 수행
    while (data->num != 0)
    {
        //구조체 배열에 이름 입력
        printf("이름: ");
        scanf("%s", (data++)->name);

        //구조체 배열에 번호 입력
        printf("번호: ");
        scanf("%d", &data->num);

        //입력된 데이터 카운트
        count++;
    }
    printf("\n\n");
    //구조체 배열에 저장된 값 출력
    for(i = count; i>0; i--)
    {
        printf("%d:%s \n", (data - i)->num, (data - i)->name);
    }
    //free(data);
    return 0;
}