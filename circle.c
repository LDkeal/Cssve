/***************************************************************************************************
    文件：  circle.c
    功能：  13个人围城一圈，点数123,出圈，求最后留下来的人是哪一个
    版本：  V1.0
    作者：  胡德鹏
    修改：  2014.10.7
 ***************************************************************************************************/
#include <stdio.h>

#define MAN_NUM     13          //人数

int Circle[MAN_NUM] ;
int CircleManNum ;      //圈内人数

/***************************************************************************************************
 *      名称:   MakeCircle()
 *      功能:   围成一个圈（相应的数据元素置为1）
 *      参数:   无
 *      返回:   无
****************************************************************************************************/
void MakeCircle(void)
{
    int i ;
    for(i = 0 ; i < MAN_NUM ; i++)
    {
        Circle[i] = 1 ;
    }
    CircleManNum = MAN_NUM ;
}

/***************************************************************************************************
 *      名称:   OutCircle()
 *      功能:   将Pos位置的人出圈
 *      参数:   Pos     需出圈的人的位置
 *      返回:   无
****************************************************************************************************/
void OutCircle(int Pos)
{
    Circle[Pos] = 0 ;
    CircleManNum-- ;
}

void dispCircle(void)
{
    int i ;
    int manNum ;
    manNum = 0 ;
    printf("当前圈内情况:\n");
    for(i = 0 ; i < MAN_NUM ; i++)
    {
        printf("%d " , Circle[i]);
        if(Circle[i] == 1)
        {
            manNum++ ;
        }
    }
    printf("\n");
    printf("圈内共：%d人\n" , manNum);
}

void main(void)
{
    int Count ;             //123点数
    int Pos ;               //当前已经点到了第几个人
    
    MakeCircle();           //围成一个圈
    Count = 0 ;
    Pos = 0 ;
    dispCircle();
    //2.点数
    while(1)
    {
        if(Circle[Pos] == 1)
        {
            //当前位置有人，则点数
            Count++ ;
            if(Count == 3)
            {
                //点到3,出圈
                OutCircle(Pos);

                if(CircleManNum == 1)
                {
                    break;
                }
                Count = 0 ;
            }
        }
        Pos++ ;
        if(Pos >= MAN_NUM)
        {
            Pos = 0 ;
        }
    }
    dispCircle();
}

