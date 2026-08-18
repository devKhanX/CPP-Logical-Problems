# selection-sort.cpp

A C++ program implementing **Selection Sort**, sorting a `std::vector<int>` in ascending order.

## The code

```cpp
#include <iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&arr)
{
    int n=arr.size();
    for (int i=0;i<n;i++)
    {
        int smallestIdx=i;
        for (int j=i;j<n;j++)
        {
            if(arr[j]<arr[smallestIdx])
            {
                smallestIdx=j;
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
}
void printArray(vector<int>&arr)
{
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int> arr={4,1,5,2,3};
    selectionSort(arr);
    printArray(arr);
}
```

## How it works

### `selectionSort(vector<int>& arr)`

Sorts `arr` in place (passed by non-const reference so the original vector is modified):

1. The **outer loop** (`i`) moves through each position of the array from left to right, marking the boundary between the "sorted" portion (indices `< i`) and the "unsorted" portion (indices `>= i`).
2. For each `i`, `smallestIdx` is initialized to `i`, assuming the current position already holds the smallest remaining value.
3. The **inner loop** (`j`, starting at `i`) scans the unsorted portion of the array, updating `smallestIdx` whenever it finds an element smaller than the current smallest found so far.
4. After scanning, `swap(arr[i], arr[smallestIdx])` places the smallest remaining element into position `i`.
5. This repeats for every `i`, progressively growing the sorted portion at the front of the array until the whole array is sorted.

### `printArray(vector<int>& arr)`

Prints `"Sorted Array"` followed by every element of `arr`, space-separated.

### `main()`

Creates `arr = {4, 1, 5, 2, 3}`, sorts it with `selectionSort`, then prints the result with `printArray`.

## Example walkthrough

Starting array: `{4, 1, 5, 2, 3}`

**i=0:** scan indices 0–4 for the smallest → `1` at index 1. Swap `arr[0]` and `arr[1]` → `{1, 4, 5, 2, 3}`

**i=1:** scan indices 1–4 for the smallest → `2` at index 3. Swap `arr[1]` and `arr[3]` → `{1, 2, 5, 4, 3}`

**i=2:** scan indices 2–4 for the smallest → `3` at index 4. Swap `arr[2]` and `arr[4]` → `{1, 2, 3, 4, 5}`

**i=3:** scan indices 3–4 for the smallest → `4` at index 3 (already smallest). Swap `arr[3]` with itself → `{1, 2, 3, 4, 5}` (unchanged)

**i=4:** scan index 4 only → `5` at index 4 (already smallest). Swap `arr[4]` with itself → `{1, 2, 3, 4, 5}` (unchanged)

Final sorted array: `{1, 2, 3, 4, 5}`

**Output:**
```
Sorted Array
1 2 3 4 5 
```

## Complexity

- **Time:** O(n²) in all cases (best, average, and worst) — the inner loop always scans the full remaining unsorted portion regardless of whether the array is already sorted, since there's no early-exit check like in optimized bubble sort.
- **Space:** O(1) additional space — sorting is done in place.
- **Stable:** No — selection sort can change the relative order of equal elements, since it swaps the found minimum into place rather than shifting elements incrementally.
- **Swaps:** At most `n` swaps total (one per outer-loop iteration, even if it's a no-op self-swap), which makes selection sort useful when swap/write operations are expensive relative to comparisons.

## Key takeaway

This is a textbook selection sort: repeatedly find the minimum of the remaining unsorted elements and swap it into place. Unlike bubble sort, its number of comparisons is always O(n²) regardless of input order, but its number of swaps is minimal (O(n)).

## Compiling & running

```bash
g++ selection-sort.cpp -o selection-sort
./selection-sort
```

## Requirements

- A C++ compiler (C++11 or later recommended)
