#include <stdio.h>
#include <string.h>

//定义数据结构
struct file_head
{
    char Name[20] ;     //文件名
    long Len ;           //文件长度
};
//求文件长度
long getFileLen(char fileName[])
{
    long Len ;
    char ch ;
    FILE *pf ;
    pf = fopen(fileName , "rb");
    Len = 0 ;
    while(1)
    {
        fread(&ch , 1, 1 , pf);
        if(feof(pf))
        {
            break;
        }
        Len++ ;
    }
    fclose(pf);
    return Len ;
}

void main(void)
{
    FILE *pfWrite ;
    FILE *pfRead ;
    char ch ;
    struct file_head fileRd ;

    char fileName[50] ;         //合并后的文件名
    char fileReadName[50] ;     //要合并的文件名

    printf("请输入合并后的文件名:\n");
    scanf("%s" , fileName);
    pfWrite = fopen(fileName , "wb");


    while(1)
    {
        printf("请输入要合并的文件名(exit结束):\n");
        scanf("%s" , fileReadName);
        if(strcmp(fileReadName , "exit") == 0)
        {
            break;
        }
        pfRead = fopen(fileReadName , "rb");
        if(pfRead == NULL)
        {
            printf("文件名错误,请重新输入\n");
        }
        else
        {
            fclose(pfRead);
            //先准备好文件头结构体
            strcpy(fileRd.Name , fileReadName) ;                
            fileRd.Len =  getFileLen(fileReadName);;
            //将结构体写入文件
            fwrite(&fileRd , sizeof(fileRd) , 1 , pfWrite);
            pfRead = fopen(fileReadName , "rb");
            //正式写入数据到文件当中
            while(1)
            {
                fread(&ch , 1 , 1 , pfRead);
                if(feof(pfRead))
                {
                    break;
                }
                fwrite(&ch , 1 , 1 , pfWrite);
            }
            fclose(pfRead);
        }
    }
    fclose(pfWrite);
    printf("合并成功\n");
}


