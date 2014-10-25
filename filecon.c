#include <stdio.h>

void main(void)
{
    FILE *pf1 ;
    FILE *pf2 ;
    unsigned char ch ;

    //打开
    pf1 = fopen("a.c" , "rb");
    if(pf1 == NULL)
    {
        printf("文件打开错误\n");
        return ;
    }
    pf2 = fopen("d.c" , "wb");
    while(1)
    {
        fread(&ch , 1 , 1 , pf1);
        if(feof(pf1))
        {
            break;
        }
        fwrite(&ch , 1 , 1 , pf2);
    }
    fclose(pf1);

    //处理第2个文件
    pf1 = fopen("b.c" , "rb");
    if(pf1 == NULL)
    {
        printf("文件打开错误\n");
        return ;
    }
    while(1)
    {
        fread(&ch , 1 , 1 , pf1);
        if(feof(pf1))
        {
            break;
        }
        fwrite(&ch , 1 , 1 , pf2);
    }
    fclose(pf1);
    //处理第3个文件
    pf1 = fopen("c.c" , "rb");
    if(pf1 == NULL)
    {
        printf("文件打开错误\n");
        return ;
    }
    while(1)
    {
        fread(&ch , 1 , 1 , pf1);
        if(feof(pf1))
        {
            break;
        }
        fwrite(&ch , 1 , 1 , pf2);
    }
    fclose(pf1);
    fclose(pf2);
    printf("合并完毕\n");
}


