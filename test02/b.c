#include <stdio.h>

/***************************************************************************
	函数三要素：	1.函数名称：应该是一个动词比较好。应该功能有关
				2.函数参数：一般来讲是已知条件，在后面的括号里面
				3.返回值：一般来讲是结果，在名称前面
 ***************************************************************************/
void main(void)
{
	//1.定义存放半径的变量
	double r ;
	//2.定义存放结果，面积的变量
	double s ;
	//3.控制结构
	printf("请输入圆的半径：\n");
	scanf("%lf" , &r);
	s = 3.14 * r * r ;
	printf("圆的面积为：%.2lf\n" , s);
}


