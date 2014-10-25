#include <stdio.h>

void printBlank(int blankNum)
{
    int i ;
    for(i = 0 ; i < blankNum ; i++)
    {
        printf(" ");
    }
}

void printStar(int starNum)
{
    int i ;
    for(i = 0 ; i < starNum ; i++)
    {
        printf("*");
    }
    printf("\n");
}


void main(void)
{
    int i ;
    int LineNum ;
    while(1)
    {
        printf("请输入行数：");

        scanf("%d" , &LineNum);
        for(i = 1 ; i <= LineNum ; i++)
        {
            printBlank(LineNum - i);         //空格数量=总行数-当前行号
            printStar(2 * i - 1);
        }
    }
}

