# Find Unique Element in an Array

## Problem Statement

Given an integer array where every element appears multiple times except one, write a C++ program to find and print the element that appears exactly once.

## Example

**Input Array**

```text
{2, 3, 5, 4, 5, 3, 4}
```

**Output**

```text
Number that appears once: 2
```

## Approach

The program uses two nested loops:

1. Traverse each element of the array.
2. Count how many times the current element appears in the entire array.
3. If the count is equal to `1`, print the element and terminate the search.

## Time Complexity

* **O(n²)**

## Space Complexity

* **O(1)**

## Concepts Practiced

* Arrays
* Nested Loops
* Frequency Counting
* Conditional Statements
* Problem Solving

## File

* `find-unique-element.cpp`
