#include <stdio.h>
#include "STD_TYPES.h"
#pragma pack(1)
typedef struct
{
    u8 hh;
    u16 salary;
    u8 hhh;
    u16 id;

}employee;
employee adel;
int main(){

	printf("%d",sizeof(adel));
}
