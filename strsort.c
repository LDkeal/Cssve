#include <stdio.h>

//1.定义一个数组存放字符串
char Str[200] = "hello" ;  

void main(void)
{
    int Head ;      //头指示位置
    int Tail ;      //尾指示位置
    char tmp ;
    printf("请输入字符串：\n");
    scanf("%s" , Str);

    Head = 0 ;
    //2.查找尾部位置
    Tail = 0 ;
    while(1)
    {
        if(Str[Tail] == '\0')
        {
            Tail-- ;
            break;
        }
        Tail++ ;
    }
    //3.将首尾位置数据依次交换
    while(1)
    {
        tmp = Str[Head] ;
        Str[Head] = Str[Tail] ;
        Str[Tail] = tmp ;
        Head++ ;
        Tail-- ;
        if(Head >= Tail)
        {
            break;
        }
    }
    //4.输出结果
    printf("反序后：%s\n" , Str);
}

