//��дһ������������һ���ַ����н���������������һ�������ַ������г��ֵ������ַ���
//���������ԭ�����£�
//char* find_char(char const* source, char const* chars);
//���Ļ����뷨�ǲ���source�ַ�����ƥ�� chars�ַ������κ��ַ��ĵ�1���ַ���
//Ȼ�󷵻�һ��ָ��source�е�1��ƥ�����ҵ���λ�õ�ָ�롣
//��� source�е������ַ�����ƥ�� chars�е��κ��ַ����ͷ���һ��NULL ָ�롣
//����κ�һ������ΪNULL�����κ�һ��������ָ����ַ���Ϊ�գ�����Ҳ����һ�� NULL ָ�롣
//�ٸ�����, �ٶ� sourceָ�� ABCDEF, ��� charsָ�� XYZ��JURY ��QQQQ, �����ͷ���һ��NULL ָ��;
//��� charsָ��XRCQEF, �����ͷ���һ��ָ�� source��C�ַ���ָ�롣������ָ����ַ����Ǿ����ᱻ�޸ĵġ�
//���ɣ�C�������д���һ������strpbrk�ĺ��������Ĺ��ܼ��������Ҫ��д�ĺ���һģһ��������������Ŀ���������Լ���ϰ����ָ�룬���ԣ�
//a.��Ӧ��ʹ���κ����ڲ����ַ����Ŀ⺯��(�� strcpy��strcmp��index��);
//b.�����е��κεط�����Ӧ��ʹ���±�����
#include<stdio.h>
char* find_char(char const* source, char const* chars);

int main()
{
	char source[6] = "ABCFF";
	char chars[4] = "HC";
	char* ch = find_char(source, chars);
	if (ch == NULL)
	{
		printf("��ָ��");
		return 1;
	}
	printf("�±�Ϊ:%d,�ַ�Ϊ:%c\n",ch - source ,*ch);
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