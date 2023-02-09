#include<stdio.h>
int main()
{
    int num,result0=1;
    printf("Enter Number");
    scanf("%d",&num);
    do
    {
        result0=result0*num;
        num--;
    }
    while(num>=1);
    printf("Factorial is =%d",result0);
}


