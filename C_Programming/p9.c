#include <stdio.h>
int main(){
 int i,num,sum=0;
 float avg=0;
 printf("enter 10 numbers\n");
 for(i=0;i<10;i++)
 {
     printf("Number%d\n",i);
     scanf("%d",&num);
     sum+=num;
 }
 avg=sum*0.1;
printf("summation is : %d\n",sum);
printf("avg is :%f\n",avg);

}
