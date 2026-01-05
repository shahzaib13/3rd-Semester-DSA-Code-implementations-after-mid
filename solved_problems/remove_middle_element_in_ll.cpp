#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next{nullptr};
    Node(T val) : data(val) {}
};

template <typename T>
class SinglyLinkedList
{
    Node<T> *head{nullptr};
    Node<T> *tail{nullptr};

public:
    void push_back(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    T removeMiddleNodeMethodOne()
    {
        if (!head)
            throw out_of_range("List is Empty");

        if (head == tail)
        {
            T val = head->data;
            delete head;
            head = tail = nullptr;
            return val;
        }

        Node<T> *slow = head;
        Node<T> *fast = head;
        Node<T> *prev = nullptr;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        if (slow == tail)
        {
            tail = prev;
        }

        T removedVal = slow->data;
        delete slow;
        return removedVal;
    }

    T removeMiddleNodeMethodTwo()
    {
        if (!head)
            throw out_of_range("List is Empty");
        if (head == tail)
        {
            T val = head->data;
            delete head;
            head = tail = nullptr;
            return val;
        }
        int count = 0;
        Node<T> *curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        curr = head;
        Node<T> *prev = nullptr;
        for (int i = 0; i < count / 2; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == tail)
        {
            tail = prev;
        }

        T removedVal = curr->data;
        delete curr;
        return removedVal;
    }
};

int main()
{
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    cout << "Original: ";
    list.print();

    cout << "Removed: " << list.removeMiddleNodeMethodOne() << endl;
    cout << "After Removal: ";
    list.print();

    return 0;
}