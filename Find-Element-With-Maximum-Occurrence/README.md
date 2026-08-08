# Find Element With Maximum Occurrence

## Problem Statement

Given an integer array, find the element that occurs the maximum number of times.

If multiple elements have the same maximum frequency, the program returns the element encountered first with that frequency.

## Example

**Input:**

```text
{2, 3, 5, 4, 5, 3, 4, 7}
```

**Output:**

```text
The number with maximum occurrence is 3
```

## Approach

The program uses two nested loops:

1. Select each element of the array.
2. Traverse the entire array to count how many times that element occurs.
3. Compare its frequency with the current maximum frequency.
4. If its frequency is greater, update the maximum frequency and the corresponding element.
5. Print the element with the highest occurrence.

## Time Complexity

* **O(n²)**

## Space Complexity

* **O(1)**

## Concepts Practiced

* Arrays
* Nested loops
* Frequency counting
* Conditional statements
* Traversing arrays
* Problem solving

## File

`find-element-with-maximum-occurrence.cpp`
