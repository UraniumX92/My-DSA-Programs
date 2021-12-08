#include<iostream>
#include "sortingUtils.hpp"

void selectionSort(int array[],int size,bool ascending=true)
{
    for(int i=0;i<size;i++)
    {
        int min = array[i];
        int index = i;
        for(int j=i+1;j<size;j++)
        {
            if(array[j]<min)
            {
                min = array[j];
                index = j;
            }
        }
        swap(array[i],array[index]);
    }
    if(!ascending)
    {
        reverse_array(array,size);
    }
}