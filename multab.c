#include <stdio.h>


void main(void)
{
    int i ;
    int j ;
    //1.第一行
    for(i = 1 ; i <= 9 ; i++)
    {
        printf("%4d" , i);
    }
    printf("\n");
    //2.行用一个循环控制，列用一个循环控制
    for(i = 1 ; i <= 9 ; i++)
    {
        for(j = 1 ; j <= i ; j++)
        {
            printf("%4d" , i * j);
        }
        printf("\n");
    }
}



