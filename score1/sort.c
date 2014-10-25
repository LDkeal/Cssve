#include <stdio.h>

#define NUM     10

struct STU_INFO Data[10] ;

void dispData(void)
{
    int i ;
    printf("当前数据如下：\n");
    for(i = 0 ; i < NUM ; i++)
    {
        printf("%d " , Data[i]);
    }
    printf("\n");
}


void main(void)
{
    dispData();
    sort();
    dispData();
}

