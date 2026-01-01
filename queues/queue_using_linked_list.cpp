/*
Notes from Shahzaib Saleem about this program:
Queue vs Stack Difference:
Stack: Add at End, Remove from End (LIFO) -> push_back / pop_back
Queue: Add at End, Remove from Front (FIFO) -> push_back / pop_front
Update: Linked list use kar rhy hain, to size dynamic hai aur kabhi full nahi hogi.
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue
{
    list<T> linkedlist;

public:
    bool isEmpty() const
    {
        return linkedlist.empty();
    }

    // Enqueue: Value ko line ky end par add krna
    void enqueue(T val)
    {
        linkedlist.push_back(val);
    }

    // Dequeue: Value ko line ky start (front) sy nikalna
    bool dequeue(T &output)
    {
        if (isEmpty())
            return false;

        output = linkedlist.front();
        linkedlist.pop_front();
        return true;
    }

    T front()
    {
        if (isEmpty())
            throw out_of_range("Queue is empty");
        return linkedlist.front();
    }

    int size()
    {
        return linkedlist.size();
    }

    void printAll()
    {
        for (T val : linkedlist)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q;
    int output;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.printAll(); // Output: 10 20 30 40
}