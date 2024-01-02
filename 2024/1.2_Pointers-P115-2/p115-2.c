//2.编写一个函数，删除一个字符串的一部分。函数的原型如下：
//int del_substr(char* str, char const* substr)
//函数首先应该判断 substr是否出现在 str中。如果它并未出现，函数就返回0；
//如果出现，函数应该把 str 中位于该子串后面的所有字符复制到该子串的位置，从而删除这个子串，然后函数返回1。
//如果 substr多次出现在 str中，函数只删除第1次出现的子串。函数的第2个参数绝不会被修改。
//举个例子, 假定 str指向 ABCDEFG, 如果 substr指向 FGH、CDF 或XABC, 函数应该返回0, str未作任何修改; 
//如果 substr指向CDE, 函数就把 str修改为指向 ABFG, 方法是把F、G和结尾的NUL字节复制到C的位置，然后函数返回1。不论出现什么情况，函数的第2个参数都不应该被修改。
//和上题的程序一样：
//a.不应该使用任何用于操纵字符串的库函数(如strcpy、strcmp等)；
//b.函数中的任何地方都不应该使用下标引用。
//一个值得注意的地方是，空字符串是每个字符串的一个子串，在字符串中删除一个空子串字符串不会产生变化。
#include<stdio.h>
int del_substr(char* str, char const* substr);

int main()
{
	char str[10] = "ABAB";
	char substr[5] = "BAB";
	int ret = del_substr(str, substr);
	if (ret == 0)
	{
		printf("删除失败\n");
		return 1;
	}
	else
	{
		printf("删除成功\n");
	}
	int i = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}



int del_substr(char* str, char const* substr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int save_i = 0;
	int count = 0;
	int sz = 0;
	while (*(substr + i) != '\0')
	{//sz没有计数\0
		sz++;
		i++;
	}
	i = 0;

	while (*(str + k) != '\0')
	{
		//通过循环遍历要删除的字符串，在原字符串中匹配要删除的字符串
		while ((*substr != *(str + i)) && (*(str + i) != '\0'))
		{
			i++;
		}
		//那么跳出循环时只有两种可能，要么是遇到\0,要么是找到了相同的字符
		if (*(str + i) == '\0')//说明找不到与要删除字符串的首字符相同的字符
		{
			return 0;
		}
		//排除都是\0和没找到的情况
		//此时 str + i和 substr 是同一字符
		save_i = i;
		k = i;//方便下一次继续向后查找
		for (j = 0; j < sz; j++)
		{
			//把要删除的字符串遍历
			if (*(substr + j) == *(str + i))
			{
				count++;
			}
			i++;
		}
		//如果完全匹配，count的值应是sz
		if (count == sz)
		{
			i = save_i;
			while (*(str + i + sz - 1) != '\0')
			{
				*(str + i) = *(str + i + sz);
				i++;
			}
			return 1;
		}
		//如果到这里没有出函数，说明不匹配，需要回头往后再找s
		k++;
		i = k;
		count = 0;

	}
}