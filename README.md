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
  Type casting or explicit conversion will be required will be required for interchangeable types in certain cases (third trick under 'Bit manipulation' serves as an example). 
- Bit manipulation
  - `&` over `%` for parity checks - `n & 1` would evaluate to be true (a boolean to be used inside an if-conditional over the ordinary `n % 2 != 0`) if `n` is odd (given that the least significant bit is always set if the number is not even).
  - `<<`/`>>` for mul/div operations with the powers of two. Ideal for conversions in between the units of information:
  ```cpp
  print("\n", ((1 << 10) << 10), "Kilobytes make up", (1048576 >> 20), "Gigabyte.");
  // 1048576 Kilobytes make up 1 Gigabyte. 
  ```
  - Given that the difference between the lowercase and uppercase versions of ASCII alphabets in integers is 32 or 2<sup>5</sup>, a quick conversion to those would be to set (` `) or clear (`_`) the bit respectively: 
  ```cpp
  print((char)('a' & '_'), (char)('a' | ' ')); // A a
  // As expected, toggle works as well:
  std::cout << (char)('X' ^ ' ') << (char)('d' ^ ' '); // xD 
  ```
