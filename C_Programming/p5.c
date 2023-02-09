#include <stdio.h>
int main(){
	float num1,num2,sum,subtraction,multip,division;
	printf("enter the first number ");
	scanf("%f",&num1);
	printf("enter the second number ");
	scanf("%f",&num2);
	multip=num1*num2;
	sum=num1+num2;
	division=num1/num2;
	subtraction=num1-num2;
	printf("summation is :%f \n",sum);
	printf("subtraction is : %f \n",subtraction);
	printf("multiplication is  : %f \n",multip);
	printf("division is %f \n",division);
}
