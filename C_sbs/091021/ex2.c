#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    char* name;
    int resident_no;
    /* data */
};

int main()
{
    struct Employee seller, * p;
    
    p = &seller;
    p->name = "Jay Kim";
    puts(p->name); //출력
    p->name = (char*)malloc(sizeof(char)*40);
    if (p->name == NULL)
    {
        printf("No more memory.\n");
        exit(1);
    }
    strcpy(p->name, "John Lee");
    puts(p->name);
    free(p->name);
    return 0;
    
}
