#include <stdio.h>



#define TYPE_NUM    7           //共7中类型

int MoneyType[] = {100 , 50 , 20 , 10 , 5 , 2 , 1};         //币种类型
int Result[TYPE_NUM] ;          //取款结果数组,张数

int MoneyBox[TYPE_NUM] = {0};        //钱箱,张数


void DispResult(void)
{
    int i ;
    printf("****************************************\n");
    printf("取款结果如下：\n");
    for(i = 0 ; i < TYPE_NUM ; i++)
    {
        if(Result[i] != 0)
        {
            printf("%3d元%4d张\n" , MoneyType[i] , Result[i]);
        }
    }
    printf("****************************************\n");
}

void DispMainMenu(void)
{
    printf("-------------------------------------------------------\n");
    printf("                   欢迎使用硅谷取款机\n");
    printf("                    1:  取款\n");
    printf("                    2:  存款\n");
    printf("                    3:  查询\n");
    printf("                    4:  转账\n");
    printf("                    5:  退出\n");
    printf("-------------------------------------------------------\n");
}

void getMoney(void)
{
    int i;
    int Money ;

    printf("请输入取款金额：");
    scanf("%d" , &Money);

    for(i = 0 ; i < TYPE_NUM ; i++)
    {
        Result[i] = Money / MoneyType[i] ;
        if(Result[i] > MoneyBox[i])
        {
            Result[i] = MoneyBox[i] ;       //取光钱箱里面的张数
        }
        Money = Money - Result[i]*MoneyType[i];      //剩余的钱
    }

    if(Money == 0)
    {
        //取款成功,扣除钱箱里面的钱
        for(i = 0 ; i < TYPE_NUM ; i++)
        {
            MoneyBox[i] = MoneyBox[i] - Result[i] ;
        }
        DispResult();
    }
    else
    {
        printf("余额不足或输入错误\n");
    }
}

void saveMoney(void)
{
    int i ;
    int Money ;
    int Sum ;
    printf("-------------------------------------\n");
    Sum = 0 ;
    for(i = 0 ; i < TYPE_NUM ; i++)
    {
        printf("%3d元的存入张数：" , MoneyType[i]);
        scanf("%d" , &Money);
        MoneyBox[i] = MoneyBox[i] + Money ;
        Sum = Sum + Money * MoneyType[i] ;
        printf("\n");
    }
    printf("共计：%6d元\n" , Sum);
    printf("-------------------------------------\n");
}

void Query(void)
{
    int i ;
    int Sum ;
    printf("-------------------------------------\n");
    printf("当前钱箱情况如下：\n");
    Sum = 0 ;
    for(i = 0 ; i < TYPE_NUM ; i++)
    {
        printf("%3d元的：%4d张\n" , MoneyType[i] , MoneyBox[i]);
        Sum = Sum + MoneyBox[i] * MoneyType[i] ;
    }
    printf("共计:%6d元\n" , Sum);
    printf("-------------------------------------\n");
}

void main(void)
{
    int i ;
    int Money = 152 ;         //取款金额
    int key ;

    while(1)
    {
        DispMainMenu();
        scanf("%d" , &key);
        switch(key)
        {
            case 1:     //取款
                getMoney();
                break;
            case 2:     //存款
                saveMoney();
                break;
            case 3:     //查询
                Query();
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}


