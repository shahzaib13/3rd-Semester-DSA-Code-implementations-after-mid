/*
Notes from Shahzaib Saleem about this program:
Update: Hum Linked list use kar rhy tuo kbhi stack full nhi hogi, na hi humy dynamic array ki trha
baar baar full hony par copy krny ki zarort
*/
#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Stack
{
    list<T> linkedlist;

public:
    bool isEmpty() const {
        return linkedlist.empty();
    }
    void push(T val) {
        linkedlist.push_back(val);  
    }

    bool pop(T& output) {
        if (isEmpty())
            return false;
        output = linkedlist.back();
        linkedlist.pop_back();
        return true;
    }

    T top() {
        if (isEmpty())
            throw out_of_range("Stack is empty");
        return linkedlist.back();
    }

    int size() {
        return linkedlist.size();
    }

    void printAll() {
        for (T val : linkedlist) {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack<int> s;
    int output;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printAll();
    s.pop(output);
    cout << "Popped: " << output << endl;
    cout << "Top: " << s.top() << endl;
}
