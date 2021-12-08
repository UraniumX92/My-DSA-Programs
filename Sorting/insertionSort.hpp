#include<iostream>
#include "sortingUtils.hpp"

void insertionSort(int array[],int size,bool ascending=true)
{
    for(int i=1;i<size;i++)
    {
        int j = i-1;
        int key = array[i];
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    if(!ascending)
    {
        reverse_array(array,size);
    }
}
