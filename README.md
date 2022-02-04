### R
- Call/invoke a function without the name, by first assigning it to be the opening parenthesis:
```r
'(' = median
(1:9) # 5
```
- Load one of two libraries with the same name:
```r 
lattice <- "ggplot2"
library(lattice) #lattice, check with ?xyplot()
library(lattice, character.only = TRUE) #ggplot2, check with ?aes()
```
- Inspect the structure and contents of an object using a mix of functions such as `str()`, `attributes()`, `class()` and `unclass()`.
- Use backticks for invalid (numeric constants, string with whitespaces or special symbols) column names.
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
  - `<<`/`>>` for mul/div operations with the powers of two. Ideal for conversions in between the units of information:
  ```cpp
  print("\n", ((1 << 10) << 10), "Kilobytes make up", (1048576 >> 20), "Gigabyte.");
  // 1048576 Kilobytes make up 1 Gigabyte. 
  ```
  - Mess with a particular bit:
  ```cpp
  n |= 1 << bitNum; // Set
  n &= ~(1 << bitNum); // Clear
  n ^= 1 << bitNum; // Toggle, much like https://stackoverflow.com/a/60946658/11422223
  ```  
  - RGB breakdown: (conversions to and from Hex or RGBA possible as well)
  ```cpp 
  // Considering red-green-blue to be represented by three sets of 8 bits, from left to right or from the MSB to the LSB:
  int blue = rgb & 0xFF0000, green = (rgb >> 8) & 0xFF00, red = (rgb >> 16) & 0xFF;
  rgbAgain = (red << 16) + (green << 8) + blue; 
  ```
  - Given that the difference between the lowercase and uppercase versions of ASCII alphabets in integers is 32, a quick switch to those would be to respectively set or clear the sixth bit (since 2<sup>6 - 1</sup> = 32, with the rightmost bit being 2<sup>0</sup>) from the right using appropriate characters: 
  ```cpp
  print((char)('a' & '_'), (char)('a' | ' ')); // A a
  // As expected, toggle works as well:
  std::cout << (char)('X' ^ ' ') << (char)('d' ^ ' '); // xD 
  ```
  - Check for a number to be a power of 2:
  ```cpp
  bool powerOfTwo = n && !(n & (n - 1));
  if(powerOfTwo) print(n, "tends to be a power of 2.");
  ```
