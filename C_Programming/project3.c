#include <stdio.h>
int main(){
	float width,length,area,circumference;
	printf("enter rectangle width ");
	scanf("%f",&width);
	printf("enter rectangle length ");
	scanf("%f",&length);
	area=length*width;
	circumference=2*(length+width);
	printf("rectangle area is : %f \n",area);
	printf("rectangle circumference is :%f",circumference);
}
