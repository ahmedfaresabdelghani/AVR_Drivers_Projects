#include<stdio.h>
int main()
{
    int arr[10]={7,9,15,20,35,42,50,53,57,60};
    int index,search,start=0,end=9,middle;
    printf("please enter a number to search for:");
    scanf(" %d",&search);
    while(start<=end)
    {
        middle=(start+end)/2;
        if(search==arr[middle])
        {
            index=middle;
            printf("the number index is:%d",index);
            break;
        }
        else if(search<arr[middle])
        {
            end=middle-1;
        }
        else
        {
            start=middle+1;
        }
    }
    if(start>end)
    {
     printf("not found");
    }


}
