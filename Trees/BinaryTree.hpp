#include<bits/stdc++.h>
#include<iostream>
#include "CustomVector.hpp"

bool isSorted(int array[],int size)
{
    bool sorted;
    for(int i=1;i<size;i++)
    {
        if(array[i]>array[i-1])
        {
            sorted = true;
        }
        else
        {
            return false;
        }
    }
    return sorted;
}

template<typename Type>
class NodeBT
{
    public:
    Type data;
    NodeBT<Type>* left = NULL;
    NodeBT<Type>* right = NULL;
    NodeBT(){}
    NodeBT(Type data)
    {
        this->data = data;
    }
    ~NodeBT()
    {
        free(this);
    }
};

template<typename Type>
class BST
{
    private:
        NodeBT<Type>* inOrderPredecessor(NodeBT<Type>* node)
        {
            node = node->left;
            while(node!=NULL && node->right!=NULL)
            {
                node = node->right;
            }
            return node;
        }

        NodeBT<Type>* inOrderSuccessor(NodeBT<Type>* node)
        {
            node = node->right;
            while(node!=NULL && node->left!=NULL)
            {
                node = node->left;
            }
            return node;
        }

        void inorderDisp(NodeBT<Type>* node)
        {
            if(node!=NULL)
            {
                inorderDisp(node->left);
                std::cout << node->data << " ";
                inorderDisp(node->right);
            }
        }

        NodeBT<Type>* searchBST(Type value,NodeBT<Type>* node)
        {
            if(node==NULL)
            {
                return NULL;
            }

            if(node->data==value)
            {
                return node;
            }
            else if(node->data > value)
            {
                return searchBST(value,node->left);
            }
            else
            {
                return searchBST(value,node->right);
            }
        }

        NodeBT<Type>* deletion(Type value,NodeBT<Type>* node)
        {
            static NodeBT<Type>* exists = search(value);
            if(!exists)
            {
                std::logic_error err("Given Value Doesn't exist in this BST");
                throw err;
            }
            else
            {
                if(node==NULL)
                {
                    return NULL;
                }
                if(node->right==NULL && node->left==NULL)
                {
                    if(node==root)
                    {
                        root = NULL;
                    }
                    else
                    {
                        free(node);
                    }
                    return NULL;
                }

                NodeBT<Type>* temp;
                if(value > node->data)
                {
                    node->right = deletion(value,node->right);
                }
                else if(value < node->data)
                {
                    node->left = deletion(value,node->left);
                }
                else
                {
                    temp = inOrderPredecessor(node);
                    if(temp)
                    {
                        node->data = temp->data;
                        node->left = deletion(temp->data,node->left);
                    }
                    else
                    {
                        temp = inOrderSuccessor(node);
                        node->data = temp->data;
                        node->right = deletion(temp->data,node->right);
                    }

                }
                return node;
            }
        }

    public:
        NodeBT<Type>* root = NULL;
        
        BST(){}

        // Takes a sorted array pointer and the int which is size of the given array and creates a Balanced BST from given array.
        BST(Type array[],int size)
        {
            this->insert(array[size/2]);
            for(int i=0;i<size;i++)
            {
                if(i==size/2)
                {
                    continue;
                }
                this->insert(array[i]);
            }
        }
        
        BST(Type value)
        {
            root = new NodeBT<Type>(value);
        }

        ~BST()
        {
            std::stack<NodeBT<Type>*> st;
            NodeBT<Type>* current = root;
            while(current!=NULL || !st.empty())
            {
                while(current!=NULL)
                {
                    st.push(current);
                    current = current->left;
                }
                current = st.top();
                NodeBT<Type>* temp = current;
                st.pop();
                current = current->right;
                delete temp;
            }
            free(this);
        }

        // Returns a Bool. true if insertion is successful. else false.
        bool insert(Type value)
        {
            if(root==NULL)
            {
                root = new NodeBT<Type>(value);
                return true;
            }
            else
            {
                bool exists = search(value);
                if(exists)
                {
                    return false;
                }
                else
                {
                    NodeBT<Type>* node = root;
                    NodeBT<Type>* prev;

                    while(node!=NULL)
                    {
                        prev = node;
                        if(value > node->data)
                        {
                            node = node->right;
                        }
                        else if(value < node->data)
                        {
                            node = node->left;
                        }
                    }
                    NodeBT<Type>* newnode = new NodeBT<Type>(value);
                    if(value>prev->data)
                    {
                        prev->right = newnode;
                    }
                    else
                    {
                        prev->left = newnode;
                    }
                    return true;
                }
            }
        }

        NodeBT<Type>* search(Type value)
        {
            return searchBST(value,root);
        }

        NodeBT<Type>* del(Type value)
        {
            return deletion(value,root);
        }

        void inorderDisplay()
        {
            if(!root)
            {
                std::cout << "BST is Empty" << std::endl;
                return;
            }
            inorderDisp(root);
            std::cout << std::endl;
        }

};


template<typename Type>
void checkInorder(NodeBT<Type>* node,Cvector<Type>& vec)
{
    if(node->right==NULL && node->left==NULL)
    {
        vec.push(node->data);
        return;
    }
    else
    {
        checkInorder(node->left,vec);
        vec.push(node->data);
        checkInorder(node->right,vec);
    }

}

template<typename Type>
bool isBST(NodeBT<Type>* node)
{
    if(node->left==NULL && node->right==NULL)
    {
        return 1;
    }
    Cvector<Type> vec;
    checkInorder(node,vec);
    return isSorted(vec.get_arrayPtr(),vec.get_current());
}


// CODE TAKEN FROM GEEKS FOR GEEKS. AND SLIGHTLY MODIFIED BY ME (TEMPLATED)
// template<typename Type>
// void inOrder(struct NodeBT<Type>* root)
// {
    
//     std::stack<NodeBT<Type>*> s;
//     NodeBT<Type> *curr = root;
 
//     while (curr != NULL || !s.empty())
//     {
//         /* Reach the left most Node of the
//            curr Node */
//         while (curr !=  NULL)
//         {
//             /* place pointer to a tree node on
//                the stack before traversing
//               the node's left subtree */
//             s.push(curr);
//             curr = curr->left;
//         }
 
//         /* Current must be NULL at this point */
//         curr = s.top();
//         s.pop();
 
//         std::cout << curr->data << " ";
 
//         /* we have visited the node and its
//            left subtree.  Now, it's right
//            subtree's turn */
//         curr = curr->right;
 
//     } /* end of while */
// }