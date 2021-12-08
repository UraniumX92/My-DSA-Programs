#include<iostream>
#include "sortingUtils.hpp"

void bubbleSort(int array[],int size,bool ascending=true)
{
    int tempSize = size;
    bool sorted;
    for(int i=0;i<(size-1);i++,tempSize--)
    {
        sorted = true;
        for(int j=0;j<(tempSize-1);j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
                sorted = false;
            }
        }
        if(sorted)
        {
            break;
        }
    }
    if(!ascending)
    {
        reverse_array(array,size);
    }
}