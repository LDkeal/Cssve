#include <stdio.h>

struct stu_info
{
    char Name[30] ;
    int Age ;
    char Sex[8] ;
    char Tel[15] ;
};

int x = 100 ;

struct stu_info  ZhangShan = 
{
    "张三" ,
    19 ,
    "男" ,
    "13988888888"
};

void main(void)
{
    struct stu_info *p ;
    p = &ZhangShan ;
    printf("将张三结构体显示出来：\n");
    printf("%s\t%d\t%s\t%s\n" , ZhangShan.Name , ZhangShan.Age , ZhangShan.Sex , ZhangShan.Tel);
    printf("用指针将张三结构体显示出来：\n");
    printf("%s\t%d\t%s\t%s\n" , p->Name , p->Age , p->Sex , p->Tel);
            
}



