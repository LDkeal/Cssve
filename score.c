#include <stdio.h>

//对二维数组赋初值
float Score[5][5] = 
{
    {65 , 75 , 81 , 92 , 46} ,
    {95 , 95 , 92 , 92 , 96} ,
    {85 , 65 , 83 , 92 , 46} ,
    {55 , 95 , 84 , 92 , 46} ,
    {95 , 25 , 85 , 92 , 46} 
};


/***************************************************************************************************
 *      名称:   getAverage()
 *      功能:   获取某个学生的平均分
 *      参数:   StudentNo       学生编号
 *      返回:   平均成绩
****************************************************************************************************/
float getAverage(int StudentNo)
{
    int i ;
    float Sum ;
    Sum = 0 ;
    for(i = 0 ; i < 5 ; i++)
    {
        Sum = Sum + Score[StudentNo][i] ;
    }
    return (Sum / 5);
}

float getLessonAverage(int LessonNo)
{
    int i ;
    float Sum ;
    Sum = 0 ;
    for(i = 0 ; i < 5 ; i++)
    {
        Sum = Sum + Score[i][LessonNo] ;
    }
    return (Sum / 5);
}

void main(void)
{
    int i ;         //第i个人的循环变量
    int j ;         //第j门课程的循环变量
    float Sum ;     //和的变量
    float Average ;

    int Cnt ;       //不及格课程计数



    for(j = 0 ; j < 5 ; j++)
    {
        //求第j门课程的平均分
        Sum = 0 ;
        for(i = 0 ; i < 5 ; i++)
        {
            Sum = Sum + Score[i][j] ;
        }
        printf("第%d门课程的平均分是：%.2f\n" , j + 1 , Sum / 5);
    }

    //找出两门以上不及格的学生
    for(j = 0 ; j < 5 ; j++)
    {
        //第j个学生有多少门课程不及格
        Cnt = 0 ;
        for(i = 0 ; i < 5 ; i++)
        {
            if(Score[j][i] < 60)
            {
                Cnt++ ;
            }
        }
        if(Cnt >= 2)
        {
            printf("第%d个学生有2门以上课程不及格\n" , j + 1);
        }
    }
    //平均成绩90分以上的学生
    for(i = 0 ; i < 5 ; i++)
    {
        Average = getAverage(i);
        if(Average >= 90)
        {
            printf("第%d个学生平均成绩在90分以上\n" , i);
        }
    }
}


