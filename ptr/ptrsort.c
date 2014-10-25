#include <stdio.h>

#define NUM     9

int Data[] = {99 , 88 , 77 , 66 , 55 , 44 , 33 , 22 , 11} ;

void DispData(void)
{
    int *p ;
    printf("当前数据如下：\n");
    for(p = Data ; p < Data + 9 ; p++)
    {
        printf("%d " , *p);
    }
    printf("\n");
}


void main(void)
{
    int *pHead ;                //指向头位置的指针
    int *pTail ;                //指向尾位置的指针
    int tmp ;
    DispData();
    pHead = Data ;
    pTail = pHead + NUM - 1 ; 
    while(1)
    {
        tmp = *pHead ;
        *pHead = *pTail ;
        *pTail = tmp ;
        pHead++ ;               //向后挪动一个位置
        pTail-- ;               //向前挪动一个位置
        if(pHead > pTail)
        {
            break;
        }
    }
    DispData();
}

