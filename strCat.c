#include <stdio.h>

char s1[100] = "hello ";
char s2[100] = "world.";

void main(void)
{
    int i ;         //第1个串的位置
    int j ;         //第2个串的位置
    //1.查找第一个字符串的结束位置
    i = 0 ; 
    while(1)
    {
        if(s1[i] == '\0')
        {
            break;
        }
        i++ ;
    }
    //2.将第2个串连接到第一个串后面
    j = 0 ;
    while(1)
    {
        s1[i] = s2[j] ;
        if(s2[j] == '\0')
        {
            break;
        }
        i++ ;
        j++ ;
    }
    //3.输出结果
    printf("连接后：%s\n" , s1);
}


