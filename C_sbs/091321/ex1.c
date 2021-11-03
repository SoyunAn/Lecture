#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    int entri_year;
    char residence[6];
    char* name;
};

int main()
{
    struct Employee a = { 2019, "Seoul",NULL };
    struct Employee b;

    a.name = (char*)malloc(5*sizeof(char));
    strcpy(a.name, "lee");
    printf("%d %s %s\n", a.entri_year, a.residence, a.name);
    printf("=================\n");

    b=a;
    printf("%d %s %s\n", a.entri_year, a.residence, a.name);
    printf("%d %s %s\n", b.entri_year, b.residence, b.name);
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("=================\n");

    strcpy(b.name, "Park");
    printf("%d %s %s\n", a.entri_year, a.residence, a.name);
    printf("%d %s %s\n", b.entri_year, b.residence, b.name);
    printf("=================\n");
    
    b.entri_year = 2018;
    printf("%d %s %s\n", a.entri_year, a.residence, a.name);
    printf("%d %s %s\n", b.entri_year, b.residence, b.name);
    printf("=================\n");

    return 0;
}