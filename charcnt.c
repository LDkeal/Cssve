#include <stdio.h>

int EnCnt ;     //英文字符的个数
int DecCnt ;    //数字字符的个数
int BlankCnt ;  //空格字符的个数
int OtherCnt ;  //其他字符的个数

/*char EnChar[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;*/

void main(void)
{
    int i; 
/*    for(i = 0 ; i < 26*2 ; i++)*/
/*    {*/
/*        printf("%c:0x%2x,%3d " , EnChar[i] , EnChar[i] , EnChar[i]);*/
/*        if((i+1) % 8 == 0 )*/
/*        {*/
/*            printf("\n");*/
/*        }*/
/*    }*/
/*    printf("\n");*/

    int ch ;
    //将字符计数器清零
    EnCnt = 0 ;
    DecCnt = 0 ;
    BlankCnt = 0 ;
    OtherCnt = 0 ;
    while(1)
    {
        ch = getchar();
        if(ch == '\n' || ch == '\r')
        {
            break;
        }
        if(ch >= 'a' && ch <= 'z')
        {
            EnCnt++ ;
        }
        else
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                EnCnt++ ;
            }
            else
            {
                if(ch >= '0' && ch <= '9')
                {
                    DecCnt++ ;
                }
                else
                {
                    if(ch == ' ')
                    {
                        BlankCnt++;
                    }
                    else
                    {
                        OtherCnt++ ;
                    }
                }
            }
        }
    }
    //输出结果
    printf("英文字符的个数：%4d\n" , EnCnt);
    printf("数字字符的个数：%4d\n" , DecCnt);
    printf("空格字符的个数：%4d\n" , BlankCnt);
    printf("其他字符的个数：%4d\n" , OtherCnt);
}


