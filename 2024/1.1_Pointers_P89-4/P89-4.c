void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
//每个函数的第一个参数是字符数组，用于实际存储所有的位。
//第二个参数用于标识需要访问的位。函数的调用者要确保这个值不要太大，以免越界。
//第一个函数把指定的位设置为1，第二个函数把指定的位清零。
//如果value值为0，第三个函数把指定的为清零，否则设置为1.
//最后一个函数，如果参数中指定的位不是零，函数返回真，否则返回假。
#include<stdio.h>
int main()
{
	char bit_arr[4] = { 0 };

	//测试一下
	set_bit(bit_arr, 1);
	printf("%d\n", bit_arr[0]);
	clear_bit(bit_arr, 1);
	printf("%d\n", bit_arr[0]);

	assign_bit(bit_arr, 2,3);
	printf("%d\n", bit_arr[0]);

	if (test_bit(bit_arr, 7))
	{
		printf("第7位不是0");
	}
	else
	{
		printf("第7位是0");
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