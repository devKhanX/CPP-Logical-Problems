# void-pointer.cpp

A small C++ program demonstrating how a `void*` (void pointer) can point to variables of different data types, and how it must be explicitly cast back to a typed pointer before being dereferenced.

## What is a void pointer?

A `void*` is a generic pointer type in C/C++ that can hold the address of **any** data type — `int`, `float`, `char`, a struct, etc. It doesn't know what type of data it points to, so:

- It **cannot be dereferenced directly** (the compiler doesn't know the size/type of the data).
- It **cannot do pointer arithmetic** (the compiler doesn't know the step size).
- Before use, it must be **cast** to the correct pointer type (e.g., `static_cast<int*>(ptr)`).

This makes `void*` useful for writing generic functions or storing addresses of unknown/varying types, at the cost of losing type safety until it's cast back.

## The code

```cpp
#include<iostream>
using namespace std;
int main()
{
	int n=50;
	float f=49.56;
	char c='$';
	void *ptr;
	ptr=&n;
	cout<<*(static_cast<int*>(ptr))<<endl;
	ptr=&f;
	cout<<*(static_cast<int*>(ptr))<<endl;
	ptr=&c;
	cout<<*(static_cast<int*>(ptr))<<endl;
	return 0;
}
```

## How it works

1. **`ptr = &n;`** — `ptr` stores the address of `n` (an `int`). Casting `ptr` to `int*` and dereferencing it correctly prints the integer value:
   ```
   50
   ```

2. **`ptr = &f;`** — `ptr` now stores the address of `f` (a `float`). The code casts it to `int*` instead of `float*`. This reinterprets the **raw bytes** of the float as an integer, rather than converting the value `49.56` to `50`. The result is a large, seemingly meaningless number (the integer representation of the float's underlying bit pattern), and it may differ depending on compiler/platform.

3. **`ptr = &c;`** — `ptr` now stores the address of `c` (a single `char`, typically 1 byte). Casting it to `int*` and dereferencing it reads **4 bytes** (the size of an `int`) starting from a 1-byte variable. This reads past the memory that actually belongs to `c`, resulting in **undefined behavior** — the output could be any garbage value, and could even crash the program depending on what memory follows `c`.

## Key takeaway

A `void*` must be cast to the **correct** matching pointer type before dereferencing. Casting it to the *wrong* type (as done here for `float` and `char`) does not convert the value — it misreads the memory, producing garbage output for `float` and undefined behavior for `char`. This program is a deliberate illustration of that pitfall, not a recommended coding pattern.

## Compiling & running

```bash
g++ void-pointer.cpp -o void-pointer
./void-pointer
```

**Note:** The output for the `float` and `char` cases is *not guaranteed* — it depends on your compiler, platform, and memory layout. Only the `int` case is guaranteed to reliably print `50`.

## Requirements

- A C++ compiler supporting `static_cast` (C++11 or later recommended)
