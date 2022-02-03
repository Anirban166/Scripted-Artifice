### R
> To be updated soon.
___
### C++
- Macros
  - Stringify for debugging:
  ```cpp
  #define varDebug(v) std::cout << #v << " = " << v // << std::endl
  ```
- Templates
  - Generic print:
  ```cpp
  // Single variable:
  template<typename T>
  void print(T value) {
    std::cout << value << " ";
  }  
  // Multiple/Any number of arguments:
  template<typename ...T>
  void print(T&&... args) {
    ((std::cout << args << " "), ...);
  }
  ```
- Bit manipulation
  - `&` over `%` for parity checks - `n & 1` would evaluate to be true (a boolean to be used inside an if-conditional over the ordinary `n % 2 != 0`) if `n` is odd (given that the least significant bit is always set if the number is not even).
  - `<<` and `>>` for mul/div operations with the powers of two. Ideal for conversions in between the units of information:
  ```cpp
  print("\n", ((1 << 10) << 10), "Kilobytes make up", (1048576 >> 20), "Gigabyte.");
  // 1048576 Kilobytes make up 1 Gigabyte. 
  ```
