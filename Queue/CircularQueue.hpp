#include<iostream>

template<typename Type>
class CQ
{
    private:
    int size;
    int front = -1; 
    int rear = -1;
    int current_size = 0;
    Type* array;

    // Circular increment around the size of Queue.
    // takes the reference and changes it's value.
    void cIncrement(int& x)
    {
        x = (x+1)%size;
    }

    public:

    CQ(int size)
    {
        this->size = size;
        array = new Type[size];
        cIncrement(front);
    }

    ~CQ()
    {
        delete array;
        free(this);
    }

    void enqueue(Type data)
    {
        if(isFull())
        {
            std::out_of_range err("Queue Overflow.");
            throw err;
        }
        cIncrement(rear);
        array[rear] = data;
        current_size++;
    }

    Type dequeue()
    {
        if(isEmpty())
        {
            std::out_of_range err("Queue Underflow.");
            throw err;
        }
        Type value = array[front];
        cIncrement(front);
        current_size--;
        return value;
    }

    Type peek(int position)
    {   
        if(position>size||position>current_size)
        {
            std::out_of_range err("Requested position out of range.");
            throw err;
        }
        int index,p;
        Type value;
        for(index=front,p=0;p<position;cIncrement(index),p++)
        {
            value = array[index];
        }
        return value;
    }

    Type getFront()
    {
        return array[front];
    }

    Type getRear()
    {
        return array[rear];
    }

    bool isFull()
    {
        return current_size==size;
    }

    bool isEmpty()
    {
        return current_size==0;
    }

    int currentSize()
    {
        return current_size;
    }

    void display()
    {
        if(isEmpty())
        {
            std::cout << "Circular Queue is Empty." << std::endl;
            return;
        }
        for(int index=front,p=1;p<=current_size;cIncrement(index),p++)
        {
            std::cout << "Position " << p << ": " << array[index] << std::endl;
        }
    }

    void show()
    {
        std::string pass;
        std::cin >> pass;
        if(!(pass[0]=='1' && pass[1]=='0'))
        {
            return;
        }
        for(int i=0;i<size;i++)
        {
            std::cout << array[i] << std::endl;
        }
    }
};