#include <stdio.h>
#include <unistd.h>
#include <termios.h>


#define NAME_LEN    50
#define TEL_LEN     20
#define SEX_LEN     8
#define QQ_LEN      12
#define AGE_LEN     6
#define ADDR_LEN    50

#define MAX_MAN_NUM     100

#define KEY_UP        (0x8000 + 65)
#define KEY_DOWN      (0x8000 + 66)
#define KEY_PAGE_UP   (0x8000 + 53)
#define KEY_PAGE_DOWN (0x8000 + 54)

#define KEY_CTRL_C  3



//定义每个人的信息
struct MAN_INFO
{
    char Name[NAME_LEN] ;
    char Tel[TEL_LEN] ;
    char Sex[SEX_LEN] ;
    char QQ[QQ_LEN] ;
    char Age[AGE_LEN] ;
    char Addr[ADDR_LEN];
};

//定义通信录(每个人信息的数组)
struct MAN_INFO Man[MAX_MAN_NUM] ;
int CurManNum ;                         //当前实际人数
//页数据结构
#define PAGE_SIZE       10
int pageStartPos ;              //页起始位置
int CurInPagePos ;              //页内位置(光标位置)


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

int getKey(void)
{
    int ch ;
    int Key ;
    ch = getch();
    if(ch == 27)
    {
        ch = getch();
        if(ch == 91)
        {
            ch = getch();
            Key = 0x8000 + ch ;
            if(ch == 53 || ch == 54)
            {
                ch = getch();
            }
        }
    }
    else
    {
        Key = ch ;
    }

    return Key ;
}


void DispPage(void)
{
    int i ;
    system("clear");        //清屏
    printf("-----------------------------------------------------------\n");
    for(i = 0 ; i < PAGE_SIZE ; i++)
    {
        if(i == CurInPagePos)
        {
            //显示光标
            printf("-->");
        }
        else
        {
            printf("   ");
        }
        printf("%s\t%s\n" , Man[pageStartPos + i].Name , Man[pageStartPos + i].Tel);
    }
    printf("-----------------------------------------------------------\n");
}

void LoadFile(void)
{
    int i ;
    FILE *pf ;
    pf = fopen("addr.txt" , "rt");
    CurManNum = 0 ;
    for(i = 0 ; i < MAX_MAN_NUM ; i++)
    {
        fscanf(pf , "%s" , Man[i].Name);
        fscanf(pf , "%s" , Man[i].Tel);
        fscanf(pf , "%s" , Man[i].Sex);
        fscanf(pf , "%s" , Man[i].QQ);
        fscanf(pf , "%s" , Man[i].Age);
        fscanf(pf , "%s" , Man[i].Addr);
        if(feof(pf))
        {
            break;
        }
        CurManNum++ ;
    }
    fclose(pf);
}


void main(void)
{
    int Key ;

/*    while(1)*/
/*    {*/
/*        Key = getch();*/
/*        printf("%d\n" , Key);*/
/*    }*/




    LoadFile();             //装载联系人信息到数组中

    while(1)
    {
        DispPage();         //显示一页数据
        Key = getKey();
        switch(Key)
        {
            case KEY_UP:
                if(CurInPagePos > 0)
                {
                    CurInPagePos-- ;
                }
                else
                {
                    if(pageStartPos >= PAGE_SIZE)
                    {
                        pageStartPos = pageStartPos - PAGE_SIZE ;
                        CurInPagePos = PAGE_SIZE - 1 ;
                    }
                }
                break;
            case KEY_DOWN:
                if(CurInPagePos < PAGE_SIZE - 1)
                {
                    CurInPagePos++ ;
                }
                else
                {
                    if(pageStartPos < CurManNum - PAGE_SIZE)
                    {
                        pageStartPos = pageStartPos + PAGE_SIZE ;
                        CurInPagePos = 0 ;
                    }
                }
                break;
            case KEY_PAGE_UP:
                if(pageStartPos >= PAGE_SIZE)
                {
                    pageStartPos = pageStartPos - PAGE_SIZE ;
                }
                break;
            case KEY_PAGE_DOWN:
                if(pageStartPos < CurManNum - PAGE_SIZE)
                {
                    pageStartPos = pageStartPos + PAGE_SIZE ;
                }
                break;
            case 'a':
                break;
            case KEY_CTRL_C:
                return ;
            default:
                break;
        }
    }
}
