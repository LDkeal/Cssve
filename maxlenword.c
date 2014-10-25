#include <stdio.h>
//1.定义数据
char Str[200] = "This is a dog abcdefg888 akedj adskj 22 asfjd." ;

int MaxLen ;        //最长单词的长度
int MaxWordPos ;    //最长单词的位置

void main(void)
{
    int i ;             //循环变量

    int StartPos ;      //单词起始位置
    int EndPos ;        //单词结束位置
    int Len ;           //单词长度
    StartPos = 0 ;
    EndPos = 0 ;

    //初始化最长单词为0
    MaxLen = 0 ;        
    MaxWordPos = 0 ;

    while(1)
    {
        //2.查找单词起始位置
        for(i = EndPos ; i < 200 ; i++)
        {
            if(Str[i] != ' ' || Str[i] == '\0')
            {
                //找到单词起始位置
                StartPos = i ;
                break;
            }
        }
        if(Str[i] == '\0')
        {
            //起始位置到了字符串结束位置，结束单词查找
            break;
        }
        //3.查找单词的结束位置
        for(i = StartPos ; i < 200 ; i++)
        {
            if(Str[i] == ' ' || Str[i] == '\0')
            {
                EndPos = i ;
                break;
            }
        }
        //4.计算单词长度
        Len = EndPos - StartPos ;
        if(Len > MaxLen)
        {
            //保存当前单词为最长单词
            MaxLen = Len ;
            MaxWordPos = StartPos ;
        }
    }
    //5.输出结果
    printf("最长单词长度为：%d\n" , MaxLen);
    for(i = 0 ; i < MaxLen ; i++)
    {
        printf("%c" , Str[MaxWordPos + i]);
    }
    printf("\n");
}


