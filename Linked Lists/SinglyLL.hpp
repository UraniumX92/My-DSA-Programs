#include<iostream>

template<typename Type>
class NodeSLL
{
    public:
    Type data;
    NodeSLL * next = NULL;

    NodeSLL(){}
    NodeSLL(int data)
    {
        this->data = data;
    }

    ~NodeSLL()
    {
        free(this);
    }
};

template<typename Type>
class SinglyLinkedList
{
    protected:
    NodeSLL<Type> * head;
    int size = 0;

    Type deleteAtBeginning()
    {
        Type value = head->next->data;
        head->next = head->next->next;

        size--;
        return value;
    }
    
    void insertAtBeginning(Type data)
    {
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        item->next = head->next;
        head->next = item;
        size++;
    }

    public:

    template<typename T>
    friend std::ostream& operator <<(std::ostream& os,const SinglyLinkedList<T> & sll);

    SinglyLinkedList()
    {
        head = new NodeSLL<Type>;
    }

    SinglyLinkedList(Type array[],int arrSize)
    {
        NodeSLL<Type> * sllPtr = new NodeSLL<Type>(array[0]);
        head = new NodeSLL<Type>(array[0]);
        head->next = sllPtr;
        size++;
        NodeSLL<Type> * ptr;
        for(int i=1;i<arrSize;i++)
        {
            push(array[i]);
        }
    }

    SinglyLinkedList<Type>(std::initializer_list<Type> list)
    {
        std::initializer_list<Type>::iterator it = list.begin();
        for(int i=0;i<list.size();i++)
        {
            std::cout << *(it++) << std::endl;
        }
    }

    ~SinglyLinkedList()
    {
        if(head->next==NULL)
        {
            delete head;
            free(this);
            return;
        }
        NodeSLL<Type> * ptr = head;
        do
        {
            NodeSLL<Type> * P = ptr;
            ptr = ptr->next;
            delete P;

        }while(ptr->next!=NULL);
        free(this);
    }

    Type& operator [] (int index)
    {
        if(index<0||index>=size)
        {
            std::out_of_range err("Index out of range.");
            throw err;
        }
        if(index==0)
        {
            return head->next->data;
        }
        NodeSLL<Type> * ptr = head;
        int i = 0;
        while(i!=index+1 && ptr->next!=NULL)
        {
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }

    void push(Type data)
    {
        if(head->next==NULL)
        {
            NodeSLL<Type> * nitem = new NodeSLL<Type>(data);
            head->next = nitem;
            size++;
            return;
        }
        NodeSLL<Type> * ptr = head;
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
        size++;
    }

    Type pop()
    {
        if(head->next==NULL)
        {
            return head->data;
        }
        Type value;
        NodeSLL<Type> * ptr = head;
        NodeSLL<Type> * q ;
        while(ptr->next!=NULL)
        {
            q = ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        q->next = NULL;
        size--;
        return value;
    }

    void insert(int index,Type data)
    {
        if(index==0)
        {
            insertAtBeginning(data);
            return;
        }
        if(index==size)
        {
            push(data);
            return;
        }
        if(index>size)
        {
            std::out_of_range err("Index out of range.");
            throw err;
        }
        NodeSLL<Type> * ptr = head;
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        for(int i=0;i<index;i++)
        {
            ptr = ptr->next;
        }
        item->next = ptr->next;
        ptr->next = item;
        size++;
    }

    void insert_after(Type value,Type data)
    {   
        NodeSLL<Type> * ptr = head;
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        do
        {
            ptr = ptr->next;
        } while (ptr->data!=value && ptr->next!=NULL);
        if(ptr->data!=value)
        {
            std::logic_error err("Given value does not exist in List.");
            throw err;
        }
        item->next = ptr->next;
        ptr->next = item;
        size++;
    }

    Type del(int index)
    {
        if(index==0)
        {
            return deleteAtBeginning();
        }
        if(index==size-1)
        {
            return pop();
        }
        if(index>=size)
        {
            std::out_of_range err("Index out of range.");
            throw err;
        }
        Type value;
        NodeSLL<Type> * ptr = head;
        for(int i=0;i<index;i++)
        {
            ptr = ptr->next;
        }
        auto q = ptr->next;
        value = q->data;
        // value = ptr->next->data;
        ptr->next = ptr->next->next;
        size--;
        return value;

    }

    void display()
    {
        if(head->next==NULL)
        {
            std::cout << "Linked list is empty!" << std::endl;
            return;
        }
        NodeSLL<Type> * ptr = head;
        int i = 0;
        do
        {
            ptr = ptr->next;
            std::cout << "index " << i <<": "<< ptr->data << std::endl;
            i++;
        }while(ptr->next!=NULL);
    }

    int getSize()
    {
        return size;
    }

};

template<typename T>
std::ostream& operator <<(std::ostream& os,const SinglyLinkedList<T> & sll)
{
    if(sll.head->next==NULL)
    {
        os << "Linked list is empty!" << std::endl;
        return os;
    }
    NodeSLL<T> * ptr = sll.head;
    int i = 0;
    do
    {
        ptr = ptr->next;
        os <<"index "<<i<<": "<< ptr->data << std::endl;
        i++;
    }while(ptr->next!=NULL);
    return os;
}