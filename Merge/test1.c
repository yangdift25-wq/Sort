//从后往前比较
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
   int p1=m-1;//nums1最后一个有效元素
   int p2=n-1;//nums2最后一个元素
   int p3=m+n-1;//nums1最后一个元素

   while(p1>=0&&p2>=0)
   {
    if(nums1[p1]>=nums2[p2])
    {
        nums1[p3]=nums1[p1];
        p3--;
        p1--;
    }
    else
    {
        nums1[p3]=nums2[p2];
        p3--;
        p2--;
    }
   }
   while(p1>=0)//其实可以删了，因为最后剩了nums1的元素，它们本来就在正确的位置
   {
    nums1[p3]=nums1[p1];
    p3--;
    p1--;
   }
   while(p2>=0)
   {
    nums1[p3]=nums2[p2];
    p3--;
    p2--;
   }
}
