#include <stdio.h>

int Data[50] ;


int getMax(int Buf[] , int num)
{
    int i ;
    int max ;
    max = Buf[0] ;
    for(i = 0 ; i < num ; i++)
    {
        if(Buf[i] > max)
        {
            max = Buf[i] ;
        }
    }
    return max ;
}


void main(void)
{
    int i ;
    int Num ;           //数据元素个数
    int Max ;
    Num = 0 ;
    printf("请输入数据(负数结束)：");
    for(i = 0 ; i < 50 ; i++)
    {
        scanf("%d" , &Data[i]);
        if(Data[i] < 0)
        {
            break;
        }
        Num++ ;
    }
    //求最大值
    Max = getMax(Data , Num);

    printf("最大值为：%d\n" , Max);
}


