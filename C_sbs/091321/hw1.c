#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum{
   Quit, Sunday, Monday, Tuesday, Wednesday, Thrusday, Friday, Saturday
} weekday;

weekday next_day(weekday today) {
    weekday next;
    next = (weekday)(((int)today + 1) % 7);
    return next;
}

int main() {
    weekday today, tommorrow;
   


    tommorrow = next_day(today);
    while(1)
    {
        printf("Enter Number corresponding to today. \n");
        // printf("1:Sun, 2:Mon, 3:Tue, 4:Wed, 5:Thu, 6:Fri, 7:Sat, 그만두기(0) \n ");
        printf("1:Sun, 2:Mon, 3:Tue, 4:Wed, 5:Thu, 6:Fri, 7:Sat, 그만두기(0) \n ");
        scanf("%d", &today);
    
        if (today == 1 || today == 2){
            printf("Tommorrow is weekend. \n");
        }
        else if (today == 0) {
            break; 
        }
        else if (today > 7) {
            printf("존재하지 않는 선택지 입니다. \n");
        }
        else {    
            printf("Tommorow is not weekend. \n\n");
        }
    }
    return 0;
}