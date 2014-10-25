#include <stdio.h>

struct stu_info
{
    char Name[30] ;
    int Age ;
    char Sex[8];
};

struct stu_info ZhangShan =
{
    "张三" ,
    19 ,
    "男"
};

void main(void)
{
    struct stu_info tmp ;
    //1.定义文件指针
    FILE *pf ;
    //2.打开文件
    pf = fopen("stu.dat" , "wb");
    //3.写数据
    fwrite(&ZhangShan , sizeof(ZhangShan) , 1 , pf);
    //4.关闭文件
    fclose(pf);

    pf = fopen("stu.dat" , "rb");
    fread(&tmp , sizeof(tmp) , 1 , pf);
    fclose(pf);
    //显示tmp
    printf("%s\t%d\t%s\n" , tmp.Name , tmp.Age , tmp.Sex);

}


