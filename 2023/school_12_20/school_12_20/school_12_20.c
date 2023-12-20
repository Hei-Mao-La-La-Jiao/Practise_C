//编写程序exp5_6.c，请判断花瓶是谁打碎的。教师花瓶碎了，班级只有四个小同学，老师询问小同学，已知是其中1人打碎的，还知道4人中每个人要么是诚实的，要么总是说谎的。
//小同学回答老师的问题是：
//甲说：“乙没有打碎，是丁打碎的。”
//乙说：“我没有打碎，是丙打碎的。”
//丙说：“甲没有打碎，是乙打碎的。”
//丁说：“我没有打碎。”
//根据四人回答判断谁打碎了花瓶。
//实验解答：
//①源程序exp5_6.c的源代码如下：

#include<stdio.h>

int main()
{
	//a:     != b       == d    
	//b:     != b       == c	
	//c:     != a       == b
	//d:     != d
	// a:   b/d
	// b:	b/c
	// c:   a/b
	// 
	//要么全真，要么全假

	int a, b, c, d;
	for (a = 0; a < 2; a++)
	{
		for (b = 0; b < 2; b++)
		{
			for (c = 0; c < 2; c++)
			{
				for (d = 0; d < 2; d++)
				{
					if (
						a + b + c + d == 1
						&& (b + d) == 1
						&& (b + c) == 1
						&& (a + b) == 1
						)
					{
						printf("a:%d  b:%d  c:%d  d:%d\n", a, b, c, d);
						printf("打碎花瓶的是为1的");
					}
				}
			}
		}
	}
	return 0;
}