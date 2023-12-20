#include<stdio.h>

//输入函数
void Input(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf_s("%d", arr + i);
	}
}

//输出函数
void Output(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

//求平均数函数
void Ave(int* arr, int sz)
{
	int i = 0;
	int add = 0;
	for (i = 0; i < sz; i++)
	{
		add += arr[i];
	}
	printf("平均数是:%f\n", add / 12.0);
}

//求最大值函数
void Max(int* arr, int sz)
{
	int i = 0;
	int max = arr[0];
	for (i = 0; i < sz; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("数组最大值为:%d\n", max);
}

//求最小值函数
void Min(int* arr, int sz)
{
	int i = 0;
	int min = arr[0];
	for (i = 0; i < sz; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	printf("数组最小值为:%d\n", min);
}

//搜索函数
int Search(int* arr, int sz)
{
	int tem = 0;
	printf("请输入要查找的数:");
	scanf_s("%d", &tem);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (tem == arr[i])
		{
			return i;
		}
	}
	printf("要寻找的数在数组中不存在！");
}

//排序函数（冒泡排序）
void Sort(int* arr, int sz)
{
	int i, j, temp;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//菜单
void menu(void)
{
	printf("\n");
	printf("*****************************\n");
	printf("*** 1.输入       2.输出   ***\n");
	printf("*** 3.平均值     4.最大值 ***\n");
	printf("*** 5.最小值     6.查找   ***\n");
	printf("*** 7.排序       0.退出   ***\n");
	printf("*****************************\n");
}

int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int num = -1;
	int re = -1;
	do
	{
		menu();
		printf("请选择操作:");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			Input(arr, sz);
			break;
		case 2:
			Output(arr, sz);
			break;
		case 3:
			Ave(arr, sz);
			break;
		case 4:
			Max(arr, sz);
			break;
		case 5:
			Min(arr, sz);
			break;
		case 6:
			re = Search(arr, sz);
			if (re != -1)
			{
				printf("找到了，下标为%d", re);
			}
			break;
		case 7:
			Sort(arr, sz);
			break;
		}



	} while (num);

	return 0;
}