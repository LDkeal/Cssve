#include <stdio.h>

void main(void)
{
    char ch ;
    //1.定义文件指针
    FILE *pf ;
    //2.打开文件
    pf = fopen("fileread.c" , "rt");
    //3.读，循环读
    while(1)
    {
        ch = fgetc(pf);
        //4.判断文件是否结束
        if(feof(pf))
        {
            break;
        }
        printf("%c" , ch);
    }
    fclose(pf);
}

