## 🚀 Phase 1: Syntax Crash Course (15 mins)

#### 🧾 Input/Output

```python
n = int(input())
arr = list(map(int, input().split()))
```

#### 🔁 Loops

```python
for i in range(5):        # 0 to 4
for i in range(1, 6):     # 1 to 5
```

#### 🔀 Conditionals

```python
if x > 5:
elif x == 5:
else:
```

#### 🧮 Functions

```python
def add(a, b):
    return a + b
```

## 🧰 Phase 2: Python for DSA Toolkit (20 mins)

#### 📋 Lists (C++ vector)

```python
arr = [1, 2, 3]
arr.append(4)
arr.pop()
arr.sort()
arr.reverse()
arr[1:3]  # slicing
```

#### 🧺 Sets (C++ unordered_set)

```python
s = set()
s.add(1)
s.remove(1)
1 in s
```

#### 🗺️ Dictionaries (C++ unordered_map)

```python
d = {}
d['a'] = 1
if 'a' in d:
    print(d['a'])
```

#### 🐍 Heaps

```python
import heapq
heapq.heappush(heap, val)
heapq.heappop(heap)
```

**Max heap**

```python
heapq.heappush(heap, -val)
-max_heap_val = heapq.heappop(heap)
```

#### 🔄 Queue / Deque

```python
from collections import deque
q = deque()
q.append(1)
q.popleft()
```

## 💡 Phase 3: Pythonic Tricks (15 mins)

#### 🧠 One-liner Input

```python
arr = [int(x) for x in input().split()]
```

#### 🔢 Frequency Count

```python
from collections import Counter
cnt = Counter(arr)
```

#### 🧮 Defaultdict

```python
from collections import defaultdict
graph = defaultdict(list)
graph[0].append(1)
```

#### 🧾 Enumerate

```python
for idx, val in enumerate(arr):
```

#### 🔤 Lambda Sort

```python
arr.sort(key=lambda x: x[1])
```

### 📚 Ordered Map / Set in Python

#### ✅ Ordered Map (like C++ map)

**Sorted by key:**

```python
data = {3: "c", 1: "a", 2: "b"}
sorted_map = dict(sorted(data.items()))
```

**Insertion order:**

```python
from collections import OrderedDict
ordered_map = OrderedDict()
```

#### ✅ Ordered Set

**Using dict keys:**

```python
ordered_set = dict.fromkeys([3, 1, 2])
```

**Using OrderedDict:**

```python
from collections import OrderedDict
ordered_set = OrderedDict()
ordered_set[3] = None
```

### ⚙️ SortedContainers (Like C++ map / set)

**Install:**

```bash
pip install sortedcontainers
```

#### 🔹 SortedDict

```python
from sortedcontainers import SortedDict
sd = SortedDict()
sd[5] = "five"
sd[1] = "one"
```

#### 🔹 SortedSet

```python
from sortedcontainers import SortedSet
ss = SortedSet([3, 1, 2])
```

## 🔁 C++ to Python Equivalents

| C++           | Python                    |
| ------------- | ------------------------- |
| map           | SortedDict, dict + sort() |
| unordered_map | dict                      |
| set           | SortedSet (external)      |
| unordered_set | set                       |
