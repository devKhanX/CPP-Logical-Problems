# Rearrange Array Alternating Positive and Negative

## Problem Statement

Given an array containing positive and negative integers, rearrange the elements so that positive and negative numbers appear alternately.

The positive numbers should be placed at even indices, while negative numbers should be placed at odd indices.

## Example

**Input:**

```text
3 1 -2 -5 2 -4
```

**Output:**

```text
3 -2 1 -5 2 -4
```

## Approach

The program uses a separate output array and maintains two positions:

* `pos` starts at index `0` for positive numbers.
* `neg` starts at index `1` for negative numbers.

For every element in the input array:

1. If the element is positive, place it at the current positive position and increase the position by `2`.
2. If the element is negative, place it at the current negative position and increase the position by `2`.
3. Finally, print the output array.

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

## Concepts Practiced

* Arrays
* Array traversal
* Positive and negative numbers
* Index manipulation
* Building a result array
* Problem-solving

## File

`rearrange-array-alternating-positive-negative.cpp`
