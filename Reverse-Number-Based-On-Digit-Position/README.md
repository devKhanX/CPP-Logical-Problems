# Reverse-Number-Based-On-Digit-Position.cpp

A C++ program that reads an integer and builds a new number using only the digits that sit at **odd positions** (counted from the leftmost/most-significant digit, 1-indexed), assembled in reverse order of processing.

## The code

```cpp
#include<iostream>
using namespace std;
int count(int num)
{
    int count = 0;
    while(num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
int rev(int num, int count)
{
    int rev = 0, rem;
    while(num > 0)
    {
        rem = num % 10;
        if(count % 2 != 0)
        {
            rev = rev * 10 + rem;
        }
        num /= 10;      
        count--;
    }
    return rev;
}
int main()
{
    int num, numCount;
    cout << "Enter number: ";
    cin >> num;
    numCount = count(num);
    cout << "Reversed number is " << rev(num, numCount);
    return 0;
}
```

## How it works

### `count(int num)`
Counts the number of digits in `num` by repeatedly dividing by 10 until it reaches 0. For example, `count(12345)` returns `5`.

### `rev(int num, int count)`
Walks through `num` one digit at a time, from the **least significant (rightmost)** digit to the most significant, using `count` as a countdown that starts at the total digit count:

- `rem = num % 10` — extracts the current rightmost digit.
- `if (count % 2 != 0)` — only keeps this digit if the countdown value `count` is odd at this step.
- If kept, the digit is appended to `rev` (`rev = rev * 10 + rem`), building up a new number.
- `num /= 10; count--;` — moves to the next digit to the left and decrements the countdown.

Because `count` starts at the total digit count and decreases by 1 with each digit processed (right to left), its value at each step equals that digit's **position counted from the left, 1-indexed**. So the condition `count % 2 != 0` keeps only the digits that sit at **odd positions from the left** (1st, 3rd, 5th, ...) of the original number — and since digits are processed right-to-left but kept ones are appended in that same right-to-left order, the surviving digits end up **reversed** relative to their original order.

### `main()`
Reads `num`, computes its digit count, and prints the result of `rev(num, numCount)`.

## Example walkthrough

For input `12345` (5 digits, positions from the left: `1`=1st, `2`=2nd, `3`=3rd, `4`=4th, `5`=5th):

| Step | num   | digit (rem) | count | odd? kept | rev after step |
|------|-------|-------------|-------|-----------|-----------------|
| 1    | 12345 | 5           | 5     | yes       | 5               |
| 2    | 1234  | 4           | 4     | no        | 5               |
| 3    | 123   | 3           | 3     | yes       | 53              |
| 4    | 12    | 2           | 2     | no        | 53              |
| 5    | 1     | 1           | 1     | yes       | 531             |

**Output:**
```
Enter number: 12345
Reversed number is 531
```

Only the digits at odd positions from the left (`1`, `3`, `5`) survive, and they come out in reverse order (`531`) because the rightmost digit is processed — and appended — first.

## Notes and edge cases

- **Input `0`:** `count(0)` returns `0` (the `while` loop never executes since `0 > 0` is false), and `rev(0, 0)`'s loop also never executes, so the result is `0`.
- **Negative numbers:** The `while(num > 0)` condition in both functions is false immediately for negative input, so `numCount` would be `0` and the result would be `0` — negative numbers are not handled meaningfully by this program.
- **Variable shadowing:** Both functions declare a local variable with the *same name* as the function itself (`int count` inside `count()`, `int rev` inside `rev()`). This is legal in C++ — the local variable shadows the function name within that scope — but it can be confusing to read and is generally best avoided in real code (e.g. rename the local variables to `digitCount` and `result`).

## Compiling & running

```bash
g++ reverse-number-based-on-digit-position.cpp -o reverse-number-based-on-digit-position
./reverse-number-based-on-digit-position
```

## Requirements

- A C++ compiler (C++11 or later recommended)
