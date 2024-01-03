//3. 编写函数 reverse_string, 它的原型如下:
//void reverse_string(char* string);
//函数把参数字符串中的字符反向排列。请使用指针而不是数组下标，
//不要使用任何C函数库中用于操纵字符串的函数。
//提示：不需要声明一个局部数组来临时存储参数字符串。

#include<stdio.h>
void reverse_string(char* string);

int main()
{
	char arr[5] = "ABCD";
	reverse_string(arr);
	int i = 0;
	for (; i < 5; i++)
	{
		printf("%c", arr[i]);
	}

	return 0;
}

void reverse_string(char* string)
{
	char* left = string;
	char* right = NULL;
	int i = 0;
	if (*string == '\0')
	{
		printf("空字符串\n");
		return;
	}

	while (*(string + i) != '\0')
	{
		right = string + i;
		i++;
	}

	char temp = 0;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}