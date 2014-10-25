#include <stdio.h>

void main(void)
{
    //1.定义文件指针
    FILE *pf ;
    char ch ;
    //2.打开文件
    pf = fopen("fileDisp.c" , "rt");
    //3.读文件并显示
    while(1)
    {
        ch = fgetc(pf);         //读一个字节
        if(feof(pf))            //判断文件是否结束
        {
            break;
        }
        printf("%c" , ch);
    }
    //关闭文件
    fclose(pf);
}


