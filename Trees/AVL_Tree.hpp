#include<iostream>
#include<bits/stdc++.h>

int max(int a,int b)
{
    return a>b? a:b;
}

template<typename Type>
class NodeBT
{
    public:
    Type data;
    NodeBT<Type>* left = NULL;
    NodeBT<Type>* right = NULL;
    int height = 0;

    NodeBT(){}
    NodeBT(Type value)
    {
        this->data = value;
    }

    ~NodeBT()
    {
        free(this);
    }
};

template<typename Type>
int getHeight(NodeBT<Type>* node)
{
    return node==NULL? 0 : node->height;
}

template<typename Type>
int getBalanceFactor(NodeBT<Type>* node)
{
    return getHeight(node->left)-getHeight(node->right);
}

template<typename Type>
class AVL_Tree
{
    private:
    NodeBT<Type>* rotateLeft(NodeBT<Type>* node)
    {
        NodeBT<Type>* x = node->right;
        NodeBT<Type>* t2 = x->left;

        node->right = t2;
        x->left = node;

        node->height = 1 + max(getHeight(node->left),getHeight(node->right));
        x->height = 1 + max(getHeight(node->left),getHeight(node->right));
        return x;
    }

    NodeBT<Type>* rotateRight(NodeBT<Type>* node)
    {
        NodeBT<Type>* x = node->left;
        NodeBT<Type>* t2 = x->right;

        x->right = node;
        node->right = t2; 

        node->height = 1 + max(getHeight(node->left),getHeight(node->right));
        x->height = 1 + max(getHeight(node->left),getHeight(node->right));
        return x;
    }

    NodeBT<Type>* insertion(NodeBT<Type>* node,Type value)
    {
        static bool exists = searchBST(value,root);
        if(exists)
        {
            std::logic_error err("Given value already exists in BST.");
            throw err;
        }
        if(node==NULL)
        {
            NodeBT<Type>* newnode = new NodeBT<Type>(value);
            return newnode;
        }
        else
        {
            if(value>node->data)
            {
                node->right = insertion(node->right,value);
            }
            else if(value<node->data)
            {
                node->left = insertion(node->left,value);
            }
            node->height = 1 + max(getHeight(node->left),getHeight(node->right));
            int balanceFactor = getBalanceFactor(node);

            // Rotation Cases:
            // Left Left
            if(balanceFactor>1 && value < node->left->data)
            {
                return rotateRight(node);
            }
            // Right Right
            if(balanceFactor<-1 && value > node->right->data)
            {
                return rotateLeft(node);
            }
            // Left Right
            if(balanceFactor>1 && value > node->left->data)
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
            // Right Left
            if(balanceFactor<-1 && value < node->right->data)
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
            return node;
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

    void inorderDisp(NodeBT<Type>* node)
    {
        if(node!=NULL)
        {
            inorderDisp(node->left);
            std::cout << node->data << " ";
            inorderDisp(node->right);
        }
    }

    public:
    NodeBT<Type>* root = NULL;

    AVL_Tree(){}
    AVL_Tree(Type data)
    {
        root = new NodeBT<Type>(data);
    }

    ~AVL_Tree()
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

    NodeBT<Type>* insert(Type value)
    {
        root = insertion(root,value);
        return root;
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