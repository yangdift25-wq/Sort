//随机三路快速排序

void Swap(int* left,int* right)
{
  int tmp=*left;
  *left=*right;
  *right=tmp;
}

int* QuickSort(int* arr,int left,int right)
{
  //left>=right直接返回
  if(left>=right)
  {
    return NULL;
  }


//限制随机数范围
int r=left+rand()%(right-left+1);
//交换左节点与基准数
Swap(&arr[left],&arr[r]);
int pivot=arr[left];

//定义三个变量
int lt=left;//<pivot
int i=left+1;//当前数
int gt=right;

  while(i<=gt)
  {
    if(arr[i]<pivot)
    {
      lt++;
      Swap(&arr[i],&arr[lt]);
      i++;
    }
    else if(arr[i]>pivot)
    {
      Swap[&arr[i],&arr[gt]);
      gt--;//不能i++因为不知道互换的数与pivot的关系
    }
    else
    {
      i++;
    }
  }

  //让基准数到正确的位置
  Swap(&arr[left],&arr[lt]);

  //递归左右
  QuickSort(arr,left,lt-1);
  QuickSort(arr,gt+1,right);
}


int main()
{
  int arr[]={1,3,5,5,6,5,5,5,6,8,3,9};
  //设置种子
  srand((unsigned)time(NULL));
  QuickSort(arr,0,11);

  return 0;
}
