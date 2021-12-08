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
class StackLL
{
    private:
    NodeSLL<Type>* top = NULL;
    int size = 0;
    int curr_size = 0;

    public:

    StackLL(int size)
    {
        this->size = size;
    }

    ~StackLL()
    {
        if(top==NULL)
        {
            return;
        }
        NodeSLL<Type>* ptr = top;
        NodeSLL<Type>* q;
        while(ptr!=NULL)
        {
            q = ptr;
            ptr = ptr->next;
            delete q;
        }
        delete ptr;
    }

    void push(Type value)
    {
        if(curr_size==size && size!= 0)
        {
            std::out_of_range err("Stack Overflow.");
            throw err;
        }
        if(top==NULL)
        {
            top = new NodeSLL<Type>(value);
        }
        else
        {
            NodeSLL<Type> * node = new NodeSLL<Type>(value);
            node->next = top;
            top = node;
        }
        curr_size++;
    }
    
    Type pop()
    {
        if(top==NULL)
        {
            std::out_of_range err("Stack Underflow.");
            throw err;
        }
        Type value = top->data;
        NodeSLL<Type>* p = top;
        top = top->next;
        delete p;
        curr_size--;
        return value;
    }

    Type peek(int pos)
    {
        NodeSLL<Type>* ptr = top;
        for(int i=1;i<pos;i++)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    Type topValue()
    {
        return top->data;
    }

    bool isEmpty()
    {
        return top==NULL;
    }

    bool isFull()
    {
        return curr_size==size;
    }

    void display()
    {
        if(top==NULL)
        {
            std::cout << "Stack is Empty."<< std::endl;
            return;
        }
        NodeSLL<Type>* ptr = top;
        int i = 1;
        while(ptr!=NULL)
        {
            std::cout <<"Position "<< i << ": " << ptr->data << std::endl;
            ptr=ptr->next;
            i++;
        }
    }
};