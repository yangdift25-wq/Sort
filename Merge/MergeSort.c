#include<stdio.h>
#include<stdlib.h>



//合并函数
void Merge(int* a, int left, int mid, int right)
{
	//定义一个新数组来存放合并的数
	int n = right - left + 1;
	int* arr=(int*)malloc(sizeof(int)*(right-left+1));
	//需要三个指针
	int p1 = left;
	int p2 = mid + 1;
	int p3 = 0;

	while (p1 <= mid && p2 <= right)
	{
		if (a[p1] <= a[p2])
		{
			arr[p3] = a[p1];
			p1++;
			p3++;
		}
		else
		{
			arr[p3] = a[p2];
			p2++;
			p3++;
		}
	}
	//因为有一个已经比较完了，继续比较另一个
	//分左右两种情
	while (p1 <= mid)
	{
		arr[p3] = a[p1];
		p3++;
		p1++;
	}
	while (p2 <= right)
	{
		arr[p3] = a[p2];
		p3++;
		p2++;
	}
	int j = 0;
	for (int i = left; i <= right; i++)
	{
		a[i] = arr[j];
		j++;
	}
	//用完释放空间
	free(arr);
}



//归并排序
void MergeSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//mid在各个递归里都不一样
	int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);

	//写一个完成合并的函数
	Merge(a, left, mid, right);
}


int main()
{
	int a[] = { 2,4,1,6,4,3,7,5 };
	MergeSort(a, 0, 7);
	for (int i = 0; i <= 7; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}
