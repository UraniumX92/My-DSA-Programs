#include<iostream>

template<typename Type>
class Queue
{
    private:
    int size;
    int front = -1;
    int rear = -1;
    Type* array;

    void shift_front()
    {
        for(int i=0;i<rear;i++)
        {
            array[i] = array[i+1];
        }
        rear--;
    }

    public:
    Queue(int size)
    {
        this->size = size;
        array = new Type[size];
    }

    ~Queue()
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
        if(isEmpty())
        {
            front++;
            rear++;
            array[rear] = data;
        }
        else
        {
            rear++;
            array[rear] = data;
        }
    }

    Type dequeue()
    {
        if(isEmpty())
        {
            std::out_of_range err("Queue Underflow.");
            throw err;
        }
        Type value = array[front];
        shift_front();
        return value;
    }

    Type peek(int position)
    {
        if(position>rear+1 || position>size)
        {
            std::out_of_range err("Given position is out of range.");
            throw err;
        }
        if(position<=0)
        {
            std::out_of_range err("Position cannot be greater than or equal to 0");
            throw err;
        }
        return array[position-1];
    }

    Type getFront()
    {
        return array[front];
    }

    Type getRear()
    {
        return array[rear];
    }

    int current_size()
    {
        return rear+1;
    }

    bool isFull()
    {
        return (rear == size-1);
    }

    bool isEmpty()
    {
        return (rear == -1);
    }

    void display()
    {
        if(isEmpty())
        {
            std::cout << "Queue is Empty." << std::endl;
            return;
        }
        for(int i=0;i<=rear;i++)
        {
            std::cout << "Position " << i+1 << ": " << array[i] << std::endl;
        }
    }
};