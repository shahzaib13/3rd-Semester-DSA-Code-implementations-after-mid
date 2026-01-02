#include <iostream>
using namespace std;

template <typename T>
struct BSTNode
{
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T val)
    {
        data = val;
        left = right = nullptr;
    }
};

template <typename T>
class BST
{
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }
    // Retrun Address of root node
    BSTNode<T>* getRoot()
    {
        return root;
    }
    
    void insert(const T val)
    {
        BSTNode<T> *newNode = new BSTNode<T>(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        BSTNode<T> *currentNode = root;
        BSTNode<T> *previousNode = nullptr;

        while (currentNode != nullptr)
        {
            previousNode = currentNode;
            if (val < currentNode->data)
                currentNode = currentNode->left;
            else if (val > currentNode->data)
                currentNode = currentNode->right;
            else
            {
                delete newNode;
                return;
            }
        }

        if (val < previousNode->data)
            previousNode->left = newNode;
        else
            previousNode->right = newNode;
    }
    /*
    Search karta value ko,
    root sy start hota
    agr value currentNode ki value sy chooti ho tuo left node/side par jata, 
    agr bari tuo right node/side par,
    or agr value equal ho means value mil gayi, return true, else false
    */
    bool search(const T val)
    {
        BSTNode<T> *currentNode = root;
        while (currentNode != nullptr)
        {
            if (currentNode->data == val)
                return true;
            else if (val < currentNode->data)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        return false;
    }

    void deleteNode(const T val)
    {
        BSTNode<T> *cur = root;
        BSTNode<T> *parent = nullptr;
        // Searching value in tree
        while (cur != nullptr && cur->data != val)
        {
            parent = cur;
            if (val < cur->data)
            cur = cur->left;
            else
            cur = cur->right;
        }
        
        // Value do not exist in tree
        if (cur == nullptr)
            return;
        
        // Case 1: 2 childs of node: ab hum right side mai sabsy chooti value tak jaye gy
        // i.e: one step right, then all to left
        // Jis Value ko delete krna tha ussy right side ki sabsy chooti value sy swap ka dy gy
        // Converted to Case 2 or 3
        if (cur->left && cur->right)
        {
            BSTNode<T> *succ = cur->right;
            BSTNode<T> *succParent = cur;

            while (succ->left != nullptr)
            {
                succParent = succ;
                succ = succ->left;
            }

            cur->data = succ->data;
            cur = succ;
            parent = succParent;
        }
        // Case 2: Only One Child
        // Child can be left child or right child, so using tenary operator to decide child
        BSTNode<T> *child = (cur->left) ? cur->left : cur->right;
        // agr koi parent nhi hai tuo means root node par hai hum
        if (parent == nullptr)
        {
            root = child;
        }
        
        else
        {
            if (cur == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }

        delete cur;
    }

    void inorder(BSTNode<T> *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(BSTNode<T> *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(BSTNode<T> *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    BST<int> tree;

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "Inorder: ";
    tree.inorder(tree.getRoot());
    cout << endl;
}