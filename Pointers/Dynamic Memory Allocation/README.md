# dynamic_memory_reallocation.cpp

A C++ program demonstrating how to properly **free** dynamically allocated array memory with `delete[]` and then **reallocate** a new array to the same pointer with `new[]`.

## The code

```cpp
#include<iostream>
using namespace std;
int main()
{
	int *p=new int[5];
	p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;
	delete []p;
	p= new int[10];
	cout<<*p;
	return 0;
}
```

## How it works

1. **`int *p = new int[5];`** — Dynamically allocates an array of 5 `int`s on the heap; `p` points to the first element.
2. **`p[0] = 10; ... p[4] = 50;`** — Fills the array with values `10, 20, 30, 40, 50`.
3. **`delete[] p;`** — Frees the memory for the 5-element array. Because it was allocated with `new[]`, it must be released with the array form `delete[]` (not plain `delete`) so that the destructors for all elements run correctly and the whole block is freed properly. `p` is still holding the old (now invalid) address at this point — it doesn't automatically become `nullptr`.
4. **`p = new int[10];`** — Immediately reassigns `p` to a brand-new, independently allocated array of 10 `int`s. This overwrites the old dangling address with a fresh, valid one *before* it's ever dereferenced — so there's no dangling-pointer access here, unlike programs that dereference `p` right after `delete` without reallocating first.
5. **`cout << *p;`** — Dereferences `p`, reading the first element of the **new** 10-element array. This array is allocated with `new int[10]`, which **default-initializes `int` elements to indeterminate values** (unlike `new int[10]()`, which would zero-initialize them). So `*p` reads an **uninitialized value**.

## Output

```
Unspecified / indeterminate value
```

Since the new array's elements were never explicitly initialized, `*p` prints whatever garbage value happens to occupy that memory — it is **not guaranteed** to be `0`, and it may vary between runs, compilers, or platforms. (Note: reading an uninitialized `int` value itself is technically implementation-defined/unspecified rather than undefined behavior in this case, but it should never be relied upon.)

## Key takeaway

- Memory allocated with `new[]` **must** be released with `delete[]` (not `delete`), or the behavior is undefined — mismatching the two is a common bug.
- After `delete[] p`, `p` becomes a dangling pointer until it is reassigned — the pointer variable itself is not automatically nulled out.
- Reassigning `p = new int[10];` right after `delete[] p;` is safe: it points `p` at fresh, valid memory before any dereference happens.
- However, `new int[N]` (without `()`) does **not** initialize the elements — reading them before assigning values leads to indeterminate/garbage output. Use `new int[N]()` (value-initialization) if zero-initialized elements are needed.
- In modern C++, prefer `std::vector<int>` or smart pointers (`std::unique_ptr<int[]>`) over raw `new[]`/`delete[]` to avoid manual memory management pitfalls like mismatched allocation/deallocation and uninitialized reads.

## Compiling & running

```bash
g++ dynamic_memory_reallocation.cpp -o dynamic_memory_reallocation
./dynamic_memory_reallocation
```

**Note:** The printed value is not guaranteed and may differ across executions since it reads uninitialized memory. Running under tools like Valgrind or AddressSanitizer can help highlight the use of uninitialized memory (`-fsanitize=address,undefined` / MemorySanitizer).

## Requirements

- A C++ compiler (C++11 or later recommended)
