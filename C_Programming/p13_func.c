#include<stdio.h>
#include "function.c"
/*prototype or declaration*/
int set_bit(int x, int y);
int clear_bit(int x, int y);
int toggle_bit(int x, int y);
int get_bit(int x, int y);
int main()
{
    int op1=8,op2=3;
    /*calling*/
    int res=get_bit(op1,op2);
    printf("%d",res);
}

