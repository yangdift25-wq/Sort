int MergeSort(int* nums,int left,int right,int* arr)
{
    if(left>=right)
    {
        return 0;
    }
    int mid=(left+right)/2;

    //左右递归计数
    int leftcount=MergeSort(nums,left,mid,arr);
    int rightcount=MergeSort(nums,mid+1,right,arr);//注意必须先让左右区间有序再计算跨区间对数，这个顺序不能反

    //计算跨区间对数
    int cross=0;
    int j=mid+1;
    for(int i=left;i<=mid;i++)
    {
        while(j<=right&&(long long )nums[i]>(long long )nums[j]*2)
        {
            j++;
        }

        cross+=j-(mid+1);
    }

    //合并数组
    int p1=left;
    int p2=mid+1;
    int k=0;
    while(p1<=mid&&p2<=right)
    {
        if(nums[p1]<=nums[p2])
        {
            arr[k++]=nums[p1++];
        }
        else
        {
            arr[k++]=nums[p2++];
        }
    }
    
    while(p1<=mid)
    {
        arr[k++]=nums[p1++];
    }

    while(p2<=right)
    {
        arr[k++]=nums[p2++];
    }

    //赋值给nums
    int h=0;
    for(int i=left;i<=right;i++)
    {
        nums[i]=arr[h++];
    }
    return leftcount+rightcount+cross;
}

int reversePairs(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    //定义动态数组，等下排序里面要用
    int* arr=(int*)malloc(sizeof(int)*numsSize);
    int count=MergeSort(nums,left,right,arr);
    //释放内存
    free(arr);

    return count;
}  
