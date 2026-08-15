# Null Pointer

## Problem Statement

A **null pointer** is a pointer that does not currently point to a valid memory location.

This program demonstrates how to:

- Initialize a pointer with `nullptr`.
- Check whether a pointer is null.
- Assign a valid memory address to the pointer.
- Dereference the pointer after assigning it a valid address.

## Code Explanation

The pointer is initially set to `nullptr`:

```cpp
int* ptr = nullptr;
The program checks whether the pointer is null:
if (ptr == nullptr)
Since it does not point to a valid memory location, the program prints:
Pointer is currently null.

A valid variable is then created and its address is assigned to the pointer:

int value = 20;
ptr = &value;

The pointer is checked again. Since it now contains a valid memory address, the program can safely dereference it:

*ptr
#### Output
Pointer is currently null.
Pointer is not null.
Value at the memory location pointed to by the pointer: 20
Important Note
A null pointer should not be dereferenced.

###For example:
*ptr = 10;
while ptr is nullptr would result in undefined behavior.

####Concepts Practiced
Pointers
nullptr
Null Pointer
Address-of Operator (&)
Dereference Operator (*)
Pointer Validation
Memory Addresses
File

null-pointer.cpp

Learning Outcome

This program demonstrates how to identify a null pointer and safely assign it a valid memory address before accessing the value stored at that address.
