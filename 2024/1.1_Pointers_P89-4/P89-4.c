void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
//ÿ�������ĵ�һ���������ַ����飬����ʵ�ʴ洢���е�λ��
//�ڶ����������ڱ�ʶ��Ҫ���ʵ�λ�������ĵ�����Ҫȷ�����ֵ��Ҫ̫������Խ�硣
//��һ��������ָ����λ����Ϊ1���ڶ���������ָ����λ���㡣
//���valueֵΪ0��������������ָ����Ϊ���㣬��������Ϊ1.
//���һ�����������������ָ����λ�����㣬���������棬���򷵻ؼ١�
#include<stdio.h>
int main()
{
	char bit_arr[4] = { 0 };

	//����һ��
	set_bit(bit_arr, 1);
	printf("%d\n", bit_arr[0]);
	clear_bit(bit_arr, 1);
	printf("%d\n", bit_arr[0]);

	assign_bit(bit_arr, 2,3);
	printf("%d\n", bit_arr[0]);

	if (test_bit(bit_arr, 7))
	{
		printf("��7λ����0");
	}
	else
	{
		printf("��7λ��0");
	}

	return 0;
}


void set_bit(char bit_array[], unsigned bit_number)
{
	bit_array[bit_number / 8] |= (1 << (bit_number % 8));
}

void clear_bit(char bit_array[], unsigned bit_number)
{
	bit_array[bit_number / 8] &= ~(1 << (bit_number % 8));
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	if (value == 0)
	{
		clear_bit(bit_array, bit_number);
	}
	else
	{
		set_bit(bit_array, bit_number);
	}
}

int test_bit(char bit_array[], unsigned bit_number)
{
	if (((bit_array[bit_number / 8]) << (bit_number % 8) & 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}