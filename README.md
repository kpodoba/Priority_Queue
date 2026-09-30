# Bounded Priority Queue (C++)

Header-only C++ library for priority queues with support for various data types. `BoundedPriorityQueue<T>` has a size limit: when full, it discards the lowest-priority elements.

## Features

- Generic (`template <typename T>`), no external dependencies
- Higher number = higher priority; FIFO order for equal priorities
- Configurable maximum size (default: 10), changeable at runtime
- Element lookup with `contains()`

## Files

- `PriorityQueue.hpp` - `Node<T>` and abstract `PriorityQueue<T>`
- `BoundedPriorityQueue.hpp` - `BoundedPriorityQueue<T>`
- `main.cpp` - usage examples

Everything is in the `kp` namespace.

## Build and run

```bash
g++ -std=c++17 main.cpp -o priority_queue
./priority_queue
```

## Usage

```cpp
#include "BoundedPriorityQueue.hpp"

kp::BoundedPriorityQueue<std::string> queue(3);

queue.insert(10, "low");
queue.insert(20, "high");
queue.insert(15, "medium");
queue.insert(30, "urgent");   // full -> "low" is discarded

while (!queue.isEmpty()) {
    std::cout << queue.pop() << std::endl;   // urgent, high, medium
}
```

When the queue is full, a new element replaces the lowest one only if its priority is strictly higher; otherwise it is ignored.

## API

- `BoundedPriorityQueue()` / `BoundedPriorityQueue(size_t maxSize)` - constructors
- `insert(int priority, const T& value)` - adds an element
- `T pop()` - removes and returns the highest-priority element (`T()` if empty)
- `setMaxSize(size_t)` / `getMaxSize()` - changes / returns the size limit
- `contains(int priority, const T& value)` - checks if an element exists
- `isEmpty()`, `size()`, `printQueue()` - inherited from `PriorityQueue<T>`
