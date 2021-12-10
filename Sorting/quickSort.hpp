#include "sortingUtils.hpp"

int partition(int array[],int low,int high)
{
    int pivot = array[low];
    int i = low+1;
    int j = high;

    do
    {
        while(array[i]<pivot)
        {
            i++;
        }

        while(array[j]>pivot)
        {
            j--;
        }
        
        if(i<j)
        {
            swap(array[i],array[j]);
        }
    }while(i<j);
    swap(array[low],array[j]);
    return j;
}

void quickSort(int array[],int low,int high)
{
    int partition_int;
    if(low<high)
    {
        partition_int = partition(array,low,high);
        quickSort(array,partition_int+1,high);
        quickSort(array,low,partition_int-1);
    }
    
}