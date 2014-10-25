#include <stdio.h>

double getArea(double r)
{
    return (3.14 * r *r);
}

double getCircle(double r)
{
    return (2 * 3.14 * r);
}

/***************************************************************************************************
 *      名称:   getVol()
 *      功能:   求球的体积
 *      参数:   半径
 *      返回:   体积
****************************************************************************************************/
double getVol(double r)
{
    return (4 * 3.14 * r * r * r / 3);
}


void main(void)
{
    double r ;
    double result ;
    int key ;

    double (*func)(double r);


    while(1)
    {
        printf("1   求面积\n");
        printf("2   求周长\n");
        printf("3   求体积\n");
        scanf("%d" , &key);
        printf("请输入半径：\n");
        scanf("%lf" , &r);
        switch(key)
        {
            case 1:
                func = getArea ;
                break;
            case 2:
                func = getCircle ;
                break;
            case 3:
                func = getVol ;
                break;
            default:
                break;
        }
        result = func(r);
        printf("计算结果是：%lf\n" , result);
    }
}

