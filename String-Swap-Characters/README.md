# string-swap-characters.cpp

A small C++ program demonstrating basic `std::string` operations: getting the size of a string, concatenating strings, and swapping individual characters between two strings.

## The code

```cpp
#include <iostream>
using namespace std;

int main()
{
    string string1, string2;
    string1 = "abcd";
    string2 = "ef";
    cout << string1.size() << " " << string2.size() << endl;
    cout << string1 + string2 << endl;
    swap(string1[0], string2[0]);
    cout<<string1<<" "<<string2;
    return 0;
}
```

## How it works

1. **`string string1, string2;`** — Two empty `std::string` objects are declared.
2. **`string1 = "abcd";`** and **`string2 = "ef";`** — The strings are assigned values.
3. **`string1.size()`** and **`string2.size()`** — `.size()` returns the number of characters in each string: `4` for `"abcd"` and `2` for `"ef"`.
4. **`string1 + string2`** — The `+` operator on `std::string` performs concatenation, joining the two strings into `"abcdef"`. Note this does not modify `string1` or `string2` themselves, since the result is only used inside `cout`.
5. **`swap(string1[0], string2[0]);`** — `string1[0]` and `string2[0]` access individual `char` elements (via `operator[]`) at index `0` of each string. `swap()` (from `<utility>`, made available here via `<iostream>`/`using namespace std`) exchanges these two **characters** — it does *not* swap the whole strings, just the character at index 0 in each.
   - Before: `string1[0] = 'a'`, `string2[0] = 'e'`
   - After: `string1[0] = 'e'`, `string2[0] = 'a'`
6. **`cout << string1 << " " << string2;`** — Prints the strings after the character swap.

## Output

```
4 2
abcdef
ebcd af
```

- `string1.size()` → `4`, `string2.size()` → `2`
- `string1 + string2` → `"abcdef"`
- After swapping the first character of each string: `string1` becomes `"ebcd"` and `string2` becomes `"af"`

This program is well-defined — unlike some other examples in this repo, it does not involve undefined behavior. It's simply a demonstration of `std::string`'s size, concatenation, and indexed character access/swap.

## Key takeaway

- `std::string::size()` returns the number of characters currently stored in the string.
- The `+` operator concatenates two strings into a new string (it does not modify the operands unless assigned back, e.g. `string1 = string1 + string2;` or `string1 += string2;`).
- `operator[]` on a `std::string` gives direct access to individual `char` elements, which can be read or modified (including via `std::swap`) just like elements of an array.
- `std::swap()` works on any two objects of the same type that are swappable — here, two `char` values.

## Compiling & running

```bash
g++ string-swap-characters.cpp -o string-swap-characters
./string-swap-characters
```

## Requirements

- A C++ compiler (C++11 or later recommended)
