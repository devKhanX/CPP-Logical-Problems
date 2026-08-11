# Linear Search

## Problem Statement

Given an array of integers, search for a given number and determine whether it exists in the array.

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
Value found at index 6
```

## Approach

The program uses **Linear Search**:

1. Start from the first element of the array.
2. Compare each element with the number being searched.
3. If a match is found, store its index and stop the search.
4. If the entire array is traversed without finding the number, report that it was not found.

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

## Concepts Practiced

* Arrays
* Linear Search
* Array Traversal
* Conditional Statements
* Searching Algorithms

## File

`linear-search.cpp`
