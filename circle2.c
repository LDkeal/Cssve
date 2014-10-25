#include <stdio.h>

int Circle[13] ;        //1：在圈内相应位置有人，0：相应位置没人
int CurManNum ;         //当前圈内人数

void main(void)
{
    int i ;
    int cnt ;           //存放123点数的变量
    int Pos ;           //当前点到的位置
    //1.先围成一个圈
    for(i = 0 ; i < 13 ; i++)
    {
        Circle[i] = 1 ;
    }
    CurManNum = 13 ;
    //2.点数 
    cnt = 0 ;
    Pos = 0 ;
    while(1)
    {
        if(Circle[Pos] == 1)
        {
            //这个位置有人，则点数
            cnt++ ;
            if(cnt == 3)
            {
                //这个人出圈
                Circle[Pos] = 0 ;
                CurManNum-- ;
                if(CurManNum == 1)
                {
                    break;
                }
                cnt = 0 ;
            }
        }
        Pos++ ;
        if(Pos >= 13)
        {
            Pos = 0 ;
        }
    }
    printf("当前圈内情况：\n");
    for(i = 0 ; i < 13 ; i++)
    {
        printf("%d " , Circle[i]);
    }
    printf("\n");
}

