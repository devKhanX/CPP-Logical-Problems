# product-sum-difference.cpp

A C++ program that reads an integer, computes the **sum** and the **product** of its digits, and returns the difference between the product and the sum (`product - sum`).

## The code

```cpp
#include <iostream> 
using namespace std; 
int sumProdDiff(int number) { 
    int sum = 0, pro = 1, digit = 0, result = 0; 
    while (number > 0) 
    { 
        digit = number % 10; 
        sum += digit; 
        pro *= digit; 
        number /= 10; 
    } 
    
    result=pro -sum; 
    return result; 
} 

int main() { 
    int number, result = 0; 
    cout<<"Enter a number: "; 
    cin>>number; 
    result=sumProdDiff(number); 
    cout<<"Sum and product difference is " << result << endl; 
    return 0; 
}
```

## How it works

### `sumProdDiff(int number)`

1. **`sum = 0`, `pro = 1`** — `sum` starts at `0` (identity for addition), `pro` starts at `1` (identity for multiplication), so both accumulate correctly from the first digit.
2. **`while (number > 0)`** — Loops while there are digits left to process:
   - `digit = number % 10` — extracts the last (rightmost) digit.
   - `sum += digit` — adds it to the running digit sum.
   - `pro *= digit` — multiplies it into the running digit product.
   - `number /= 10` — removes the last digit, shifting to the next one.
3. **`result = pro - sum`** — Once all digits are processed, the function returns the product of digits minus the sum of digits.

### `main()`

Reads `number` from the user, calls `sumProdDiff(number)`, and prints the result.

## Example walkthrough

For input `123`:

| Step | number | digit | sum | pro |
|------|--------|-------|-----|-----|
| 1    | 123    | 3     | 3   | 3   |
| 2    | 12     | 2     | 5   | 6   |
| 3    | 1      | 1     | 6   | 6   |

- Sum of digits = `6`
- Product of digits = `6`
- `result = pro - sum = 6 - 6 = 0`

**Output:**
```
Enter a number: 123
Sum and product difference is 0
```

## Notes and edge cases

- **A `0` digit anywhere zeros the product:** Since `pro` is multiplied by every digit, if any digit in the number is `0`, `pro` becomes `0` regardless of the other digits. For example, input `102` → digits `1, 0, 2` → sum `= 3`, product `= 0`, result `= 0 - 3 = -3`.
- **Input `0`:** The `while (number > 0)` loop never executes, so `sum` stays `0` and `pro` stays `1` (its initial value, since no digit is ever multiplied in). `result = 1 - 0 = 1`.
- **Negative numbers:** `while (number > 0)` is immediately false for negative input, so the function returns the same result as for `0` (`1`) — negative numbers aren't handled meaningfully, since `number % 10` and `number /= 10` are never reached.
- **Negative results:** Since digits range `0–9`, the sum grows roughly linearly with digit count while the product can be `0` (if any digit is `0`) or grow much faster for digits with no zeros — so `result` can end up negative (when `sum > pro`, e.g. many small/zero digits) or positive (when the product dominates, e.g. digits like `9`).

## Compiling & running

```bash
g++ product-sum-difference.cpp -o product-sum-difference
./product-sum-difference
```

## Requirements

- A C++ compiler (C++11 or later recommended)
