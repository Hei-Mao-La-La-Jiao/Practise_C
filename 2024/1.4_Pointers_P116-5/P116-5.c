void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
void Eratosthenes(char bit_array[]);
//ÿ�������ĵ�һ���������ַ����飬����ʵ�ʴ洢���е�λ��
//�ڶ����������ڱ�ʶ��Ҫ���ʵ�λ�������ĵ�����Ҫȷ�����ֵ��Ҫ̫������Խ�硣
//��һ��������ָ����λ����Ϊ1���ڶ���������ָ����λ���㡣
//���valueֵΪ0��������������ָ����Ϊ���㣬��������Ϊ1.
//���һ�����������������ָ����λ�����㣬���������棬���򷵻ؼ١�

//5. �޸�ǰһ��� Eratosthenes ����ʹ��λ������������ַ����飬
//����Ҫ�õ��� 5�±����ϰ4����������λ���麯��������޸�ʹ����Ŀռ�Ч�ʽ�һ����ߣ�
//����������ʱ��Ч�ʽ��͡������ϵͳ��ʹ������������������ҵ�����������Ƕ��� ?



#include<stdio.h>
#define BIT_NUM 8000
#define HALF_NUM 4000
int main()
{
	char bit_arr[1000];
	unsigned int i = 0;
	for (; i < BIT_NUM; i++)
	{
		set_bit(bit_arr, i);
	}
	Eratosthenes(bit_arr);

	int count = 0;
	for (i = 0; i < BIT_NUM; i++)
	{
		if (test_bit(bit_arr, i))
		{
			count++;
		}
	}
	printf("�����ĸ�����%d��\n", count);

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
	if ((((bit_array[bit_number / 8]) >> (bit_number % 8)) & 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




void Eratosthenes(char bit_arr[])
{
	unsigned int i = 2;
	unsigned int bit_position = 0;//i�Ǵ�2��ʼ��������bit_position�Ƕ�Ӧλ��λ��
	while (i < HALF_NUM)
	{
		if (test_bit(bit_arr, bit_position))
		{
			while ((bit_position + i) < BIT_NUM)
			{
				clear_bit(bit_arr, bit_position + i);//��i��Ϊ��������һ����
				bit_position += i;
			}
		}
		i++;
		bit_position = i - 2;
	}

}