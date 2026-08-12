# Exponential Search

## Problem Statement

Given a sorted array and a target value, find the index of the target using the **Exponential Search** algorithm.

Exponential Search first finds a suitable range in which the target may exist by repeatedly doubling the search index. It then applies **Binary Search** within that range.

## Example

### Input

```text
Array: 2 5 8 12 16 23 38 45 57 64 72
Target: 45 
