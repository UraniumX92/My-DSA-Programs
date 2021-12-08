#include<iostream>

template<typename Type>
class NodeDLL
{
    public:
    Type data;
    NodeDLL<Type> * next = NULL;
    NodeDLL<Type> * prev = NULL;

    NodeDLL(){}

    NodeDLL(Type data)
    {
        this->data = data;
    }

    ~NodeDLL()
    {
        free(this);
    }
};

template<typename Type>
class DoublyLinkedList
{
    public:
    NodeDLL<Type> * head;
    NodeDLL<Type> * tail;
    int size = 0;

    DoublyLinkedList()
    {
        head = new NodeDLL<Type>;
        tail = head;
    }

    ~DoublyLinkedList()
    {
        if(head->next!=NULL)
        {
            NodeDLL<Type> * ptr = head->next;
            NodeDLL<Type> * q;
            while(ptr->next!=NULL)
            {
                q = ptr;
                ptr = ptr->next;
                delete q;
            }
            delete ptr;
        }
        delete head;
        free(this);
    }

    void push(Type data)
    {
        NodeDLL<Type> * node = new NodeDLL<Type>(data);
        if(head->next==NULL)
        {
            head->next = node;
            node->prev = head;
            tail = node;
            size++;
            return;
        }
        NodeDLL<Type> * ptr = head->next;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        node->prev = ptr;
        tail = node;
        size++;
    }

    Type pop()
    {
        Type value;
        if(head->next==NULL)
        {
            std::logic_error err("Doubly Linked List is already empty.");
            throw err;
        }
        NodeDLL<Type> * ptr = head->next;
        NodeDLL<Type> * q;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        q = ptr;
        value = q->data;
        ptr = ptr->prev;
        delete q;
        ptr->next = NULL;
        tail = ptr;
        size--;
        return value;
    }

    void insert_after(Type value, Type data)
    {
        NodeDLL<Type>* ptr = head->next;
        while((ptr->data != value) && (ptr->next != NULL))
        {
            ptr = ptr->next;
        }
        if (ptr->data != value)
        {
            std::logic_error err("Given value doesn't exist in Doubly Linked List.");
            throw err;
        }
        NodeDLL<Type>* item = new NodeDLL<Type>(data);
        item->next = ptr->next;
        item->prev = ptr;
        ptr->next = item;
        item->next->prev = item;
        size++;
    }

    NodeDLL<Type>* getNodeIndex(int index)
    {
        if(index > (size - 1) || index < 0)
        {
            std::out_of_range err("Index out of range.");
            throw err;
        }
        if(index == 0)
        {
            return head->next;
        }
        NodeDLL<Type>* ptr = head->next;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }

    void update()
    {
        int s = 0;
        if(head->next==NULL)
        {
            size = 0;
            return;
        }
        NodeDLL<Type> * ptr = head->next;
        while(ptr!=NULL)
        {
            s++;
            ptr = ptr->next;
        }
        size = s;
    }

    NodeDLL<Type>*& getHead()
    {
        return head;
    }

    int getSize()
    {
        return size;
    }

    void interactiveDisplay()
    {
        std::cout << "At each input, Enter 'p' for previous node, and Enter 'n' for next node. any other input will terminate the Interactive Displaying of the Doubly Linked list." << std::endl;
        NodeDLL<Type> * ptr = head->next;
        std::string inputStr = "n";
        int index = 0;
        while(ptr!=NULL)
        {
            std::cout << "Index " << index << ": " << ptr->data << std::endl;
            std::cin >> inputStr;
            if(inputStr=="n")
            {
                ptr = ptr->next;
                index++;
            }
            else if(inputStr=="p")
            {
                ptr = ptr->prev;
                index--;
                if(ptr==head)
                {
                    break;
                }
            }
            else
            {
                std::cout << "Interactive Display terminated by user input." << std::endl;
                return;
            }
        }
        std::cout << "Doubly Linked List reached one of it's end." << std::endl;
    }

    void display(bool reverse=false)
    {
        if(head->next==NULL)
        {
            std::cout << "Doubly Linked List is empty." << std::endl;
            return;
        }
        int i;
        NodeDLL<Type> * ptr;

        if(reverse)
        {
            ptr = tail;
            i = size-1;
            while(ptr!=head)
            {
                std::cout << "index " << i << ": " << ptr->data << std::endl;
                ptr = ptr->prev;
                i--;
            }
        }
        else
        {
            ptr = head->next;
            i = 0;
            while(ptr!=NULL)
            {
                std::cout << "index " << i << ": " << ptr->data << std::endl;
                ptr = ptr->next;
                i++;
            }
        }
    }
}; 