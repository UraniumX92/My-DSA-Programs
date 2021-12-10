void merge(int array[],int low,int mid,int high)
{
    int i = low;
    int j = mid+1;
    int arr[(high-low)+1];
    int k = 0;
    while(i<=mid && j<=high)
    {
        if(array[i]<array[j])
        {
            arr[k] = array[i];
            i++;k++;
        }
        else
        {
            arr[k] = array[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
        arr[k] = array[i];
        i++;k++;
    }
    while(j<=high)
    {
        arr[k] = array[j];
        j++;k++;
    }
    k=0;
    for(int x=low;x<=high;x++,k++)
    {
        array[x] = arr[k];
    }
}

void mergeSort(int array[],int low,int high)
{
    int mid = (low+high)/2;
    if(low<high)
    {
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}