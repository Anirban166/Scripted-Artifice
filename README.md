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
  - Play around with a particular bit:
  ```cpp
  n |= 1 << bitNum; // Set
  n &= ~(1 << bitNum); // Clear
  n ^= 1 << bitNum; // Toggle, much like https://stackoverflow.com/a/60946658/11422223
  ```
  - `<<`/`>>` for mul/div operations with the powers of two. Ideal for conversions in between the units of information:
  ```cpp
  print("\n", ((1 << 10) << 10), "Kilobytes make up", (1048576 >> 20), "Gigabyte.");
  // 1048576 Kilobytes make up 1 Gigabyte. 
  ```
  - Given that the difference between the lowercase and uppercase versions of ASCII alphabets in integers is 32, a quick conversion to those would be to respectively set or clear the sixth bit (since 2<sup>6 - 1</sup> = 32, with LSB being 2<sup>0</sup>) from the right: 
  ```cpp
  print((char)('a' & '_'), (char)('a' | ' ')); // A a
  // As expected, toggle works as well:
  std::cout << (char)('X' ^ ' ') << (char)('d' ^ ' '); // xD 
  ```
