#include <stdio.h>

void swap(int *x , int *y)
{
    int tmp ;
    tmp = *x ;
    *x = *y ;
    *y = tmp ;
}

void main(void)
{
    int a = 99 ;
    int b = 100 ;

    printf("a = %d , b = %d\n" , a , b);
    swap(&a , &b);
    printf("a = %d , b = %d\n" , a , b);

}
