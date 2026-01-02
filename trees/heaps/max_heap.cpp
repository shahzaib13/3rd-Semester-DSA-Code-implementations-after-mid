/*
Max heap: TOP(Root) par hmsha sab sy bari value rhti hai.
root index: 1
parent index: childIdx / 2
left child index : parentIdx * 2 
Right child index : (parentIdx * 2 ) + 1

Max Heap Insertion Logic: hum hmsha sab sy end par insert krty hai, phir hum check krty,
kya yeh new values, apny parent sy bari hai? agr han tuo hum parent sath swap kar dety hai,
and phir yeh checking/process repeat krty, jab tak new value apny parent sy chooti na hojye
----agr chooti ho tuo simply udhr hi store krwa dety

Max Heap Deletion Logic: hum hmsha Root node(1 index) sy value remove krty hai,
isky liye hum sab sy end wali value ko root par ly aty hai,
phir hum dono child (left & right) sath compair krty hai,
jo child bara hoga usky sath hum dobra swap kar dy gy,
and yeh steps repeat kary gy,
jab tak dono child small na hojye apny parent sy.
*/
#include <iostream>
using namespace std;

template <typename T>
class MaxHeap {

    T* heap;
    int capacity;
    int heapSize;

    void doubleHeapSize() {
        int newCapacity = capacity * 2;
        T* newHeap = new T[newCapacity + 1];

        for (int i = 1; i <= heapSize; i++) {
            newHeap[i] = heap[i];
        }

        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    MaxHeap(int cap = 10) {
        capacity = cap;
        heapSize = 0;
        heap = new T[capacity + 1];
    }

    void insert(T val) {
        if (heapSize == capacity) {
            doubleHeapSize();
        }
        heapSize++;
        int currentNode = heapSize;

        while (currentNode != 1 && heap[currentNode / 2] < val) {
            heap[currentNode] = heap[currentNode / 2];
            currentNode /= 2;
        }

        heap[currentNode] = val;
    }

    bool remove(T &output) {
        if (heapSize == 0) {
            return false;
        }

        int currentNode = 1;
        int child = 2;
        T LastValue = heap[heapSize--];
        output = heap[1];
        
        bool isParentSmaller = true;
        while (child <= heapSize && isParentSmaller) {
            if (child < heapSize && heap[child] < heap[child + 1]) {
                child++;
            }

            if (LastValue >= heap[child]) {
                isParentSmaller = false;
            } else {
                heap[currentNode] = heap[child];
                currentNode = child;
                child = child * 2;
            }
        }
        heap[currentNode] = LastValue;
        return true;
    }

    void print() {
        for (int i = 1; i <= heapSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    MaxHeap<int> h(5);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(5);
    h.insert(60);

    cout << "Heap: ";
    h.print();

    int deletedVal;
    if (h.remove(deletedVal)) {
        cout << "Removed: " << deletedVal << endl;
    }

    cout << "Heap after removal: ";
    h.print();

    return 0;
}