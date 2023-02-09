#include <stdio.h>
int Get_Max(int x,int y);
int main()
{   int op1,op2,max;
    printf("please enter Value 1: ");
    scanf(" %d",&op1);
    printf("please enter Value 2: ");
    scanf(" %d",&op2);
    Get_Max(op1,op2);

}

int Get_Max(int x,int y)
{
    int result=x>y?x:y;
    printf("the max number is: %d",result);
    return result;
}
