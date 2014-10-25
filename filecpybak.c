#include <stdio.h>

void main(void)
{
    FILE *pf1 ;     //读
    FILE *pf2 ;     //写
    char ch ;

    pf1 = fopen("filecpy.c" , "rt");
    pf2 = fopen("filecpybak.c" , "wt");
    while(1)
    {
        ch = fgetc(pf1);
        if(feof(pf1))
        {
            break;
        }
        fputc(ch , pf2);
    }
    fclose(pf1);
    fclose(pf2);
}


