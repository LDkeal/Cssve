#include <stdio.h>

void main(void)
{
    //1.定义数据
    float w , h ;
    float t ;       //体指数

    while(1)
    {
        printf("请输入身高(米)和体重(公斤):");
        scanf("%f%f" , &h , &w);

        t = w / (h * h) ;

        if(t < 18)
        {
            printf("低体重\n");
        }
        else
        {
            if(t >= 18 && t < 25)
            {
                printf("正常体重\n");
            }
            else
            {
                if(t >= 25 && t < 27)
                {
                    printf("超重体重\n");
                }
                else
                {
                    printf("肥胖\n");
                }
            }
        }
    }
}


