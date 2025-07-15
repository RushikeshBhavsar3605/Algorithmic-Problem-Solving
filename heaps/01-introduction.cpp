#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class MaxHeap {
  public:
    vi tree;

    void insert(int val) {
        tree.push_back(val); // Insert at end
        int index = tree.size() - 1;

        // Bubble up to maintain max-heap property
        while (index) {
            int parent = (index - 1) / 2;

            if (tree[parent] < tree[index]) {
                swap(tree[parent], tree[index]); // Promote child if larger
                index = parent;
            } else
                return;
        }
    }

    void remove() {
        int size = tree.size();
        if (size == 0)
            return;

        tree[0] = tree.back(); // Replace root with last
        tree.pop_back();
        size--;

        int index = 0;

        // Push down to restore max-heap property
        while (index < size) {
            int largest = index;
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;

            // Find the largest among parent and children
            if (leftChild < size && tree[largest] < tree[leftChild])
                largest = leftChild;
            if (rightChild < size && tree[largest] < tree[rightChild])
                largest = rightChild;

            if (largest != index) {
                swap(tree[index], tree[largest]); // Swap with larger child
                index = largest;
            } else
                break; // Heap is valid
        }
    }

    void print() {
        loop(i, 0, tree.size())
            cout << tree[i] << " ";
        cout << endl;
    }
};

class MinHeap {
  public:
    vi tree;

    void insert(int val) {
        tree.push_back(val); // Insert at end
        int index = tree.size() - 1;

        // Bubble up to maintain min-heap property
        while (index) {
            int parent = (index - 1) / 2;

            if (tree[parent] > tree[index]) {
                swap(tree[parent], tree[index]); // Promote child if smaller
                index = parent;
            } else
                return;
        }
    }

    void remove() {
        int size = tree.size();
        if (size == 0)
            return;

        tree[0] = tree.back(); // Replace root with last
        tree.pop_back();
        size--;

        int index = 0;

        // Push down to restore min-heap property
        while (index < size) {
            int smallest = index;
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;

            // Find the smallest among parent and children
            if (leftChild < size && tree[smallest] > tree[leftChild])
                smallest = leftChild;
            if (rightChild < size && tree[smallest] > tree[rightChild])
                smallest = rightChild;

            if (smallest != index) {
                swap(tree[index], tree[smallest]); // Swap with smaller child
                index = smallest;
            } else
                break; // Heap is valid
        }
    }

    void print() {
        loop(i, 0, tree.size())
            cout << tree[i] << " ";
        cout << endl;
    }
};

void heapify(vi &tree, int index, int length) {
    int largest = index;            // Initialize largest as root
    int leftChild = index * 2 + 1;  // left child
    int rightChild = index * 2 + 2; // right child

    // If left child is larger than root
    if (leftChild < length && tree[largest] < tree[leftChild])
        largest = leftChild;

    // If right child is larger than largest so far
    if (rightChild < length && tree[largest] < tree[rightChild])
        largest = rightChild;

    // If largest is not root
    if (largest != index) {
        swap(tree[index], tree[largest]);

        // Recursively heapify the affected subtree
        heapify(tree, largest, length);
    }
}

void heapSort(vi &nums) {
    int n = nums.size();

    // Build max heap
    revloop(i, n / 2 - 1, 0)
        heapify(nums, i, n);

    // One by one extract elements from heap
    revloop(i, n - 1, 0) {
        // Move current root to end
        swap(nums[0], nums[i]);

        // Call heapify on the reduced heap
        heapify(nums, 0, i);
    }
}

int main() {
    cout << "Max Heap:" << endl;
    MaxHeap maxHeap;
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(40);
    maxHeap.insert(50);
    maxHeap.print();
    maxHeap.remove();
    maxHeap.print();
    maxHeap.remove();
    maxHeap.print();

    cout << endl << endl;

    cout << "Min Heap:" << endl;
    MinHeap minHeap;
    minHeap.insert(30);
    minHeap.insert(20);
    minHeap.insert(40);
    minHeap.insert(50);
    minHeap.print();
    minHeap.remove();
    minHeap.print();
    minHeap.remove();
    minHeap.print();

    cout << endl << endl;

    cout << "Convert Array in Max Heap:" << endl;
    vi v = {54, 53, 55, 52, 50};
    revloop(i, v.size() / 2 - 1, 0)
        heapify(v, i, v.size());
    iterate(it, v)
        cout << it << " ";

    cout << endl << endl;
    
    cout << "Heap Sort:" << endl;
    v = {1, 5, 6, 3, 4, 2, 1};
    heapSort(v);
    loop(i, 0, v.size())
        cout << v[i] << " ";
    cout << endl;
    return 0;
}

/*
Problem:
*/
/*
Insertion
30 ->      30 -> 30    ->    40    ->   40    ->    40   ->   50
           /     /  \        /  \       /  \        /  \      /  \
          20    20   40     20  30     20  30      50  30    40   30
                                      /           /         /
                                     50          20        20

Deletion
    50     ->     20     ->   20    ->  40   ->   30    ->   30
   /  \          /  \        /  \      /  \      /  \       /
  40  30        40  30      40  30    20  30    20  40     20
 /             /
20            50
*/