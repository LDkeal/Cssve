#include <stdio.h>
//第一个日期
int Year1 = 2012 ;
int Month1 = 1 ;
int Day1 = 10;
//第二个日期
int Year2 = 2012 ;
int Month2 = 3 ;
int Day2 = 12 ;

int MonthTab[] =
{
    31 ,
    28 ,
    31 ,
    30 ,
    31 ,
    30 ,
    31 ,        //7月份
    31 ,
    30 ,
    31 ,
    30 ,
    31
};

int isLeapYear(int y)
{
    if(((y % 400) == 0) || (((y % 4) == 0) &&(y % 100) != 0))
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }
}

/***************************************************************************************************
 *      名称:   getSameYearDays()
 *      功能:   获取同一年当中两个日期相差的天数
 *      参数:   y       年
                m1，d1  第1个月日
                m2, d2  第2个月日
 *      返回:   相差的天数
****************************************************************************************************/
int getSameYearDays(int y , int m1 , int d1 , int m2 , int d2)
{
    int i ;
    int Days ;      //相差天数

    printf("y:%d , m1:%d , d1:%d , m2:%d , d2:%d\n" , y , m1 , d1 , m2 , d2);

    if(m1 == m2)
    {
        Days = d2 - d1 ;
    }
    else
    {
        //第一个月份的天数
        Days = MonthTab[m1 - 1] - d1 ;
        if(m1 == 2)
        {
            if(isLeapYear(y))
            {
                Days++ ;
            }
        }

        //中间月份的天数
        for(i = m1 + 1 ; i < m2 ; i++)
        {
            Days = Days + MonthTab[i - 1] ;      
            if(i == 2)
            {
                if(isLeapYear(y))
                {
                    Days++ ;
                }
            }
        }
        //最后一个月份的天数
        Days = Days + d2 ;      
    }
    return Days ;
}




void main(void)
{
    int Days ;
    int i ;
    if(Year1 == Year2)
    {
        Days = getSameYearDays(Year1 , Month1 , Day1 , Month2 , Day2);
    }
    else
    {
        //1.第一年的天数
        Days = getSameYearDays(Year1 , Month1 , Day1 , 12 , 31);
        //2.中间年份的天数
        for(i = Year1 + 1 ; i < Year2 ; i++)
        {
            Days = Days + 365 ;
            if(isLeapYear(i))
            {
                Days++ ;
            }
        }
        //3.最后一年的天数
        Days = Days + getSameYearDays(Year2 , 1 , 1 , Month2 , Day2);
    }
    printf("两个日期相差的天数：%d\n" , Days);

}



