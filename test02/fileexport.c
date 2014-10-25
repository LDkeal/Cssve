#include <stdio.h>

//定义数据结构
struct file_head
{
    char Name[20] ;     //文件名
    long Len ;           //文件长度
};


void main(void)
{
    FILE *pfRead;
    FILE *pfWrite ;
    char fileReadName[50] ;         //解压文件名
    char ch ;
    long i ;

    struct file_head fileHead ;     //定义结构体变量
    //提示输入要解压的文件
    while(1)
    {
        printf("请输入要解压的文件：\n");
        scanf("%s" , fileReadName);
        pfRead = fopen(fileReadName , "rb");
        if(pfRead == NULL)
        {
            printf("输入的文件名错误，请重新输入\n");
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        //1.读文件头
        fread(&fileHead , sizeof(fileHead) , 1 , pfRead);
        if(feof(pfRead))
        {
            break;
        }
        pfWrite = fopen(fileHead.Name , "wb");          //打开写文件
        //2.依次读入文件数据,并写入文件
        for(i = 0 ; i < fileHead.Len ; i++)
        {
            fread(&ch , 1 , 1 , pfRead);
            fwrite(&ch , 1 , 1 , pfWrite);
        }
        fclose(pfWrite);
    }
    fclose(pfRead);
}


