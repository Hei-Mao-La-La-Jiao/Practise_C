//3. ��д���� reverse_string, ����ԭ������:
//void reverse_string(char* string);
//�����Ѳ����ַ����е��ַ��������С���ʹ��ָ������������±꣬
//��Ҫʹ���κ�C�����������ڲ����ַ����ĺ�����
//��ʾ������Ҫ����һ���ֲ���������ʱ�洢�����ַ�����

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
		printf("���ַ���\n");
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