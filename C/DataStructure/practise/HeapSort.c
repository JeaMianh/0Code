#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int arr[], int i, int len)
{
    int dad = i;
    int son = 2*i+1;
    while (son < len)
    {
        if (son+1 < len && arr[son] < arr[son+1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else
        {
            swap(&arr[dad], &arr[son]);
            //判断孙节点
            dad = son;
            son = 2*dad+1;
        }
        
    }
}

void HeapSort(int arr[], int len)
{
    //从最后一个父节点开始
    for (int i = len/2-1; i >= 0; i--)
    {
        MaxHeapify(arr,i,len);
    }
    //堆顶和无序区的最后一个交换,剩下的再排成有序堆
    for (int i = len-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        MaxHeapify(arr, 0, i);
    }
}


int main()
{
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    HeapSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
