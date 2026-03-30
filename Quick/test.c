void Swap(int* left,int* right)
{
    int tmp=*left;
    *left=*right;
    *right=tmp;
}

void QuickSort(int* nums,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int pivot=1;

    //定义三个指针
    int lt=left;
    int i=left;
    int gt=right;

    while(i<=gt)
    {
        if(nums[i]<pivot)
        {
            Swap(&nums[i],&nums[lt]);
            lt++;
            i++;
        }
        else if(nums[i]>pivot)
        {
            Swap(&nums[i],&nums[gt]);
            gt--;
        }
        else
        {
            i++;
        }
    }
}

void sortColors(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    QuickSort(nums,left,right);
}
