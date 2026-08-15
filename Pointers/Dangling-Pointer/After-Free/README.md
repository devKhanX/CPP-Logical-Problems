# dangling-after-free.cpp

A small C++ program demonstrating a **dangling pointer** caused by accessing memory after it has been freed (a classic **use-after-free** bug).

## What is a dangling pointer?

A dangling pointer is a pointer that still holds the address of memory that has already been deallocated (freed). The pointer variable itself isn't automatically set to `nullptr` when the memory is freed — it still "points" to that address, but the memory it refers to is no longer valid for the program to use. Reading or writing through a dangling pointer results in **undefined behavior**.

## The code

```cpp
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int *ptr=(int*)malloc (20);
	free(ptr);	
	cout<<*ptr;
}
```

## How it works

1. **`int *ptr = (int*)malloc(20);`** — Dynamically allocates 20 bytes on the heap and stores the starting address in `ptr`.
2. **`free(ptr);`** — Releases that memory back to the system. The memory is no longer owned by the program, but `ptr` still holds the same address — `ptr` is now a **dangling pointer**.
3. **`cout << *ptr;`** — Dereferences `ptr` to read an `int` from memory that has already been freed.

## Output

```
Undefined Behavior
```

The program accesses memory after it has been released. Since the memory is no longer guaranteed to belong to the program, the result is unpredictable and may differ across executions, compilers, or platforms. Possible outcomes include:

- Printing a leftover/garbage value that happens to still be there.
- Printing a completely different value if the memory was reused/overwritten by another allocation.
- Crashing the program (segmentation fault).

## Key takeaway

Once memory is `free()`-d (or `delete`-d in C++), the pointer to it becomes dangling and **must not be dereferenced**. Best practices to avoid this:

- Set the pointer to `nullptr` immediately after freeing it: `free(ptr); ptr = nullptr;`
- Check for `nullptr` before dereferencing a pointer.
- Avoid using a pointer after it has been freed/deleted anywhere in the program.
- Prefer smart pointers (`std::unique_ptr`, `std::shared_ptr`) in modern C++ to manage ownership automatically and avoid manual `free`/`delete` mistakes.

## Compiling & running

```bash
g++ dangling-after-free.cpp -o dangling-after-free
./dangling-after-free
```

**Note:** This program invokes undefined behavior deliberately, for educational purposes. Its output is not guaranteed and running it under tools like Valgrind or AddressSanitizer (`-fsanitize=address`) will typically report a heap-use-after-free error.

## Requirements

- A C++ compiler (C++11 or later recommended)
