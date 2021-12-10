#include "sortingUtils.hpp"

int find_max(int array[],int size)
{
    int max = array[0];
    for(int i=0;i<size;i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    return max;
}

void countSort(int array[],int size)
{
    int max = find_max(array,size);
    int arr[max+1];
    for(int i=0;i<=max;i++)
    {
        arr[i] = 0;
    }
    for(int i=0;i<size;i++)
    {
        arr[array[i]]++;
    }
    int j = 0;
    for(int i=0;i<=max;i++)
    {
        if(arr[i]>0)
        {
            array[j] = i;
            arr[i]--;
            i--;j++;
        }
    }
}