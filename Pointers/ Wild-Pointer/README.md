# Wild Pointer

## Definition

A **wild pointer** is a pointer that has been declared but has not been initialized with a valid memory address.

In this program, the pointer `p` is declared without assigning it a valid address.

```cpp
int* p;
int* p;

At this point, p is a wild pointer because it does not point to a known valid memory location.

The program then attempts to store 12 at the memory location pointed to by p:

*p = 12;

However, the address stored in p is indeterminate. Therefore, the program may attempt to access or modify an invalid memory location.

Output

There is no guaranteed output.

The program has undefined behavior because it dereferences an uninitialized pointer.

Possible behavior includes:

Program crash
Memory corruption
Unexpected results
Apparently working without an immediate error
Important Note

A pointer should be initialized before it is dereferenced.

For example:

int value = 12;
int* p = &value;

Now p points to a valid memory location and can safely be dereferenced.

Concepts Practiced
Pointers
Wild Pointer
Pointer Initialization
Dereferencing
Memory Addresses
Undefined Behavior
File

wild-pointer.cpp

Learning Outcome

This program demonstrates why pointers should always be initialized with a valid address or nullptr before they are dereferenced.
