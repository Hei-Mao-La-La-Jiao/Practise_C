#include<stdio.h>
//《c和指针》第四章-第7题
// 编写一个函数，从一个字符串中去除多余的空格。
void Deblank(char string[])
{
	int i = 0;
	int j = 0;
	while (string[i] != '\0')
	{
		if (string[i] == 32 && string[i + 1] == 32)
		{
			j = i;
			while (string[j + 1] != '\0')
			{
				string[j + 1] = string[j + 2];
				j++;
			}
			i--;
		}
		i++;
	}
}

int main()
{
	char string[20] = { 0 };
	gets(string);
	Deblank(string);
	printf("%s", string);

	return 0;
}