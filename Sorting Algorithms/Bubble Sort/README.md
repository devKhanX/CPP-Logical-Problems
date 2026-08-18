# bubble-sort.cpp

A C++ program implementing **Bubble Sort** with an early-exit optimization, sorting a `std::vector<int>` in ascending order.

## The code

```cpp
#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}
void printArray(const vector<int>& arr)
{
    cout << "Sorted Array" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {4, 1, 5, 2, 3};
    bubbleSort(arr);
    printArray(arr);
    return 0;
}
```

## How it works

### `bubbleSort(vector<int>& arr)`

Sorts `arr` in place (passed by non-const reference so the original vector is modified):

1. The **outer loop** (`i`) runs up to `n - 1` passes over the array.
2. The **inner loop** (`j`) compares each pair of adjacent elements `arr[j]` and `arr[j+1]`. If they're out of order (`arr[j] > arr[j+1]`), they're swapped with `std::swap`. This "bubbles" the largest unsorted element to its correct position at the end of the unsorted portion on each pass.
3. `n - i - 1` shrinks the inner loop's range on each outer pass, since the last `i` elements are already guaranteed sorted from previous passes.
4. **Early-exit optimization:** `isSwap` tracks whether any swap happened during a pass. If a full pass completes with no swaps, the array is already sorted, so the function `return`s immediately instead of doing unnecessary further passes.

### `printArray(const vector<int>& arr)`

Prints `"Sorted Array"` followed by every element of `arr`, space-separated.

### `main()`

Creates `arr = {4, 1, 5, 2, 3}`, sorts it with `bubbleSort`, then prints the result with `printArray`.

## Example walkthrough

Starting array: `{4, 1, 5, 2, 3}`

**Pass 1** (`i=0`, compares indices 0–3):
- `4,1` → swap → `{1,4,5,2,3}`
- `4,5` → no swap
- `5,2` → swap → `{1,4,2,5,3}`
- `5,3` → swap → `{1,4,2,3,5}`

**Pass 2** (`i=1`, compares indices 0–2):
- `1,4` → no swap
- `4,2` → swap → `{1,2,4,3,5}`
- `4,3` → swap → `{1,2,3,4,5}`

**Pass 3** (`i=2`, compares indices 0–1):
- `1,2` → no swap
- `2,3` → no swap
- No swaps this pass → `isSwap` stays `false` → function returns early.

Final sorted array: `{1, 2, 3, 4, 5}`

**Output:**
```
Sorted Array
1 2 3 4 5 
```

## Complexity

- **Time:** O(n²) worst/average case, O(n) best case (already-sorted input) thanks to the early-exit check.
- **Space:** O(1) additional space — sorting is done in place.
- **Stable:** Yes — bubble sort never reorders equal elements relative to each other.

## Key takeaway

This is a textbook bubble sort with the classic "no swaps this pass → already sorted, stop early" optimization, which improves the best-case time complexity from O(n²) to O(n) for already-sorted or nearly-sorted input.

## Compiling & running

```bash
g++ bubble-sort.cpp -o bubble-sort
./bubble-sort
```

## Requirements

- A C++ compiler (C++11 or later recommended)
