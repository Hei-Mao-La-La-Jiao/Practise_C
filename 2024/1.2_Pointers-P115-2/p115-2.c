//2.��дһ��������ɾ��һ���ַ�����һ���֡�������ԭ�����£�
//int del_substr(char* str, char const* substr)
//��������Ӧ���ж� substr�Ƿ������ str�С��������δ���֣������ͷ���0��
//������֣�����Ӧ�ð� str ��λ�ڸ��Ӵ�����������ַ����Ƶ����Ӵ���λ�ã��Ӷ�ɾ������Ӵ���Ȼ��������1��
//��� substr��γ����� str�У�����ֻɾ����1�γ��ֵ��Ӵ��������ĵ�2�����������ᱻ�޸ġ�
//�ٸ�����, �ٶ� strָ�� ABCDEFG, ��� substrָ�� FGH��CDF ��XABC, ����Ӧ�÷���0, strδ���κ��޸�; 
//��� substrָ��CDE, �����Ͱ� str�޸�Ϊָ�� ABFG, �����ǰ�F��G�ͽ�β��NUL�ֽڸ��Ƶ�C��λ�ã�Ȼ��������1�����۳���ʲô����������ĵ�2����������Ӧ�ñ��޸ġ�
//������ĳ���һ����
//a.��Ӧ��ʹ���κ����ڲ����ַ����Ŀ⺯��(��strcpy��strcmp��)��
//b.�����е��κεط�����Ӧ��ʹ���±����á�
//һ��ֵ��ע��ĵط��ǣ����ַ�����ÿ���ַ�����һ���Ӵ������ַ�����ɾ��һ�����Ӵ��ַ�����������仯��
#include<stdio.h>
int del_substr(char* str, char const* substr);

int main()
{
	char str[10] = "ABAB";
	char substr[5] = "BAB";
	int ret = del_substr(str, substr);
	if (ret == 0)
	{
		printf("ɾ��ʧ��\n");
		return 1;
	}
	else
	{
		printf("ɾ���ɹ�\n");
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
	{//szû�м���\0
		sz++;
		i++;
	}
	i = 0;

	while (*(str + k) != '\0')
	{
		//ͨ��ѭ������Ҫɾ�����ַ�������ԭ�ַ�����ƥ��Ҫɾ�����ַ���
		while ((*substr != *(str + i)) && (*(str + i) != '\0'))
		{
			i++;
		}
		//��ô����ѭ��ʱֻ�����ֿ��ܣ�Ҫô������\0,Ҫô���ҵ�����ͬ���ַ�
		if (*(str + i) == '\0')//˵���Ҳ�����Ҫɾ���ַ��������ַ���ͬ���ַ�
		{
			return 0;
		}
		//�ų�����\0��û�ҵ������
		//��ʱ str + i�� substr ��ͬһ�ַ�
		save_i = i;
		k = i;//������һ�μ���������
		for (j = 0; j < sz; j++)
		{
			//��Ҫɾ�����ַ�������
			if (*(substr + j) == *(str + i))
			{
				count++;
			}
			i++;
		}
		//�����ȫƥ�䣬count��ֵӦ��sz
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
		//���������û�г�������˵����ƥ�䣬��Ҫ��ͷ��������s
		k++;
		i = k;
		count = 0;

	}
}