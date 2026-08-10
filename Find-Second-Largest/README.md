# Find Second Largest Element

## Problem Statement

Given an integer array, find the **largest** and **second largest** elements in the array.

The second largest element should be the largest element that is strictly smaller than the largest element.

## Example

**Input:**

```text
33 22 66 77 88
```

**Output:**

```text
Largest: 88
Second largest: 77
```

## Approach

The program uses two traversals:

1. Traverse the array to find the largest element.
2. Traverse the array again and find the largest element that is smaller than the largest element.
3. Print both values.

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

## Concepts Practiced

* Arrays
* Array traversal
* Finding maximum values
* Conditional statements
* Problem solving

## File

`find-second-largest.cpp`
