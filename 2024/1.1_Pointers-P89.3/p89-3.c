//��д����...
//����ֵ�ǰ�value�Ķ�����λģʽ�����ұ任һ�º��ֵ��
//��д����ʱҪע�ⲻҪ������������Ļ���������ֵ�ĳ��ȡ�
#include<stdio.h>
unsigned int reverse_bits(unsigned int value);

int main()
{
	unsigned int num = 0;
	scanf_s("%u", &num);
	printf("%u", reverse_bits(num));

	return 0;
}

unsigned int reverse_bits(unsigned int value)
{
	//00000000 00100011
	//11000100 00000000
	int num_bits = sizeof(unsigned int) * 8;
	unsigned int reverse_value = 0;
	int i = 1;
	for (i = 1; i <= num_bits; i++)
	{
		if ((value & 1) == 1)
		{
			reverse_value |= 1 << (num_bits - i);
		}
		value = value >> 1;
	}
	return reverse_value;
}