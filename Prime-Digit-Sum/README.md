# prime-digit-sum.cpp

A C++ program that reads an integer, computes the sum of its digits, and checks whether that digit sum is a **prime number**.

## The code

```cpp
#include<iostream>
using namespace std;
bool isPrime (int n)
{
	if (n<=1)
	return false;
	if (n==2)
	return true;
	if (n%2==0)
	return false;
	for (int i=3;i<=n/i;i+=2)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num,rev=0,rem=0,sum=0;
	cout<<"Enter number : "<<endl;
	cin>>num;
	while(num>0)
		{
			rem=num%10;
			rev=rev*10+rem;
			num/=10;
			sum+=rem;
		}
	if (isPrime(sum)==true)
	{
		cout<<"Prime Digit Sum Number";
	}
	else
	{
		cout<<"Not a Prime Digit Sum Number";
	}
}
```

## How it works

### `isPrime(int n)`

A standard trial-division primality check:

1. Numbers `<= 1` are not prime → `false`.
2. `2` is the only even prime → `true`.
3. Any other even number is not prime → `false`.
4. For odd `n > 2`, the loop checks divisibility by odd numbers starting at `3`, stopping once `i > n/i` (equivalent to checking up to `√n`, avoiding the cost of testing all the way to `n`). If any `i` divides `n` evenly, `n` is not prime.
5. If no divisor is found, `n` is prime.

### `main()`

1. Reads an integer `num`.
2. Loops while `num > 0`, extracting digits one at a time from right to left:
   - `rem = num % 10` — extracts the last digit.
   - `rev = rev * 10 + rem` — builds the digit-reversed version of `num` (computed but never used/printed in this program).
   - `num /= 10` — removes the last digit.
   - `sum += rem` — accumulates the running sum of digits.
3. Once all digits have been processed, `sum` holds the total digit sum.
4. `isPrime(sum)` checks whether that sum is prime, and the program prints the corresponding message.

## Example walkthrough

For input `29`:

| Step | num | rem | sum |
|------|-----|-----|-----|
| 1    | 29  | 9   | 9   |
| 2    | 2   | 2   | 11  |

Digit sum = `2 + 9 = 11`, which **is** prime.

**Output:**
```
Enter number : 
29
Prime Digit Sum Number
```

For input `123` (digit sum = `1 + 2 + 3 = 6`, not prime):

**Output:**
```
Enter number : 
123
Not a Prime Digit Sum Number
```

## Notes and edge cases

- **`rev` is unused:** The program computes the digit-reversed number (`rev`) but never prints or otherwise uses it — it's dead computation left over from what may have originally been a "reverse a number" exercise, combined here with the digit-sum/prime check.
- **Input `0`:** The `while(num > 0)` loop never executes, so `sum` stays `0`. Since `isPrime(0)` returns `false` (as `0 <= 1`), the output would be `"Not a Prime Digit Sum Number"`.
- **Negative numbers:** `while(num > 0)` is immediately false for negative input, so `sum` remains `0` and the result is the same as for `0` — negative numbers aren't handled meaningfully.
- **Multi-digit sums:** A larger number's digit sum can itself be multi-digit (e.g. digit sum `23`), which `isPrime` handles correctly since it works on any `int`.

## Compiling & running

```bash
g++ prime-digit-sum.cpp -o prime-digit-sum
./prime-digit-sum
```

## Requirements

- A C++ compiler (C++11 or later recommended)
