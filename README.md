# Data Structures in C
A collection of classic data structures implemented in C. This repository currently includes a **fully functional singly linked list** with robust insert, remove, and iterate operations.

## Features
- Singly linked list
  - Insert at head, tail, or middle
  - Remove from head, tail, or middle
  - Iterate over all elements
  - Proper memory management (nodes and data freed)
- Stress-tested with edge cases (empty list, out-of-bounds operations)
- Ready for extension to other data structures

## Getting Started

### Prerequisites
- C compiler (GCC, Clang, or MSVC)
- CMake 3.16+ (for building with CLion or command-line)
- Git (for cloning)

### Build Instructions
Clone the repository:
```bash
git clone https://github.com/Jeff-Andrade/data-structures.git
cd data-structures
````

Using **CMake**:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This will create the executable (by default `data_structures`).

### Run

```bash
./data_structures
```

On Windows, replace `./data_structures` with the path to the executable (e.g., `data_structures.exe`).

## Project Structure

```
data-structures/
├── LinkedList/       # Linked list source and header files
│   ├── list.c
│   ├── list.h
│   ├── listnode.c
│   └── listnode.h
├── main.c            # Example usage
├── CMakeLists.txt    # Build instructions
├── .gitignore
└── README.md
```

## Usage Example

```c
#include "list.h"
#include <stdlib.h>

int main() {
    int* value = malloc(sizeof(int));
    *value = 10;
    LinkedList* list = initialize_list(value);

    int* another = malloc(sizeof(int));
    *another = 20;
    list_insert(list, another, 1);  // insert at end

    int* more = malloc(sizeof(int));
    *more = 30;
    list_insert(list, more, 0);  // insert at head

    list_iterate(list);  // prints all elements

    // Free remaining data (list_remove frees nodes and data)
    return 0;
}
```

## Future Releases Roadmap

This repository is designed to grow into a comprehensive collection of classical data structures implemented in C. The planned future releases include:

### 1. Linear Data Structures

* **Arrays**
  * Static arrays
  * Dynamic (resizable) arrays
* **Linked Lists**
  * Doubly linked list
  * Circular linked list
* **Stacks**
  * Array-based and linked-list-based
* **Queues**
  * Simple queue
  * Circular queue / ring buffer
  * Priority queue
* **Deques** (double-ended queues)

### 2. Hierarchical / Tree Structures
* **Binary Trees**
* **Binary Search Trees (BST)**
* **Self-balancing Trees**
  * AVL tree
  * Red-Black tree
* **N-ary Trees**
* **Tries** (prefix trees)
* **Heaps**
  * Min-heap
  * Max-heap
  * Binary heap
### 3. Graph Structures
* **Graph Representations**
  * Adjacency list
  * Adjacency matrix
* **Graph Types**
  * Directed / Undirected
  * Weighted / Unweighted
* **Graph Algorithms**
  * BFS (Breadth-First Search)
  * DFS (Depth-First Search)
  * Dijkstra’s shortest path
  * Prim’s and Kruskal’s MST algorithms
### 4. Hash-based Structures
* **Hash Tables / Hash Maps**
  * Chaining and open addressing
* **Sets**
  * Implemented via hash table or BST
* **Maps / Dictionaries**

### 5. Specialized / Miscellaneous Structures
* Circular buffers
* Disjoint-set / Union-Find
* Skip lists
* Stacks with min/max tracking

**Note:**
Each data structure will be fully implemented in C with proper memory management, accompanied by example usage and optional stress tests. The goal is to provide a **robust, educational, and extendable library** for C programmers.
