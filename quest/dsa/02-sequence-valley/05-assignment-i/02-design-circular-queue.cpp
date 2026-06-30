#include "template.hpp"

/* Approach (Simulation): */
class MyCircularQueue {
  private:
    vi nums;
    int front, rear;
    int size, capacity;

  public:
    MyCircularQueue(int k) {
        nums.resize(k, 0);
        front = rear = size = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (size == capacity)
            return false;

        nums[rear] = value;
        rear = (rear + 1) % capacity;
        size++;

        return true;
    }

    bool deQueue() {
        if (size == 0)
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    int Front() {
        if (size == 0)
            return -1;

        return nums[front];
    }

    int Rear() {
        if (size == 0)
            return -1;

        return nums[(rear + capacity - 1) % capacity];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MyCircularQueue obj(3);
    print(obj.enQueue(1));
    print(obj.enQueue(2));
    print(obj.enQueue(3));
    print(obj.enQueue(4));
    print(obj.Rear());
    print(obj.isFull());
    print(obj.deQueue());
    print(obj.enQueue(4));
    print(obj.Rear());
    return 0;
}

/*
Problem: Design Circular Queue
*/