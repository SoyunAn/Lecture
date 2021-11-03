#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void min_max(int a, int b, int* min, int* max)
{
    if (a<b) {
        *min = a;
        *max = b;
    }
    else {
        *min = b;
        *max = a;
    }
}

int main()
{
    int first, second, smaller, larger;

    printf("Enter two different integers.\n");
    scanf("%d%d", &first, &second);

    min_max(first, second, &smaller, &larger);
    printf("Smaller: %d, Larger: %d \n", smaller, larger);

    return 0;

}