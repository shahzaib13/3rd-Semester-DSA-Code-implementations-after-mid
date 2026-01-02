#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Deque
{
    list<T> linked_list;
public:
    bool isEmpty()
    {
        return linked_list.empty();
    }

    void insert_front(T val)
    {
        linked_list.push_front(val);
    }

    void insert_back(T val)
    {
        linked_list.push_back(val);
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }
        linked_list.pop_front();
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }
        linked_list.pop_back();
    }

    void printAll()
    {
        for (T x : linked_list)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    Deque<int> dq;

    dq.insert_back(10);
    dq.insert_back(20);
    dq.insert_front(5);
    dq.insert_back(30);
    dq.printAll();

    dq.pop_front();
    dq.pop_back();
    dq.printAll();
}
