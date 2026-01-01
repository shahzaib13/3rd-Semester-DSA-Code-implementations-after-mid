/*
Notes from Shahzaib Saleem about this program:
Update: Iss program mai hum Dynamic Array use kar rahy hain,
mtlb user runtime par size bataye ga aur utni memory allocate hogi (mtlb ky uss size ki array bany gi).
or hum iss size ko change bhi kar sakty.
Limitions : agr stack full hogyo tuo vector ki trha new banna pary gi stack ki array and uss mai data copy krna pary ga old.
*/
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *arr{nullptr};   // Pointer for Dynamic Array
    int totalCapacity; // Total number of values a stack can store
    int topIdx;        // Index of top value or numbers of elements

public:
    // Constructor: Stack ka size user se lene k liye aur memory (utny size ki array) allocate krny k liye
    Stack(int size = 10)
    {
        if (size <= 0)
        {
            size = 10; // Default size agar user ghalat input de
        }
        totalCapacity = size;
        arr = new T[totalCapacity];
        topIdx = -1;
    }

    // Destructor: Saving from Memory Leak
    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return topIdx == -1;
    }

    bool isFull()
    {
        return topIdx == totalCapacity - 1;
    }

    void push(T val)
    {
        if (isFull())
        {
            T *temp = new T[totalCapacity * 2];
            for (int i = 0; i < totalCapacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            totalCapacity = totalCapacity * 2;
        }
        topIdx++;
        arr[topIdx] = val;
    }

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

    T top()
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty");
        }
        return arr[topIdx];
    }
    int size(){
        return topIdx;
    }
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
    Stack<int> s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printAll();
}