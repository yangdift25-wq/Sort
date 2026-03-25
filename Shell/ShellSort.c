时间复杂度O(n^1.3)左右


#include"ShellSort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void ShellSort(int* a, int n)
{
	//先大步后小步
	int gap = n / 2;
	while (gap > 0)//循环每一次循环过后gap/2
	{
		//前gap个元素默认排好序了,从每组第二个元素拿出来插入
		for (int i = gap; i < n; i++)
		{
			int tmp = a[i];//先把要插入的值存起来
			int j = i;//要进入内层循环了
			while (j - gap >= 0 && a[j - gap] > tmp)
			{
				a[j] = a[j - gap];
				j -= gap;//挪动之后j继续向前找插入位置
			}
			//出了循环交换结束，可以插入值了
			a[j] = tmp;
		}
		gap = gap / 2;
	}
}
