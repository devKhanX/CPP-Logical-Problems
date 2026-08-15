# dangling-local-variable.cpp

A small C++ program demonstrating a **dangling pointer** caused by returning the address of a **local (automatic/stack) variable** from a function.

## What causes this dangling pointer?

Local variables declared inside a function (without `static` or dynamic allocation) live on the **stack** and only exist for the **lifetime of that function call**. As soon as the function returns, its stack frame is popped and all local variables inside it are destroyed — their memory is no longer reserved for them and can be reused by the next function call.

If a function returns the **address** of such a local variable, the caller ends up with a pointer to memory that is no longer valid. That pointer is dangling the moment the function returns, even though the pointer variable itself still holds the old address.

## The code

```cpp
#include<iostream>
using namespace std;
int* getPointer()
{
	int value=10;
	return &value;
}
int main()
{
	int *ptr=getPointer();
	cout<<*ptr;
  	return 0;
}
```

## How it works

1. **`int value = 10;`** — `value` is a local variable created on `getPointer()`'s stack frame.
2. **`return &value;`** — The function returns the *address* of `value`, not a copy of its value.
3. As soon as `getPointer()` returns, its stack frame is destroyed. `value` no longer exists, but `ptr` in `main()` still holds its old (now invalid) address.
4. **`cout << *ptr;`** — Dereferences a dangling pointer, reading from memory that no longer belongs to `value`.

## Output

```
Undefined Behavior
```

The local variable is destroyed when the function returns, leaving the returned pointer dangling. Since that stack memory can be overwritten by subsequent function calls (or left untouched, purely by chance), the result is unpredictable. Possible outcomes include:

- Printing `10` anyway, purely by coincidence (the memory hasn't been overwritten yet).
- Printing a garbage value if the memory was reused.
- Crashing, in rarer cases.

Most modern compilers will also emit a warning here, such as *"address of local variable 'value' returned"* or *"function returns address of local variable"*.

## Key takeaway

**Never return the address of a local (stack) variable from a function.** Once the function returns, that variable's memory is no longer valid. Safe alternatives:

- Return the value itself (`int getValue() { int value = 10; return value; }`) — a copy is made before the stack frame is destroyed.
- Dynamically allocate the memory instead (`new int(10)`), so it persists until explicitly `delete`-d — but the caller must remember to free it.
- Declare the variable as `static` so it persists across calls — but note this means the variable is shared/reused across all calls, which has its own pitfalls.
- Prefer smart pointers (`std::unique_ptr<int>`) if returning a heap-allocated value, to manage ownership safely.

## Compiling & running

```bash
g++ dangling-local-variable.cpp -o dangling-local-variable
./dangling-local-variable
```

**Note:** This program invokes undefined behavior deliberately, for educational purposes. Compile with `-Wall` to see the compiler's warning about returning the address of a local variable.

## Requirements

- A C++ compiler (C++11 or later recommended)
