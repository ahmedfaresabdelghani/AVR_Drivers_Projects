#include <stdio.h>
int main(){
    unsigned int deg;
    printf("please enter your grade ");
	scanf("%d",&deg);
	if(0<=deg && deg<50){
        printf("Fail");
	}
	else if(50<=deg && deg<65){
        printf("normal");
	}
	else if(65<=deg && deg<75){
        printf("good");
	}
	else if(75<=deg && deg<85){
        printf("verygood");
	}
	else if(85<=deg&&deg<=100){
        printf("Excellent");
	}
	else{
        printf("error grade : %d",deg);

	}
}
