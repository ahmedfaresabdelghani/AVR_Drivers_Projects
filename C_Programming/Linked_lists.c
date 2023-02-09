#include <stdio.h>
#include "BIT_MATH.h"
#include"STD_TYPES.h"
#include <stdlib.h>
typedef struct node
{
    u32 data;
    struct node* next;
}node_t;

int main()
{   
    node_t* head=NULL,*first,*second,*ptr;
    head=(node_t*)malloc(sizeof(node_t));
    first=(node_t*)malloc(sizeof(node_t));
    second=(node_t*)malloc(sizeof(node_t));
    ptr=head;
    head->data=10;
    first->data=20;
    second->data=30;
    head->next=first;
    first->next=second;
    second->next=NULL;
    while (ptr!=NULL)
    {   
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
    
    
    /*
    u16 size_array,*ptr=NULL,chair;
    printf("please enter the number of numbers : ");
    scanf("%d",&size_array);
    ptr=(u16*) malloc(2*size_array);
    for (u16 i = 0; i < size_array; i++)
    {
        printf("please enter number %d :",i+1);
        scanf("%d",&ptr[i]);
    }
    //bubble sorting algorithm
    for (u16 i = 0; i <size_array-1 ; i++)
    {
       for (u16 j = 0; j < size_array-1-i; j++)
       {
        if (ptr[j]>ptr[j+1])
        {
            chair=ptr[j+1];
            ptr[j+1]=ptr[j];
            ptr[j]=chair;
        }
       }  
    }
    printf("the values after sorting\n");
    for (u16 i = 0; i < size_array; i++)
    {
        printf("%d\n",ptr[i]);
    }   
    */
}