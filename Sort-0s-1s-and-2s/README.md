# Sort an Array of 0s, 1s, and 2s

## Problem Statement

Given an array containing only `0`s, `1`s, and `2`s, write a C++ program to sort the array in ascending order.

The solution should count the occurrences of each element and then overwrite the array with the correct number of `0`s, `1`s, and `2`s.

## Example

**Input**

```text
{0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1}
```

**Output**

```text
0 0 0 0 0 1 1 1 1 2 2 2
```

## Approach

1. Traverse the array once to count the number of `0`s, `1`s, and `2`s.
2. Overwrite the array:

   * Fill the first `count0` positions with `0`.
   * Fill the next `count1` positions with `1`.
   * Fill the remaining positions with `2`.
3. Print the sorted array.

## Time Complexity

* **O(n)**

## Space Complexity

* **O(1)**

## Concepts Practiced

* Arrays
* Frequency Counting
* Array Traversal
* Conditional Statements
* In-place Array Modification

## File

* `sort-0s-1s-and-2s.cpp`
