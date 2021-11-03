#include <stdio.h>

int second()
{
    printf("\t\tsecond()-srart\n");
    printf("\t\tprintf(\"second()\")\n");
    printf("\t\tsecond() - end\n");

}
int first()
{
    printf("\t\tfirst()-srart\n");
    second();
    printf("\t\tfirst() - end\n");

}
int main()
{
    printf("main()-srart\n");
    first();
    printf("main() - end\n");

}