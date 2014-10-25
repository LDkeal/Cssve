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






/*
void printOneLineStar(int StarNum)
{
	int i ;
	for(i = 0 ; i < StarNum ; i++)
	{
		printf("*");
	}
	printf("\n");
}


void main(void)
{
	int i ;
	
	int LineNum ;
	
	printf("请输入行数：\n");
	scanf("%d" , &LineNum);	
	for(i = 1 ; i <= LineNum ; i++)
	{	
		printOneLineStar(i);			//打印一行的星号（根据行号）
	}
}
*/


