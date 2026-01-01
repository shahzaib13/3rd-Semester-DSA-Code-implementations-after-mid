/*
Notes by Shahzaib Saleem:
main logic:
hum 2 stacks use kar rhy, values stack1 mai push kar rhy,
pop and top ky time humy order FIFO mai chahiye but stack LIFO hai,
so hum s1 ko pop kar ky uski value ko s2 mai store krwa dety,
so ab hum s2 ko use kar ky FIFO achive kar skty,
FOR EXAMPLE: 
added values in S1 order is : 1 2 3 
removing values for S1 order is : 3 2 1 (bcz lifo data structure)
now we are also storing those removed values in S2:
values in s2 looks like: 3 2 1
now popping/removing s2 give us: 1 2 3 (s2 ky liye last in first out order)
thus, FIFO order acheived.
*/
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue {
    stack<T> s1;
    stack<T> s2;

public:
    bool isEmpty() const {
        return s1.empty() && s2.empty();
    }

    void enqueue(T x) {
        s1.push(x);
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        T val = s2.top();
        s2.pop();
        return val;
    }

    T peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 

    return 0;
}
