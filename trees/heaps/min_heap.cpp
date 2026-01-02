/*
Min heap: TOP(Root) par hmsha sab sy chooti value rhti hai.
root index: 1
parent index: childIdx / 2
left child index : parentIdx * 2
Right child index : (parentIdx * 2 ) + 1

Min Heap Insertion Logic: hum hmsha sab sy end par insert krty hai, phir hum check krty,
kya yeh new values, apny parent sy chooti hai? agr han tuo hum parent sath swap kar dety hai,
and phir yeh checking/process repeat krty, jab tak new value apny parent sy bari na hojye
----agr bari ho tuo simply udhr hi store krwa dety

Min Heap Deletion Logic: hum hmsha Root node(1 index) sy value remove krty hai,
isky liye hum sab sy end wali value ko root par ly aty hai,
phir hum dono child (left & right) sath compair krty hai,
jo child choota hoga usky sath hum dobra swap kar dy gy,
and yeh steps repeat kary gy,
jab tak dono child bary na hojye apny parent sy.
*/

#include <iostream>
using namespace std;

template <typename T>
class MinHeap
{
private:
    T *heap;
    int capacity;
    int heapSize;

    void doubleHeapSize()
    {
        int newCapacity = capacity * 2;
        T *temp = new T[newCapacity + 1];

        for (int i = 1; i <= heapSize; i++)
        {
            temp[i] = heap[i];
        }

        delete[] heap;
        heap = temp;
        capacity = newCapacity;
    }

public:
    MinHeap(int cap = 10)
    {
        capacity = cap;
        heapSize = 0;
        heap = new T[capacity + 1];
    }

    void insert(T val)
    {
        if (heapSize == capacity)
        {
            doubleHeapSize();
        }
        heapSize++;
        int currentNode = heapSize;

        while (currentNode != 1 && heap[currentNode / 2] > val)
        {
            heap[currentNode] = heap[currentNode / 2];
            currentNode /= 2;
        }

        heap[currentNode] = val;
    }

    bool remove(T &output)
    {
        if (heapSize == 0)
        {
            return false;
        }

        int currentNode = 1;
        int child = 2;
        T LastValue = heap[heapSize--];
        output = heap[1];
        bool isParentLarger = true;

        while (child <= heapSize && isParentLarger)
        {
            if (child < heapSize && heap[child] > heap[child + 1])
            {
                child++;
            }

            if (LastValue <= heap[child])
            {
                isParentLarger = false;
            }
            else
            {
                heap[currentNode] = heap[child];
                currentNode = child;
                child = child * 2;
            }
        }
        heap[currentNode] = LastValue;
        return true;
    }

    void printAll()
    {
        for (int i = 1; i <= heapSize; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap()
    {
        delete[] heap;
    }
};

int main()
{
    MinHeap<int> h(5);
    int output;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(40);

    cout << "Min Heap: ";
    h.printAll();
    if (h.remove(output))
    {
        cout << "Removed Min: " << output << endl;
    }
    cout << "Heap after removal: ";
    h.printAll();
}