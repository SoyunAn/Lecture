#include <stdio.h>
//구조체 StructData 형으로 성적, 등급, 성별 선언
struct StructData
{
    char grade;
    char class;
    char gender;
};
//구조체 BigData 형으로 성적(2비트), 등급(5비트), 성별(1비트) 선언
struct BigData
{
    char grade : 2;
    char class : 5;
    char gender : 1;
};

int main()
{
    //구조체 StructData 로 s 선언
    struct StructData s;
    // 구조체 BigData f로 b 선언
    struct BigData b;
    // 구조체 s 와 b의 크기 출력
    printf("StructData : %d\n", sizeof(s)); //3
    printf("BigData : %d", sizeof(b)); //1
}
