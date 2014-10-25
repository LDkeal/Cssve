#include <stdio.h>

int a[10] ;
int i ;
for(i = 0 ; i < 10 ; i++)
{
    printf("%d " , a[i]);
}

int a[3][5] ;
int i , j ;
for(i = 0 ; i < 3 ; i++)
{
    for(j = 0 ; j < 5 ; j++)
    {
        printf("%d " , a[i][j]);
    }
}

//二维数组
char MonthTab[12][10] =
{
    "一" ,
    "二" ,
    "三" ,
    "四" ,
    "五" ,
    "六" ,
    "七" ,
    "八" ,
    "九" ,
    "十" ,
    "十一" ,
    "十二" 
};

void main(void)
{
    int Months ;
    while(1)
    {
        printf("请输入数字月份：\n");
        scanf("%d" , &Months);
        if(Months > 0 && Months < 13)
        {
            printf("%s月份\n" , MonthTab[Months - 1]);
        }
        else
        {
            printf("输入错误，请重新输入\n");
        }
    }
}

/*
void main(void)
{
    int Months ;
    while(1)
    {
        printf("请输入数字月份：\n");
        scanf("%d" , &Months);
        switch(Months)
        {
            case 1:
                printf("一月份\n");
                break;
            case 2:
                printf("二月份\n");
                break;
            case 3:
                printf("三月份\n");
                break;
            case 4:
                printf("四月份\n");
                break;
            case 5:
                printf("五月份\n");
                break;
            case 6:
                printf("六月份\n");
                break;
            case 7:
                printf("七月份\n");
                break;
            case 8:
                printf("八月份\n");
                break;
            case 9:
                printf("九月份\n");
                break;
            case 10:
                printf("十月份\n");
                break;
            case 11:
                printf("十一月份\n");
                break;
            case 12:
                printf("十二月份\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;

        }
    }
}
*/



/*
void main(void)
{
    int Months ;
    while(1)
    {
        printf("请输入数字月份：\n");
        scanf("%d" , &Months);

        if(Months == 1)
        {
            printf("一月份\n");
        }
        else
        {
            if(Months == 2)
            {
                printf("二月份\n");
            }
            else
            {
                if(Months == 3)
                {
                    printf("三月份\n");
                }
                else
                {
                    if(Months == 4)
                    {
                        printf("四月份\n");
                    }
                }
            }
        }
    }
}
*/

