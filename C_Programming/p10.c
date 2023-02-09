#include<stdio.h>
int main()
{
    int x;
    printf("Enter the answer of 3x5\n");
    scanf("%d",&x);
    while(x!=15)
    {
        printf("please try again , wrong answer");
        scanf("%d",&x);
    }
    printf("thank you");
}
