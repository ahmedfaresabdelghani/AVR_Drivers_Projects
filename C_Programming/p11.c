#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int i=1;
    while(i<=12)
    {
        printf("%d x %d =%d \n",x,i,(x*i));
        i++;
    }

}
