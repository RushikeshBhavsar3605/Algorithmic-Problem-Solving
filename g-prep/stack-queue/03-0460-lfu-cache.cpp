#include "template.hpp"

class Node {
  public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
  public:
    Node *head, *tail;
    int size;

    DoublyLinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
        size++;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node *removeLast() {
        if (size == 0)
            return nullptr;

        Node *node = tail->prev;
        remove(node);
        return node;
    }
};

/* Approach (Hashing + Doubly Linked List): */
class LFUCache {
  private:
    int capacity;
    int minFreq;

    umap<int, Node *> keyToNode;
    umap<int, DoublyLinkedList *> freqMap;

    void updateFrequency(Node *node) {
        int freq = node->freq;
        freqMap[freq]->remove(node);

        if (freq == minFreq && freqMap[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (!freqMap.count(node->freq))
            freqMap[node->freq] = new DoublyLinkedList();

        freqMap[node->freq]->addFront(node);
    }

  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyToNode.count(key))
            return -1;

        Node *node = keyToNode[key];
        updateFrequency(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToNode.count(key)) {
            Node *node = keyToNode[key];
            node->value = value;
            updateFrequency(node);
            return;
        }

        if (sz(keyToNode) == capacity) {
            Node *node = freqMap[minFreq]->removeLast();
            keyToNode.erase(node->key);
            delete node;
        }

        Node *node = new Node(key, value);
        minFreq = 1;

        if (!freqMap.count(1))
            freqMap[1] = new DoublyLinkedList();

        freqMap[1]->addFront(node);
        keyToNode[key] = node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    print(lfu.get(1));
    lfu.put(3, 3);
    print(lfu.get(2));
    print(lfu.get(3));
    lfu.put(4, 4);
    print(lfu.get(1));
    print(lfu.get(3));
    print(lfu.get(4));
    return 0;
}

/*
Problem: LFU Cache
*/