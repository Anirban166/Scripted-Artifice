// Anirban166, ac4743@nau.edu
// Compilation: g++ -std=c++17 test.cpp -o test && ./test
// Caveats: code readability is the tradeoff in most cases, although that completely depends on the exposure or experience level of the programmer.
#include <string>
#include <vector>
// #include <chrono>
#include <iostream>
#define newline std::cout << std::endl
#define varDebug(v) std::cout << #v << " = " << v // ; newline
// using namespace std::chrono;

template<typename ...T>
void print(T&&... args) {
    ((std::cout << args << " "), ...);
}

template<typename T, int N>
class Array
{
  private:
    T m_array[N];
  public:
   int getSize() const { return N; }    
};

/**
template<typename T, size_t S>
class Array
{
  public:
    constexpr size_t Size() const { return S; }
     T& operator[](size_t index) { return m_Data[index]; }
     const T& operator[](size_t index) const { return m_Data[index]; }
     T* Data() { return m_Data; }
     const T* Data() const { return m_Data; }
   private:
     T m_Data[S]; 
}
**/

static uint32_t s_AllocCount = 0;
void* operator new(size_t size) {
  s_AllocCount++;
  // print("\nAllocating", size, "bytes.");
  return malloc(size);
}

void printString(const std::string& str) {
  print("\n", str);
}

int main()
{ 
  // 1) Stringify macro and templates:
  print("Didja know, every", 1);
  int hour = 60;
  varDebug(hour);
  std::cout <<" minutes "<< std::endl;
  Array<std::string, 5> arr;
  print("Size of the array:", arr.getSize());
  newline; 
  
  // 2) Shorthand swap: (drawback: overflow)
  // a = a + b (total), 
  // b = a - b (total - b = a => b = a),
  // a = a - b (total - b which is now a, or total - b = a)
  a = a + b - (b = a);
  print("Swapped values:", a, b);
  // for containers, my goto would be std::swap() 
  newline;

  // 3) Looping:
  std::vector<int> values = {1, 2, 3};
  print("Contents of the container:"); 
  newline;
  // Approach A:
  for(auto value : values)
    print(value);
  newline;  
  // Approach B:
  for(std::vector<int>::iterator it = values.begin(); it != values.end(); ++it)
    print(*it);
  newline;  
  // Approach C:
  for(std::size_t i = 0; i != values.size(); ++i)
    print(values[i]);  
  newline;

  // 4) Bit manipulation:
  // a) Use shifts for mul/div operations w/ power of 2:
  print(((1 << 10) << 10), "Kilobytes make up", (1048576 >> 20), "Gigabyte"); 
  newline;   
  print((char)('a' | ' '));  
  newline;   
  print((char)('a' & '_'));
  std::cout << std::endl << (char)('X' ^ ' ') << (char)('d' ^ ' ') << std::endl;  
  // e) Check for a number to be a power of 2:
  unsigned int v = 32;
  bool powerOfTwo = v && !(v & (v - 1));
  if(powerOfTwo) print(v, "tends to be a power of 2.");

  // 5) String views:
  std::string userName = "Anirban166";
  std::string_view digits(userName.c_str() + 7, 4);
  // printString(userName.substr(7, 4));
  print("\nMemory allocations:", s_AllocCount);  
  print("\nThe digits in my GitHub username (or primary email) are:", digits);  
}
