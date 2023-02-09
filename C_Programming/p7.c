#include <stdio.h>
int main(){
    int hours,hour_rate=50;
    float salary,deduction;
    printf("please enter number of hours ");
	scanf("%d",&hours);
	salary=hours*hour_rate;
	if(hours<40){
        deduction=salary/100*10;
        salary-=deduction;
	}
    printf("%f\n%f",salary,deduction);
}
