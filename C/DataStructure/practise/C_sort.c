# include<stdio.h>
void BubbleSort(int arr[], int len)
{
    
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectionSort(int arr[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        int min = i;
        for (int j = i+1; i < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}
int main()
{
    int list[] = {6, 5, 7, 3, 2, 9, 8};

    return 0;
}