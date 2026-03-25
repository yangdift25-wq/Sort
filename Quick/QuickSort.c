//快速排序

void QuickSort(int* a, int left, int right)
{

	//开始之前先判断left与right的大小,如果left>=right就没有必要比了
	if (left >= right)
	{
		return;
	}


	//首先把left和right复制一份，待会比较时会改变值
	int begin = left;
	int end = right;
	int pivot = a[left];//把基准值存起来

	//当end大于begin说明没有结束，以此为循环设立条件
	while (end > begin)
	{
		//先走右边，走到小于基准数的值时停下
		while (end > begin && a[end] >= pivot)
		{
			end--;
		}
		//然后走左边，走到大于基准数的值时停下
		while (end > begin && a[begin] <= pivot)
		{
			begin++;
		}
		//然后交换值
		int tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
	}
	int tmp = a[left];
	a[left] = a[end];
	a[end] = tmp;

	//这样只能归位一个基准数
	//然后借助递归在左右继续归位基准数
	QuickSort(a, left, end - 1);
	QuickSort(a, end + 1, right);
}
