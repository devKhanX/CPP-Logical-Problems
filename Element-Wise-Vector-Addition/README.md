# Element-Wise-vector-Addition.cpp

A C++ program that performs **element-wise addition** of two `std::vector<int>` objects, with validation that both vectors are non-empty and of equal size before combining them.

## The code

```cpp
#include <iostream>
#include <vector> 
using namespace std;
void elementWiseAdd(const vector<int>& arr1, const vector<int>& arr2) 
{
    if (arr1.empty() || arr1.size() != arr2.size()) 
	{
        cout << "Error: Vectors must be non-empty and of equal size." << endl;
        return;
    }
    vector<int> arr3;
    for (int i = 0; i < arr1.size(); i++) 
	{
        arr3.push_back(arr1[i] + arr2[i]);
    }
    for (int i = 0; i < arr3.size(); i++) 
	{
        cout << arr3[i] << " ";
    }
    cout << endl;
}
int main() 
{
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
   	elementWiseAdd(arr1, arr2);
    return 0;
}
```

## How it works

### `elementWiseAdd(const vector<int>& arr1, const vector<int>& arr2)`

Both vectors are passed **by const reference**, avoiding unnecessary copies while ensuring the function cannot modify the caller's data.

1. **Validation** — `if (arr1.empty() || arr1.size() != arr2.size())`: guards against two problem cases — an empty vector, or vectors of mismatched sizes (which would make element-wise addition undefined/meaningless). If either condition is true, an error message is printed and the function returns early, without touching `arr3`.
2. **Element-wise sum** — A new vector `arr3` is built by iterating over the indices of `arr1` (equivalently `arr2`, since sizes match) and pushing the sum `arr1[i] + arr2[i]` for each position.
3. **Printing** — A second loop prints every element of `arr3`, separated by spaces, followed by a newline.

### `main()`

Two vectors are created:
```cpp
arr1 = {2, 4, 3}
arr2 = {5, 6, 4}
```
and passed to `elementWiseAdd`.

## Example walkthrough

| Index | arr1[i] | arr2[i] | arr3[i] = arr1[i] + arr2[i] |
|-------|---------|---------|------------------------------|
| 0     | 2       | 5       | 7                            |
| 1     | 4       | 6       | 10                           |
| 2     | 3       | 4       | 7                            |

**Output:**
```
7 10 7 
```

## Edge cases handled

- **Empty vectors:** If either `arr1` or `arr2` is empty, the function prints an error and skips the addition.
- **Mismatched sizes:** If `arr1.size() != arr2.size()`, the function prints an error rather than attempting to index out of bounds. This is what makes the program well-defined — without this check, iterating past the shorter vector's bounds (or the longer one's) would risk undefined behavior.

## Key takeaway

This program is a straightforward, well-defined example of validating preconditions (non-empty, equal-length inputs) before performing an element-wise operation on two `std::vector<int>` — a common and important pattern anywhere vectors, arrays, or matrices are combined position-by-position.

## Compiling & running

```bash
g++ element-wise-vector-addition.cpp -o element-wise-vector-addition
./element-wise-vector-addition
```

## Requirements

- A C++ compiler (C++11 or later recommended)
