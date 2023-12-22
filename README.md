# Interval Tree

This repository contains C++ implementations of an Interval Tree, including the necessary classes: `Interval`, `Node`, and `IntervalTree`. The Interval Tree is a data structure used for efficient searching and overlapping of intervals.

## Table of Contents

- [Interval Class](#interval-class)
- [Node Class](#node-class)
- [IntervalTree Class](#intervaltree-class)
- [Usage Example](#usage-example)
- [How to Use](#how-to-use)

## Interval Class

### Overview

The `Interval` class represents a closed interval [low, high]. It has methods to retrieve the low and high values of the interval.

### Methods

- `getLow()`: Returns the low endpoint of the interval.
- `getHigh()`: Returns the high endpoint of the interval.

## Node Class

### Overview

The `Node` class represents a node in the Interval Tree. It includes an interval, a maximum value, and left and right children.

### Methods

- `getInterval()`: Returns the interval associated with the node.
- `getMax()`: Returns the maximum value considering the current node's interval and its children.
- `getLeft()`: Returns the left child node.
- `getRight()`: Returns the right child node.
- `setInterval(Interval* interval)`: Sets the interval for the node.
- `setMax(int max)`: Sets the maximum value for the node.
- `setLeft(Node* left)`: Sets the left child node.
- `setRight(Node* right)`: Sets the right child node.

## IntervalTree Class

### Overview

The `IntervalTree` class represents the Interval Tree data structure. It includes methods for inserting intervals, searching for overlapping intervals, and printing the tree.

### Methods

- `insert(Interval* interval)`: Inserts a new interval into the tree.
- `search(const Interval* interval)`: Searches for an overlapping interval with the given interval.
- `inOrder()`: Prints the nodes of the tree in order.

## Usage Example

```cpp
#include "Classes/IntervalTree.h"

int main() {
    Interval* intervals[] = {new Interval(15, 20), new Interval(10, 30), new Interval(17, 19),
        new Interval(5, 20), new Interval(12, 15), new Interval(30, 40)};

    auto* tree = new IntervalTree();

    for (auto & interval : intervals)
        tree->insert(interval);

    tree->inOrder();

    const Interval* searchList[] = {new Interval(6, 7), new Interval(1, 2), new Interval(10, 50),
        new Interval(12, 17), new Interval(4, 10), new Interval(-50, 10)};

    // should print {[5, 20], No, No, [15, 20], [10, 30], [10, 30]}
    for (auto & interval : searchList) {
        std::cout << "\nSearching for interval [" << interval->getLow() << "," << interval->getHigh() << "]";

        if (const Interval* result = tree->search(interval); result == nullptr)
            std::cout << "\nNo Overlapping Interval";
        else
            std::cout << "\nOverlaps with [" << result->getLow() << ", " << result->getHigh() << "]";
    }

    return 0;
}
```

## How to Use

1. Clone the repository.
2. Include the necessary header files (`Interval.h`, `Node.h`, `IntervalTree.h`) in your project.
3. Create an instance of the `IntervalTree` class and use its methods to insert intervals, search for overlaps, and print the tree.

Feel free to explore and modify the code to suit your specific requirements.
