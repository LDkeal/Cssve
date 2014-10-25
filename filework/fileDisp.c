#include <stdio.h>

void main(void)
{
    char ch ;
    //1.定义文件指针
    FILE *pf ;
    //2.打开文件
    pf = fopen("fileDisp.c" , "rt");
    //3.循环读文件直到文件结束位置
    while(1)
    {
        ch = fgetc(pf);
        if(feof(pf))
        {
            break;
        }
        printf("%c" , ch);
    }
    fclose(pf);
}
