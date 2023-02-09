#include<stdio.h>
int poin(int*, int*);
int main()
{
    int x,y;
    int *xp=&x;
    int *yp=&y;
    printf("please enter value 1 : ");
    scanf("%d",&x);
    printf("please enter value 2 : ");
    scanf("%d",&y);

    int z=poin(xp,yp);
    printf("the result is :%d",z);
}

int poin(int *x, int *y)
{
    return (*x+*y);
}

