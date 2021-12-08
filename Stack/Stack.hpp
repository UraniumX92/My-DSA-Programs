#include<iostream>

template<typename Type>
class Stack
{
    protected:
    int size;
    Type * array;
    int top = -1;

    public:
    Stack(Type arr[],int arrSize)
    {
        size = arrSize;
        array = new Type[arrSize];
        for(int i=0;i<size;i++)
        {
            array[i] = arr[i];
        }
    }

    Stack(int size)
    {
        this->size = size;
        array = new Type[size];
    }

    ~Stack()
    {
        free(array);
    }

    void push(Type value)
    {
        if(top+1==size)
        {
            std::out_of_range err("Stack Overflow.");
            throw err;
        }
        top++;
        array[top] = value;
    }

    Type pop()
    {
        if(top==-1)
        {
            std::out_of_range err("Stack Underflow.");
            throw err;
        }
        Type value = array[top];
        top--;
        return value;
    }

    Type peek(int position)
    {
        if(position>top+1)
        {
            std::out_of_range err("Requested Position out of range.");
            throw err;
        }
        else if(position<=0)
        {
            std::out_of_range err("Position cannot be less than or equal to 0.");
            throw err;
        }
        else
        {
            return array[position-1];
        }
    }

    bool isFull()
    {
        return top+1==size;
    }

    bool isEmpty()
    {
        return top==-1;
    }

    Type topValue()
    {
        return array[top];
    }

    int getTop()
    {
        return top;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if(isEmpty())
        {
            std::cout << "Stack is Empty." << std::endl;
            return;
        }
        for(int i=0;i<top+1;i++)
        {
            std::cout << "Index " << i << ": " << array[i] << std::endl;
        }
        if(isFull())
        {
            std::cout << "Current Stack status : Full" << std::endl;
        }
        else
        {
            std::cout << ".top = " << top << std::endl;
        }

    }
};