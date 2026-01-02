/*
These files are only for Traversal Code, not there full application bcz there is no tree created
to test/use our treversal
*/
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
void preorder(Node<T> *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
}