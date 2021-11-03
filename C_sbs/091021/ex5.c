#include <stdio.h>

typedef struct People
{
    char name[12];
    unsigned short int age;
    float height;
    float weight;
    /* data */
} Person;

int main()
{
    Person data;

    printf("대상자의 정보를 입력하세요\n");
    printf("이름 : ");
    scanf("%s", data.name);
    printf("나이: ");
    //%u 라고 적으면 unsigned int 형으로 처리되기 때문에 unsighned short int 형으로 입력받으려면 %hu 사용
    scanf("%hu", &data.age);
    printf("키: ");
    scanf("%f", &data.height);
    printf("몸무게: ");
    scanf("%f", &data.weight);

    printf("\n 입력한 정보는 다음과 같습니다. \n");
    //키와 몸무게는 소수점 첫째 자리까지만 보여주기위해서 %.1f 형식으로 출력
    printf("%s: %d세, %1fcm, %.1fkg\n", data.name, data.age, data.height, data.weight);


}
