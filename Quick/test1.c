这题是找第K大的元素



使用随机三路快排

OK,那么思路是什么呢?
思路就是因为我们只需要找第K大的数,然后我们就不需要左右两边都递归。我们只需要找这个我们需要找的数在哪个区间,我们就往这个区间递归,其他的区间不管,当然了,如果我们要找的数刚好就等于基准数,那就返回基准数。

然后这样的话,时间复杂度又会提升,时间复杂度是O(n),
在理想的情况下,我们每次递归分区间都能够分为二分之一,因为我们只需要处理一个区间,那么我们在理想的情况下,每次处理的数据就是上次的二分之一,所以总的数据量就是n加2/n加4/n加到最后,然后累加起来就是2n的数据量,所以这个量级是时间复杂度为O(n)的量级。




  //随机三路快排，排序一边
void Swap(int* left,int* right)
{
    int tmp=*left;
    *left=*right;
    *right=tmp;
}



int QuickSort(int* nums,int left,int right,int target)
{
    if(left==right)
    {
        return nums[left];
    }
    int r=left+rand()%(right-left+1);
    Swap(&nums[left],&nums[r]);
    int pivot=nums[left];

    //定义三个指针
    int lt=left;//<pivot
    int i=left+1;//判断当前数
    int gt=right;//>pivot
    while(i<=gt)
    {
        if(nums[i]<pivot)
        {
            lt++;
            Swap(&nums[lt],&nums[i]);
            i++;
        }
        else if(nums[i]>pivot)
        {
            Swap(&nums[gt],&nums[i]);
            gt--;
        }
        else
        {
            i++;
        }
    }
    Swap(&nums[left],&nums[lt]);//基准数归位

    if(target<lt)
    {
        //递归左边
        return QuickSort(nums,left,lt-1,target);
    }
    else if(target>gt)
    {
        //递归右边
        return QuickSort(nums,gt+1,right,target);
    }
    else
    {
        return nums[lt];
    }
}



int findKthLargest(int* nums, int numsSize, int k) {
    int left=0;
    int right=numsSize-1;
    int target=numsSize-k;
    //生成随机种子
    srand((unsigned)time(NULL));
    return QuickSort(nums,left,right,target);
}
