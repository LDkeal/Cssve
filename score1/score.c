#include <stdio.h>

#define MAX_SCORE_NUM       16 //能处理的课程最大数量(最后一门课代表在总分)
#define MAX_MAN_NUM         100         //最大处理人数
#define TOTAL_LESSON_NO     15      //总分所在的课程编号

int CurManNum ;             //当前实际人数
int CurLessonNum ;          //当前课程数量

struct STU_INFO
{
    char Name[30] ;
    float Score[MAX_SCORE_NUM];
};

struct STU_INFO   Student[MAX_MAN_NUM] ;

void MovMaxToHead(struct STU_INFO buf[] , int HeadPos , int lessonNo , int Len)
{
    int i; 
    struct STU_INFO tmp ;
    for(i = HeadPos ; i < Len ; i++)
    {
        if(buf[i].Score[lessonNo] > buf[HeadPos].Score[lessonNo])
        {
            tmp = buf[HeadPos] ;
            buf[HeadPos] = buf[i] ;
            buf[i] = tmp ;
        }
    }
}

/***************************************************************************************************
 *      名称:   sort();
 *      功能:   从大到小排序
 *      参数:   Buf         要排序的数据
 *              lessonNo    第几们课程
 *              Len         人数（行数）
 *      返回:   
****************************************************************************************************/
void sort(struct STU_INFO Buf[] , int lessonNo ,int Len)
{
    int i ;
    for(i = 0 ; i < Len ; i++)
    {
        MovMaxToHead(Buf , i , lessonNo , Len);
    }
}


/***************************************************************************************************
 *      名称:   getManTotalScore()
 *      功能:   求单个人的总分
 *      参数:   ManNo       人的编号
 *      返回:   这个人的总分
****************************************************************************************************/
float getManTotalScore(int ManNo)
{
    int i ;
    float sum ;
    sum = 0 ;
    for(i = 0 ; i < CurLessonNum ; i++)
    {
        sum = sum + Student[ManNo].Score[i] ;
    }
    return sum ;
}

void getTotalScore(void)
{
    int i ;
    for(i = 0 ; i < CurManNum ; i++)
    {
        Student[i].Score[TOTAL_LESSON_NO] = getManTotalScore(i);
    }
}

void DispStuInfo()
{
    int i ;
    int j ;
    printf("学生信息如下：\n");
    for(i = 0 ; i < CurManNum ; i++)
    {
        printf("%s\t" , Student[i].Name);
        for(j = 0 ; j < CurLessonNum ; j++)
        {
            printf("%.2f\t" , Student[i].Score[j]);
        }
        printf("%.2f" , Student[i].Score[TOTAL_LESSON_NO]);//显示总分
        printf("\n");
    }
}

/***************************************************************************************************
 *      名称:   getWordNum()
 *      功能:   获取一个字符串中的单词个数
 *      参数:   字符串缓冲区
 *      返回:   单词个数
****************************************************************************************************/
int getWordNum(char buf[])
{
    int i ;
    int wordCnt ;
    i = 0 ;
    wordCnt = 0 ;
    while(1)
    {
        //1.找单词的起始位置
        for( ; i < 200 ; i++)
        {
            if(buf[i] != ' ' && buf[i] != '\t')
            {
                //找到起始位置
                break;
            }
            if(buf[i] == '\0')
            {
                break;
            }
        }
        if(buf[i] == '\0')
        {
            break;
        }
        //2.找单词的结束位置
        for( ; i < 200 ; i++)
        {
            if(buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\0')
            {
                break;
            }
        }
        wordCnt++ ;
    }
    return wordCnt ;
}

/***************************************************************************************************
 *      名称:   LoadFile()
 *      功能:   将文件中的数据装入Student[]
 *      参数:   无
 *      返回:   无
****************************************************************************************************/
void LoadFile(void)
{
    int i ;
    int j ;
    FILE *pf ;
    char Buff[200];
    pf = fopen("score.txt" , "rt");

    //读取第一行
    fgets(Buff , 200 , pf);
    printf("%s\n" , Buff);
    CurLessonNum = 0 ;

    //判断第一行有多少个单词
    CurLessonNum = getWordNum(Buff) - 1;
    printf("CurLessonNum = %d\n" , CurLessonNum);

    rewind(pf);         //文件指针重新指向文件开始的地方
    //1.将文件装入数据结构(装入Student[])
    CurManNum = 0 ;
    for(i = 0 ; i < MAX_MAN_NUM ; i++)
    {
        //每个循环读一个人的信息
        fscanf(pf , "%s" , Student[i].Name);
        for(j = 0 ; j < CurLessonNum ; j++)
        {
            fscanf(pf , "%f" , &Student[i].Score[j]);
        }
        if(feof(pf))
        {
            break;
        }
        CurManNum++ ;
    }
    fclose(pf);

}
void DispScoreArea(int lessonNo , int Min , int Max)
{
    int Cnt ;       //人数
    int i ;
    Cnt = 0 ;
    printf("第%d门课程，分数段%d~%d之间的人如下：\n" , lessonNo , Min , Max);
    for(i = 0 ; i < CurManNum ; i++)
    {
        if(Student[i].Score[lessonNo] >= Min && Student[i].Score[lessonNo] < Max)
        {
            //在这个分数段内
            printf("%s " , Student[i].Name);
            Cnt++ ;
        }
    }
    printf("\n共计%d人\n" , Cnt);
}

void main(void)
{
    int i ;
    LoadFile();
    DispStuInfo();
    sort(Student , 1 , CurManNum);
    DispStuInfo();
    sort(Student , 2 , CurManNum);
    DispStuInfo();

    getTotalScore();
    DispStuInfo();
    sort(Student , TOTAL_LESSON_NO , CurManNum);
    DispStuInfo();




    //1.分段统计
/*    for(i = 0 ; i < CurLessonNum ; i++)*/
/*    {*/
/*        DispScoreArea(i , 0 , 60);*/
/*        DispScoreArea(i , 60 , 70);*/
/*        DispScoreArea(i , 70 , 80);*/
/*        DispScoreArea(i , 80 , 90);*/
/*        DispScoreArea(i , 90 , 101);*/
/*    }*/

}

