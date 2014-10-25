/***************************************************************************************************
 *      版    权:   胡德鹏
 *      文 件 名:   addrBooks.c
 *      作    者:   胡德鹏
 *      版    本:   
 *      创建日期:   2014-10-24 18:06
 *      完成日期:   2014-10-24
 *      文件说明:   手机通信录软件(Linux版)
 *      修改历史:   
****************************************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define NAME_LEN    50
#define SEX_LEN     8
#define TEL_LEN     15
#define ADDR_LEN     50

#define MAX_MAN_NUM 100

//第三个键值
#define KEY_DOWN        66
#define KEY_UP          65
#define KEY_PAGE_DOWN   54
#define KEY_PAGE_UP     53 
//单键
#define KEY_ESC         27
#define KEY_CTRL_C      3


struct MAN_INFO
{
    char Name[NAME_LEN] ;
    char Sex[SEX_LEN] ;
    char Tel[TEL_LEN];
    char Age[6] ;
    char Addr[ADDR_LEN] ;
};

struct MAN_INFO AddrBooks[MAX_MAN_NUM] ;
int CurManNum ;             //实际人数


#define PAGE_SIZE       10      //页大小
int PageStartPos ;               //页的位置(就是AddrBooks[]里面的序号)
int CurInPagePos ;              //当前页内位置（当前光标位置0-9）


int getch(void)  
{  
    struct termios tm, tm_old;  
    int fd = STDIN_FILENO;
    int c ;  
    if(tcgetattr(fd, &tm) < 0)  
        return -1;  
    tm_old = tm;  
    cfmakeraw(&tm);  
    if(tcsetattr(fd, TCSANOW, &tm) < 0)  
        return -1;  
    c = fgetc(stdin);  
    if(tcsetattr(fd, TCSANOW, &tm_old) < 0)  
        return -1;  
    return c;  
}



void LoadFile(void)
{
    FILE *pf ;
    int i ;
    pf = fopen("addr.txt" , "rt");
    CurManNum = 0 ;
    for(i = 0 ; i < MAX_MAN_NUM ; i++)
    {
        fscanf(pf , "%s" , AddrBooks[i].Name);
        fscanf(pf , "%s" , AddrBooks[i].Sex);
        fscanf(pf , "%s" , AddrBooks[i].Tel);
        fscanf(pf , "%s" , AddrBooks[i].Age);
        fscanf(pf , "%s" , AddrBooks[i].Addr);
        if(feof(pf))
        {
            break;
        }
        CurManNum++ ;
    }
    fclose(pf);
}

void dispPage(void)
{
    int i ;
    system("clear");
    printf("---------------------------------------------------\n");
    for(i = 0 ; i < PAGE_SIZE ; i++)
    {
        if(i == CurInPagePos)
        {
            printf("-->");
        }
        else
        {
            printf("   ");
        }
        printf("%s\t%s\n" , AddrBooks[PageStartPos + i].Name , AddrBooks[PageStartPos + i].Tel);
    }
    printf("---------------------------------------------------\n");
    printf("上下键翻页,A键增加，D键删除,回车查看详细信息\n");
    printf("---------------------------------------------------\n");
}

void main(void)
{
    int key ;
/*    while(1)*/
/*    {*/
/*        key = getch();*/
/*        printf("%d\n" , key);*/
/*        if(key == 3)*/
/*        {*/
/*            return ;*/
/*        }*/
/*    }*/

    LoadFile();

    PageStartPos = 0 ;
    CurInPagePos = 0 ;
    while(1)
    {
        dispPage();
        key = getch();
        if(key == 27)
        {
            key = getch();
            key = getch();
            switch(key)
            {
                case KEY_DOWN:
                    if(CurInPagePos < PAGE_SIZE - 1)
                    {
                        CurInPagePos++ ;
                    }
                    else
                    {
                        PageStartPos += PAGE_SIZE ;
                        CurInPagePos = 0 ;
                    }
                    break;
                case KEY_UP:
                    if(CurInPagePos > 0)
                    {
                        CurInPagePos-- ;
                    }
                    else
                    {
                        if(PageStartPos > 0)
                        {
                            PageStartPos -= PAGE_SIZE ;
                            CurInPagePos = PAGE_SIZE - 1 ;
                        }
                    }
                    break;
                case KEY_PAGE_DOWN:
                    PageStartPos += PAGE_SIZE ;
                    key = getch();
                    break;
                case KEY_PAGE_UP:
                    PageStartPos -= PAGE_SIZE ;
                    key = getch();
                    break;
                default:
                    break;
            }
        }
        else
        {
            //响应其他按键
            if(key == KEY_CTRL_C)
            {
                return ;
            }
        }
    }
}


