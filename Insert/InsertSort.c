//堆排序

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];//先把end加1位置的值存起来，后面会覆盖掉

		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
				//这里预留a[end]为了后面插入
			}
			else
			{
				break;
			}
		}
		//内循环结束插入
		a[end + 1] = tmp;
		//这里放外面是因为，当tmp是最小时end就到-1了，这样写在外面可以简略一点
	}
}
