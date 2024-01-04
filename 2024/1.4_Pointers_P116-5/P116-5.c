void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
void Eratosthenes(char bit_array[]);
//每个函数的第一个参数是字符数组，用于实际存储所有的位。
//第二个参数用于标识需要访问的位。函数的调用者要确保这个值不要太大，以免越界。
//第一个函数把指定的位设置为1，第二个函数把指定的位清零。
//如果value值为0，第三个函数把指定的为清零，否则设置为1.
//最后一个函数，如果参数中指定的位不是零，函数返回真，否则返回假。

//5. 修改前一题的 Eratosthenes 程序，使用位的数组而不是字符数组，
//这里要用到第 5章编程练习4中所开发的位数组函数。这个修改使程序的空间效率进一步提高，
//不过代价是时间效率降低。在你的系统中使用这个方法，你所能找到的最大质数是多少 ?



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
	printf("质数的个数是%d个\n", count);

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
	unsigned int bit_position = 0;//i是从2开始的整数，bit_position是对应位的位置
	while (i < HALF_NUM)
	{
		if (test_bit(bit_arr, bit_position))
		{
			while ((bit_position + i) < BIT_NUM)
			{
				clear_bit(bit_arr, bit_position + i);//加i是为了跳过第一个数
				bit_position += i;
			}
		}
		i++;
		bit_position = i - 2;
	}

}