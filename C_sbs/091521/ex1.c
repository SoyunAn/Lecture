#include <stdio.h>
#define INF 10000

int arr[INF];
int count  = 0; //전체 데이터 개수

int addBack(int data)
{
    arr[count] = data;
    count++;
}

int addFirst(int data)
{
    //데이터 입력, 앞에서 부터
    for (int i = count; i >= 1; i--){
        arr[i] = arr[i-1]; 
    }
    arr[0] = data;
    count++;
}

int show()
{
    for (int i = 0; i<count; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int removeAt (int index)
{
    for (int i = index; i< count - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    count--;
}

int main()
{
    addFirst(4);
    addFirst(5);
    addFirst(1);
    addBack(7);
    addBack(6);
    addBack(8);
    show(); //1 5 4 7 6 8 
    removeAt(2); //1 5 7 6 8
    show();
    return 0;
}