#include <stdio.h>
#include <string.h>

int findTel(char *findName);

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
    // 이름을 저장할 문자열 선언 후  초기화
    char *name[10] = {"홍동만", "최민주", "민영진"};

    //전화번호를 저장할 문자열 선언 후 초기화
    char *tel[10] = {"2222-1123", "1004-1004", "9999-1234"};
    int i;

    // 입력된 이름과 저장된 이름을 비교하여 같으면 전화번호 출력
    for (i = 0; i < 3; i++){

        // strcmp() 함수를 이용하여 이름 비교
        // strcmp() 함수는 두개의 문자열이 같으면 0, 다르면 1을 반환
        if (!strcmp(name[i], findName)) {
            printf("%s의 전화번호는 %s입니다.\n", name[i], tel[i]);
            // 같은 이름이 있으면 함수 종료
            return 0;
        }
    }
    printf("연락처가 없습니다.\n");
}
