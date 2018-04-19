#include<stdio.h>
int i,j,k;
void f1()
{
    for(j=1; j<=3-i; j++)
        printf(" ");
}
void f2()
{
    for(k=1; k<=2*i+4; k++)
        printf("%c",3);
}
main()
{
    printf("    %c%c        %c%c\n",3,3,3,3);
    for(i=1; i<=3; i++)
    {
        f1();
        f2();
        f1();
        f1();
        f2();
        f1();
        printf("\n");
    }
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=i-1; j++)
            printf(" ");
        for(k=1; k<=22-2*i; k++)
            printf("%c",3);
        printf("\n");
    }
}


