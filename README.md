# Binary Search Tree (BST) Implementation in C++

This is a comprehensive implementation of a Binary Search Tree (BST) in C++. A BST is a data structure that maintains a sorted set of elements, allowing for efficient insertion, deletion, and search operations.

## Features

- **Insertion**: Add elements to the tree while maintaining the sorted order.
- **Deletion**: Remove elements from the tree.
- **Searching**: Find elements in the tree.
- **Minimum and Maximum Value**: Get the minimum and maximum values stored in the tree.
- **Traversals**: Perform in-order, pre-order, and post-order tree traversals.
- **Height Calculation**: Determine the height of the tree.
- **Copy and Move Semantics**: Support for copying and moving trees.

## Usage

To use this BST implementation, follow these steps:

1. Include the `bst.hpp` header file in your C++ program.

```cpp
#include "bst.hpp"
```

2. Create an instance of the `BST` class, specifying the data type of the elements you want to store in the tree.

```cpp
BST<int> my_tree; // Create an instance of BST to store integers
```

3. Use the provided functions to interact with the BST. Here are some examples:

### Insertion

Insert elements into the tree. The tree will maintain its sorted order.

```cpp
my_tree.insert(42);
my_tree.insert(15);
my_tree.insert(60);
my_tree.insert(30);
```

### Deletion

Remove elements from the tree.

```cpp
my_tree.remove(15);
my_tree.remove(60);
```

### Searching

Search for elements in the tree.

```cpp
bool found = my_tree.search(42); // Returns true
bool not_found = my_tree.search(99); // Returns false
```

### Minimum and Maximum Value

Find the minimum and maximum values stored in the tree.

```cpp
int min_value = my_tree.find_min(); // Returns 30
int max_value = my_tree.find_max(); // Returns 42
```

### Height Calculation

Calculate the height of the tree.

```cpp
int treeHeight = my_tree.get_height(); // Returns the height of the tree
```

### Traversals

Perform different tree traversals.

#### In-order Traversal

In-order traversal visits nodes in ascending order.

```cpp
my_tree.inorder(); // Outputs elements in ascending order
```

#### Pre-order Traversal

Pre-order traversal visits the current node before its children.

```cpp
my_tree.preorder(); // Outputs elements in pre-order
```

#### Post-order Traversal

Post-order traversal visits the current node after its children.

```cpp
my_tree.postorder(); // Outputs elements in post-order
```