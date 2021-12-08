#include<iostream>
// #include "SinglyLL.hpp"
// #include "CircularLL.hpp"
#include "DoublyLL.hpp"

int main()
{
    // char array[8] = {'a','b','c','d','e','f','g','h'};
    // int size = sizeof(array)/sizeof(array[0]);
    // SinglyLinkedList<char> * sll  = new SinglyLinkedList<char>(array,size);
    // std::cout << "removed value is " << sll->del(3) << std::endl;
    // sll->insert(0,char(2222));
    // sll->insert_after('b','U');
    // std::cout << *sll << std::endl;
    // std::cout << "Size is : "<< sll->getSize() << std::endl;
    // int n = 0;
    // std::cout << "value at index " << n << " is: " << (*sll)[n] << std::endl;
    
    // SinglyLinkedList<char> s = {array,size};
    // std::cout << s[0] << std::endl;

    // ------------------------------------------------------------------------ //

    // CircularLinkedList<int> cll;
    // cll.push(1);
    // cll.push(2);
    // cll.push(3);
    // cll.push(4);
    // cll.push(5);
    // cll.push(6);
    // std::cout<< cll.pop() << std::endl;
    // cll.insert_after(4,10);
    // NodeSLL<int> * new_node = new NodeSLL<int>(99);
    // cll.insert_after(10,new_node);
    // cll.delete_at_value(2);
    // cll.display();
    // std::cout << "size is " << cll.getSize() << std::endl;
    // delete new_node;

    // ------------------------------------------------------------------------ //

    DoublyLinkedList<int> dll;
    dll.push(10);
    dll.push(20);
    dll.push(30);
    dll.push(40);
    dll.push(50);
    dll.pop();
    std::cout << "forward" << std::endl;
    dll.display();
    std::cout << "backward" << std::endl;
    dll.display(1);
    dll.insert_after(20, 99);
    NodeDLL<int> * gnode = dll.getNodeIndex(dll.getSize()-1);
    NodeDLL<int> * nNode = new NodeDLL<int>(101);
    nNode->next = gnode->next;
    gnode->next = nNode;
    nNode->prev = gnode;
    dll.display();
    std::cout << "Size before updating " << dll.getSize() << std::endl;
    dll.update();
    std::cout << "Size after updating " << dll.getSize() << std::endl;
    dll.interactiveDisplay();
}
