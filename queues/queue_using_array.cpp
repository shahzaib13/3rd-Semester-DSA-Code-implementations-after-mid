/*
Notes from Shahzaib Saleem about this program:
Queue is (First in First out data structure), mtlb ky jo value sabsy phly par add hogi,
wohi sab sy phly nikly gi,
IMPORTANT QUEUE FUNCTIONS:
1. isEmpty()
2. isFull()
3. enqueue()
4. dequeue()
note: back par values add hogi and front sy remove hogi, hum modulus iss liye ly rhy taky circual array bany,
taky insertion and deletion hmri constant time mai ho,
*/

#include <iostream>
using namespace std;

const int QUEUESIZE = 10;

template <typename T>
class Queue
{
    T arr[QUEUESIZE];
    int size = QUEUESIZE;
    int element{0};
    int front{0};
    int back{0};

public:

    bool isEmpty() const
    {
        return element == 0;
    }
    bool isFull() const
    {
        return element == size;
    }
    bool enqueue(T val)
    {
        if (isFull())
            return false;
        arr[back] = val;
        back = (back + 1) % size;
        element++;
        return true;
    }
    bool dequeue(T &out)
    {
        if (isEmpty())
            return false;
        out = arr[front];
        front = (front + 1) % size;
        element--;
        return true;
    }
    T peek(){
        if(isEmpty()){
            throw out_of_range("Queue is Empty");
        }
        return arr[front];
    }
};
int main()
{
    int output;
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
}