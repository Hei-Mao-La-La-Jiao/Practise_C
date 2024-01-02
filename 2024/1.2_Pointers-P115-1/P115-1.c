//编写一个函数，它在一个字符串中进行搜索，查找在一个给定字符集合中出现的所有字符。
//这个函数的原型如下：
//char* find_char(char const* source, char const* chars);
//它的基本想法是查找source字符串中匹配 chars字符串中任何字符的第1个字符，
//然后返回一个指向source中第1个匹配所找到的位置的指针。
//如果 source中的所有字符均不匹配 chars中的任何字符，就返回一个NULL 指针。
//如果任何一个参数为NULL，或任何一个参数所指向的字符串为空，函数也返回一个 NULL 指针。
//举个例子, 假定 source指向 ABCDEF, 如果 chars指向 XYZ、JURY 或QQQQ, 函数就返回一个NULL 指针;
//如果 chars指向XRCQEF, 函数就返回一个指向 source中C字符的指针。参数所指向的字符串是绝不会被修改的。
//碰巧，C函数库中存在一个名叫strpbrk的函数，它的功能几乎和这个要编写的函数一模一样。但这个程序的目的是让你自己练习操纵指针，所以：
//a.不应该使用任何用于操纵字符串的库函数(如 strcpy、strcmp、index等);
//b.函数中的任何地方都不应该使用下标引用
#include<stdio.h>
char* find_char(char const* source, char const* chars);

int main()
{
	char source[6] = "ABCFF";
	char chars[4] = "HC";
	char* ch = find_char(source, chars);
	if (ch == NULL)
	{
		printf("空指针");
		return 1;
	}
	printf("下标为:%d,字符为:%c\n",ch - source ,*ch);
	return 0;
}

char* find_char(char const* source, char const* chars)
{
	if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
	{
		return NULL;
	}


	int i = 0;
	int j = 0;
	while (*(chars + i) != '\0')
	{
		while ( (*(chars + i) != *(source + j)) && (*(source + j) != '\0'))
		{
			j++;
		}
		if (*(source + j) != '\0')
		{
			return (source + j);
		}
		i++;
		j = 0;
	}

	return NULL;
}