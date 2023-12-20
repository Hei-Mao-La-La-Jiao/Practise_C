#include<stdio.h>

//���뺯��
void Input(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf_s("%d", arr + i);
	}
}

//�������
void Output(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

//��ƽ��������
void Ave(int* arr, int sz)
{
	int i = 0;
	int add = 0;
	for (i = 0; i < sz; i++)
	{
		add += arr[i];
	}
	printf("ƽ������:%f\n", add / 12.0);
}

//�����ֵ����
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
	printf("�������ֵΪ:%d\n", max);
}

//����Сֵ����
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
	printf("������СֵΪ:%d\n", min);
}

//��������
int Search(int* arr, int sz)
{
	int tem = 0;
	printf("������Ҫ���ҵ���:");
	scanf_s("%d", &tem);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (tem == arr[i])
		{
			return i;
		}
	}
	printf("ҪѰ�ҵ����������в����ڣ�");
}

//��������ð������
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

//�˵�
void menu(void)
{
	printf("\n");
	printf("*****************************\n");
	printf("*** 1.����       2.���   ***\n");
	printf("*** 3.ƽ��ֵ     4.���ֵ ***\n");
	printf("*** 5.��Сֵ     6.����   ***\n");
	printf("*** 7.����       0.�˳�   ***\n");
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
		printf("��ѡ�����:");
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
				printf("�ҵ��ˣ��±�Ϊ%d", re);
			}
			break;
		case 7:
			Sort(arr, sz);
			break;
		}



	} while (num);

	return 0;
}