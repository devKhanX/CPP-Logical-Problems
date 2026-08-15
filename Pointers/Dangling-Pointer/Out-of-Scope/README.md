# dangling-out-of-scope.cpp

A small C++ program demonstrating a **dangling pointer** caused by a variable going **out of scope** while a pointer to it is still in use.

## What causes this dangling pointer?

In C++, a variable declared inside a block `{ ... }` only exists within that block's scope. Once execution leaves the block (even without a function call), the variable is destroyed and its stack memory is no longer reserved for it.

If a pointer outside the block was set to point at that variable, the pointer still holds the old address after the block ends — but the variable it once pointed to no longer exists there. The pointer is now dangling.

## The code

```cpp
#include<iostream>
using namespace std;
int main()
{
	int *ptr;
	{
		int value=500;
		ptr=&value;
	}
	cout<<*ptr;
	return 0;
}
```

## How it works

1. **`int *ptr;`** — `ptr` is declared in `main()`'s scope, with no initial value.
2. Inside the nested block `{ ... }`:
   - **`int value = 500;`** — `value` is a local variable that only exists within this inner block.
   - **`ptr = &value;`** — `ptr` is set to point to `value`'s address.
3. **The closing `}`** ends the inner block. `value` goes out of scope and is destroyed. `ptr` still holds its old address, but that address no longer belongs to a valid `value`.
4. **`cout << *ptr;`** — Dereferences `ptr` *after* `value` has gone out of scope, reading from memory that is no longer guaranteed to hold `500`.

## Output

```
Undefined Behavior
```

Although the program may print `500` on some systems (the stack memory often hasn't been overwritten yet at this point), the variable has already gone out of scope. Accessing it is undefined behavior, so the output is not guaranteed and may vary across compilers, platforms, or even different runs.

## Key takeaway

**A pointer must never be dereferenced after the variable it points to has gone out of scope** — whether that scope ends via a function return or simply a closing brace `}` of an inner block. Ways to avoid this:

- Don't let a pointer outlive the scope of the variable it points to.
- If data needs to persist beyond a block's scope, allocate it dynamically (`new`) and manage its lifetime explicitly (or with smart pointers), or declare it in an outer/wider scope.
- Set pointers to `nullptr` once the variable they reference is no longer valid, and check before dereferencing.
- Prefer RAII and smart pointers (`std::unique_ptr`, `std::shared_ptr`) to tie a resource's lifetime to a clear owner instead of a raw pointer to a stack variable.

## Compiling & running

```bash
g++ dangling-out-of-scope.cpp -o dangling-out-of-scope
./dangling-out-of-scope
```

**Note:** This program invokes undefined behavior deliberately, for educational purposes. Compiling with `-Wall -Wextra` and running under AddressSanitizer (`-fsanitize=address`) can help catch scope-related dangling pointer issues like this one.

## Requirements

- A C++ compiler (C++11 or later recommended)
