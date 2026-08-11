# Binary Search

## Problem Statement

Given a **sorted array** of integers, search for a given number and determine whether it exists in the array.

If the number is found, display its index. Otherwise, display a message indicating that the value was not found.

## Example

**Array:**

```text
10 20 30 40 50 60 70 80 90 100
```

**Input:**

```text
70
```

**Output:**

```text
70 Found at index 6
```

## Approach

The program uses **Binary Search**:

1. Set `start` to the first index and `end` to the last index.
2. Calculate the middle index.
3. If the middle element equals the target, the search is complete.
4. If the target is smaller than the middle element, search the left half.
5. If the target is larger than the middle element, search the right half.
6. Continue until the element is found or the search range becomes empty.

## Important Condition

Binary Search requires the array to be **sorted**.

## Complexity

* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)

## Concepts Practiced

* Arrays
* Binary Search
* Searching Algorithms
* Array Indexing
* Divide-and-Conquer Approach
* Conditional Statements

## File

`binary-search.cpp`
