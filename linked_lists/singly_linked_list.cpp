#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class SinglyLinkedList
{
    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
    int element{0};

public:
    SinglyLinkedList() {}

    SinglyLinkedList(const SinglyLinkedList& obj)
    {
        Node<T>* temp = obj.head;
        while (temp)
        {
            insertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    ~SinglyLinkedList()
    {
        removeAll();
    }

    void insertAtStart(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (element == 0)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
        element++;
    }

    void insertAtEnd(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (element == 0)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        element++;
    }

    bool search(T val) const
    {
        Node<T>* temp = head;
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
        if (!head)
            return false;

        if (head->data == val)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            element--;
            if (element == 0)
                tail = nullptr;
            return true;
        }

        Node<T>* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;

        if (!curr->next)
            return false;

        Node<T>* temp = curr->next;
        curr->next = temp->next;
        if (temp == tail)
            tail = curr;
        delete temp;
        element--;
        return true;
    }

    bool removeFromStart(T& output)
    {
        if (element == 0)
            return false;
        output = head->data;
        return remove(output);
    }

    bool removeFromEnd(T& output)
    {
        if (element == 0)
            return false;

        output = tail->data;

        if (element == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node<T>* temp = head;
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        element--;
        return true;
    }

    void removeAll()
    {
        Node<T>* curr = head;
        while (curr)
        {
            Node<T>* nextNode = curr->next;
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

    SinglyLinkedList& operator=(const SinglyLinkedList& obj)
    {
        if (this != &obj)
        {
            removeAll();
            Node<T>* temp = obj.head;
            while (temp)
            {
                insertAtEnd(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= element)
            throw out_of_range("Index Out Of Bound");
        Node<T>* temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= element)
            throw out_of_range("Index Out Of Bound");
        Node<T>* temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }

    friend ostream& operator<<(ostream& os, const SinglyLinkedList& obj)
    {
        Node<T>* temp = obj.head;
        while (temp)
        {
            os << temp->data << " -> ";
            temp = temp->next;
        }
        os << "NULL";
        return os;
    }
};

int main()
{
    SinglyLinkedList<int> l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);

    cout << l << endl;
}
