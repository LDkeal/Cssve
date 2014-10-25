#include <stdio.h>

int Circle[13] ;            //圈的表示,1:相应位置有人,0:相应位置无人
int CurManNum ;             //当前圈内人数

void dispCircle(void)
{
    int i ;
    printf("当前圈内情况如下：\n");
    for(i = 0 ; i < 13 ; i++)
    {
        printf("%d " , Circle[i]);
    }
    printf("\n");
}

void main(void)
{
    int i ;
    int cnt ;           //存放1/2/3点数的变量
    int Pos ;           //点数的位置
    //1.围成一个圈
    for(i = 0 ; i < 13 ; i++)
    {
        Circle[i] = 1 ;
    }
    CurManNum = 13 ;
    dispCircle();

    //2.点数
    Pos = 0 ;
    cnt = 0 ;
    while(1)
    {
        if(Circle[Pos] == 1)
        {
            cnt++ ;         //点数
            if(cnt == 3)
            {
                Circle[Pos] = 0 ;       //出圈
                cnt = 0 ;
                CurManNum--;
                dispCircle();
            }
        }
        Pos++ ;
        if(Pos == 13)
        {
            Pos = 0 ;
        }
    }
}



