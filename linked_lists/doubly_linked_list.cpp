#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;

    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList
{
    Node<T> *head{nullptr};
    Node<T> *tail{nullptr};
    int element{0};

public:
    DoublyLinkedList() {}

    DoublyLinkedList(const DoublyLinkedList &obj)
    {
        Node<T> *temp = obj.head;
        while (temp)
        {
            insertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    ~DoublyLinkedList()
    {
        removeAll();
    }

    void insertAtStart(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (element == 0)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        element++;
    }

    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (element == 0)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        element++;
    }

    bool search(T val) const
    {
        Node<T> *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool remove(T val)
    {
        Node<T> *curr = head;
        while (curr && curr->data != val)
            curr = curr->next;
        if (!curr)
            return false;

        if (curr == head && curr == tail)
        {
            head = tail = nullptr;
        }
        else if (curr == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (curr == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
        element--;
        return true;
    }

    bool removeFromStart(T &output)
    {
        if (element != 0)
            output = head->data;
        return remove(head->data);
    }

    bool removeFromEnd(T &output)
    {
        if (element == 0)
            return false;
        output = tail->data;

        if (element == 1)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        element--;
        return true;
    }

    void removeAll()
    {
        Node<T> *curr = head;
        while (curr)
        {
            Node<T> *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = tail = nullptr;
        element = 0;
    }

    int size() const
    {
        return element;
    }

    DoublyLinkedList &operator=(const DoublyLinkedList &obj)
    {
        if (this != &obj)
        {
            removeAll();
            Node<T> *temp = obj.head;
            while (temp)
            {
                insertAtEnd(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= element)
            throw out_of_range("Index Out Of Bound Error");
        Node<T> *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= element)
            throw out_of_range("Index Out Of Bound Error");
        Node<T> *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }

    friend ostream &operator<<(ostream &os, const DoublyLinkedList &obj)
    {
        Node<T> *temp = obj.head;
        while (temp)
        {
            os << temp->data << " <=> ";
            temp = temp->next;
        }
        os << "NULL\n";
        return os;
    }
};

int main()
{
}
