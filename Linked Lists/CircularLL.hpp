#include<iostream>

template<typename Type>
class NodeSLL
{
    public:
    Type data;
    NodeSLL<Type> * next = NULL;

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

template<class Type>
class CircularLinkedList 
{
    protected:
    NodeSLL<Type> * head;
    int size = 0;

    public:

    CircularLinkedList()
    {
        head = new NodeSLL<Type>;
        head->next = head;
    }

    ~CircularLinkedList()
    {
        NodeSLL<Type> * ptr = head->next;
        NodeSLL<Type> * q;
        while(ptr->next!=head->next)
        {
            q = ptr;
            ptr = ptr->next;
            delete q;
        }
        delete q;
        delete head;
        free(this);
    }

    void push(Type data)
    {
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        if(head->next==head)
        {
            head->next = item;
            item->next = head->next;
            size++;
            return;
        }
        NodeSLL<Type> * ptr = head->next;
        while(ptr->next!=head->next)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
        item->next = head->next;
        size++;
    }

    Type pop()
    {
        Type value;
        if(head->next==head)
        {
            std::logic_error err("Circular Linked List is Empty.");
            throw err;
        }

        NodeSLL<Type> * ptr = head;
        if(size==1)
        {
            value = ptr->next->data;
            ptr->next = head;
            size--;
            return value;
        }
        
        do
        {
            ptr = ptr->next;
        }while(ptr->next->next!=head->next);
        value = ptr->next->data;
        ptr->next = head->next;
        size--;
        return value;
    }

    void insert_after(Type value,Type data)
    {
        NodeSLL<Type> * ptr = head->next;
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        while(ptr->data!=value && ptr->next!=head->next)
        {
            ptr = ptr->next;
        }
        if(ptr->data!=value)
        {
            std::logic_error err("Given value doesn't exist in Circular Linked List.");
            throw err;
        }
        item->next = ptr->next;
        ptr->next = item;
        size++;
    }

    void insert_after(Type value,NodeSLL<Type>* new_node)
    {
        NodeSLL<Type> * ptr = head->next;
        while(ptr->data!=value && ptr->next!=head->next)
        {
            ptr = ptr->next;
        }
        if(ptr->data!=value)
        {
            std::logic_error err("Given value doesn't exist in Circular Linked List.");
            throw err;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
        size++;
    }

    void insert_after(NodeSLL<Type>* node,Type data)
    {
        NodeSLL<Type> * item = new NodeSLL<Type>(data);
        item->next = node->next;
        node->next = item;
        size++;
    }

    void insert_after(NodeSLL<Type>* node,NodeSLL<Type>* new_node)
    {
        new_node->next = node->next;
        node->next = new_node;
        size++;
    }

    Type delete_at_value(Type value)
    {
        NodeSLL<Type> * ptr = head->next;
        if(ptr->data==value)
        {
            head->next = ptr->next;
            return value;
        }
        while(ptr->next->data!=value && ptr->next!=head->next)
        {
            ptr = ptr->next;
        }
        if(ptr->next->data!=value)
        {
            std::logic_error err("Given value doesn't exist in Circular Linked List.");
            throw err;
        }
        ptr->next = ptr->next->next;
        size--;
        return value;
    }

    NodeSLL<Type> * getNode(Type value)
    {
        NodeSLL<Type> * ptr = head->next;
        while(ptr->data!=value && ptr->next!=head->next)
        {
            ptr = ptr->next;
        }
        if(ptr->data!=value)
        {
            return NULL;
        }
        return ptr;
    }

    NodeSLL<Type> * getHead()
    {
        return head;
    }

    void display()
    {
        if(head->next==head)
        {
            std::cout << "Circular Linked List is Empty." << std::endl;
            return;
        }
        NodeSLL<Type> * ptr = head;
        int i = 0;
        do
        {
            ptr = ptr->next;
            std::cout << "index " << i << " : " << ptr->data << std::endl;
            i++;
        }while(ptr->next!=head->next);
        return;
    }

    void display_infinite()
    {
        std::string inp = "y";
        NodeSLL<Type> * ptr = head->next;

        int i = 0;
        while(inp!="exit")
        {
            std::cout <<"index "<<i << ": "<< ptr->data << std::endl;
            std::cin >> inp;
            ptr = ptr->next;
            i++;
            if(ptr==head->next)
            {
                i = 0;
            }
        }
        std::cout << "display_infinite() terminated." << std::endl;
    }

    int getSize()
    {
        return size;
    }
};