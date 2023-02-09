#include <stdio.h>
#include "STD_TYPES.h"
typedef struct
{
    u8 id;
    u8 math;
    u8 language;
    u8 physics;
    u8 chemistry;
}student;


int main(void)
{
    student arr[10];
     for(u8 i=0;i<10;i++)
    {
        arr[i].math=i*7+30;
        arr[i].language=i*6+40;
        arr[i].physics=i*5+50;
        arr[i].chemistry=i*4+60;
    }
    u8 id_scan;
        printf("please enter correct student id :");
        scanf("%d",&id_scan);
             if(id_scan<1||id_scan>10)
             {
                 printf("wrong id");
             }
             else
             {      id_scan--;
                    printf("Math  :%d\n",arr[id_scan].math);
                    printf("language :%d\n",arr[id_scan].language);
                    printf("physics :%d\n",arr[id_scan].physics);
                    printf("chemistry :%d\n",arr[id_scan].chemistry);
             }


}
