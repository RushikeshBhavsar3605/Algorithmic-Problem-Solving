# Heaps: Quick Reference Playbook

Use this table to immediately pattern-match the problem to the solution and grab the code.

| The Problem (When to use)                                                                       | The Pattern (How to solve)                                                                                                                                                      | Code Reference                                                                      |
| :---------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | :---------------------------------------------------------------------------------- |
| **Heap Fundamentals**<br>Need to build a heap from scratch or sort in-place `O(N log N)`.       | **Array Math:** `leftChild = 2*i + 1`, `rightChild = 2*i + 2`. Use `heapify` to bubble up/push down.                                                                            | `01-introduction.cpp`                                                               |
| **Top K / Kth Extremum**<br>Find the Kth largest/smallest in an array, stream, or by frequency. | **Min/Max Heap of size K:** To find Kth _largest_, maintain a Min-Heap of size K. Push elements; if size > K, pop. Root is the answer.                                          | `02-0215-Kth-largest...`<br>`07-0703-Kth-largest...`<br>`09-0347-top-k-frequent...` |
| **K-Way Merge**<br>Combine multiple sorted streams (Linked Lists, Twitter Feeds).               | **Min/Max Heap of Heads:** Push the first element of each stream into the heap. Pop the extremum, append to result, and push the _next_ element from that popped node's stream. | `03-0023-merge-k-sorted...`<br>`06-0355-design-twitter.cpp`                         |
| **Running Median**<br>Track the median of a continuous, infinite stream.                        | **Two Heaps:** Max-Heap (smaller half) + Min-Heap (larger half). Push to max, rebalance to min. Ensure size difference is never > 1.                                            | `08-0295-find-median...`                                                            |
| **Scheduling & Cooldowns**<br>Run tasks with cooldowns or group items sequentially.             | **Heap + Queue/Map:** Max-Heap (most frequent task first) + FIFO Queue (cooldown waiting room). For exact groupings, use Min-Heap + frequency map.                              | `04-0621-task-scheduler.cpp`<br>`05-0846-hand-of-straights.cpp`                     |

## C++ STL Cheat Sheet

Because everyone forgets the exact syntax during high-pressure situations:

**Max-Heap (Default)**

```cpp
priority_queue<int> maxHeap;
```

**Min-Heap**

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

**Custom Comparator (e.g., Min-Heap of Pairs based on first element)**

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
```
