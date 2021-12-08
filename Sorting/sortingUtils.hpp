void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void shift_right(int array[],int size,int index)
{
    for(int i=size;i>index;i--)
    {
        array[i] = array[i-1];
    }
}

void reverse_array(int array[],int size)
{
    int halfsize = size/2;
    for(int i=0;i<halfsize;i++)
    {
        swap(array[i],array[size-(i+1)]);
    }
}