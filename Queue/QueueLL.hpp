#include<iostream>

template<typename Type>
class NodeSLL
{
    public:
    Type data;
    NodeSLL<Type>* next = NULL;

    NodeSLL(){}
    NodeSLL(Type data)
    {
        this->data = data;
    }

    ~NodeSLL()
    {
        free(this);
    }
};

template<typename Type>
class QLL
{
    private:
    int size;
    NodeSLL<Type>* front = NULL;
    NodeSLL<Type>* rear = NULL;
    int current_size = 0;

    public:

    QLL(int size)
    {
        this->size = size;
    }

    ~QLL()
    {
        NodeSLL<Type>* ptr = front;
        NodeSLL<Type>* p;
        while(ptr!=rear)
        {
            p = ptr;
            ptr = ptr->next;
            delete p;
        }
        delete ptr;
        free(this);
    }

    void enqueue(Type data)
    {
        if(isFull())
        {
            std::out_of_range err("Queue Overflow.");
            throw err;
        }
        NodeSLL<Type>* node = new NodeSLL<Type>(data);
        if(isEmpty())
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
        current_size++;
    }

    Type dequeue()
    {
        if(isEmpty())
        {
            std::out_of_range err("Queue Underflow.");
            throw err;
        }
        Type value = front->data;
        NodeSLL<Type>* ptr = front;
        front = front->next;
        delete ptr;
        current_size--;
        return value;
    }

    Type peek(int position)
    {
        if(isEmpty() || position > current_size)
        {
            std::out_of_range err("Requested peek position is out of range.");
            throw err;
        }
        NodeSLL<Type>* ptr = front;
        int i = 1;
        while(i<position)
        {
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }

    Type frontValue()
    {
        return front->data; 
    }

    Type rearValue()
    {
        return rear->data;
    }

    int get_current_size()
    {
        return current_size;
    }

    bool isFull()
    {
        return current_size == size;
    }

    bool isEmpty()
    {
        return front==NULL;
    }

    void display()
    {
        if(isEmpty())
        {
            std::cout << "Queue is Empty." << std::endl;
            return;
        }
        int pos = 1;
        NodeSLL<Type>* ptr = front;
        do
        {
            std::cout << "Position " << pos << ": " << ptr->data << std::endl;
            ptr = ptr->next;
            pos++;
        }while(ptr!=NULL);
    }
};