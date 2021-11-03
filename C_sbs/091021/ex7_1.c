#include <stdio.h>
#include <string.h>

struct Person
{
    char name[11];
    char tel[11];
};

int main()
{
    char name[100];
    printf("검색할 이름 입력: ");
    scanf("%s", name);
    findTel(name);
    return 0;
}

int findTel(char*findName)
{
    struct Person PersonArr[3] = {"홍동만", "최민주", "민영진"};
    struct findTel tel = {"2222-1123", "1004-1004", "9999-1234"};
    int i;
    

    for (i = 0; i < 3; i++){

        // strcmp() 함수를 이용하여 이름 비교
        // strcmp() 함수는 두개의 문자열이 같으면 0, 다르면 1을 반환
        if (!strcmp(name[i], findName)) {
            printf("%s의 전화번호는 %s입니다.\n", name[i], tel[i]);
            // 같은 이름이 있으면 함수 종료
            return 0;
        }
    }    
}