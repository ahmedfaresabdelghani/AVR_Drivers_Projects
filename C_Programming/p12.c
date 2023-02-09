#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
  for(int i=1;i<=12;i++){
    printf("%d x %d =%d \n",x,i,(x*i));
  }
}
