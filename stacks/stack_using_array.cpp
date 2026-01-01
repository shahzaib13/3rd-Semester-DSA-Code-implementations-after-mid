/*
Notes from Shahzaib Saleem about this program:
Stack is (Last in First out data structure), mtlb ky jo value sabsy end par add hogi,
woh sab sy phly nikly gi,
IMPORTANT STACK FUNCTIONS:
1. isEmpty()
2. isFull()
3. push()
4. pop()
5. top() or peek()
iss program ki limitations: array use kar rhy tuo size fix hoga tuo fix size ki stack bany gi,
*/
#include <iostream>
using namespace std;

const int StackSize = 10; // Stack Array Size

template <typename T>
class Stack
{
    T arr[StackSize]; // Array to store values
    int totalCapacity = StackSize; // total number of values a stack  can store
    int topIdx = -1; // index of top value or numbers of elements

public:
    // Function to check is stack is empty
    bool isEmpty()
    {
        return topIdx == -1;
    }
    // Function to check is stack is full (minus -1 iss liye kiya bcz array size 1 sy 10 tak ja rha
    // but hmry array ky index 0 sy 9 tak )
    bool isFull()
    {
        return topIdx == totalCapacity - 1;
    }
    // Values Add krny ky liye (agr stack full howa tuo kuch add nhi hoga)
    bool push(T val)
    {
        if (isFull())
        {
            return false;
        }
        topIdx++;
        arr[topIdx] = val;
        return true;
    }
    // Values Remove krny ky liye (agr stack empty howa tuo kuch add nhi hoga)
    bool pop(T &output)
    {
        if (isEmpty())
        {
            return false;
        }
        output = arr[topIdx];
        topIdx--;
        return true;
    }
    // Sab sy upar/top wali value dekhny/get ky liye (agr stack empty hoyi tuo koi value nhi hogi tuo error throw kar diya)
    T top()
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty");
        }
        return arr[topIdx];
    }
    // Sari values print krwny ky liye
    void printAll()
    {
        for (int i = 0; i <= topIdx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack<int> s;
    int output;
    s.push(1);
    s.push(2);
    s.push(3);
    s.printAll();
    while (!s.isEmpty())
    {
        cout << "current top value before popping: " << s.top() << endl;
        s.pop(output);
    }
    if(s.isEmpty()){
        cout << "Stack is empty now";
    }
}