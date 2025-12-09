// Advanced Debugging Worksheet
// Practice debugging complex issues: memory, pointers, and logic errors

#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace advanced_debugging {

// Exercise 1: Pointer debugging - null and dangling pointers
void exercise1_pointers() {
  std::cout << "\n=== Exercise 1: Pointer Issues ===" << std::endl;
  
  int* ptr1 = nullptr;
  int value = 42;
  int* ptr2 = &value;
  
  // TODO: Set breakpoint here, inspect ptr1 and ptr2
  // Watch what happens when we check nullptr
  if (ptr1 != nullptr) {
    std::cout << "ptr1: " << *ptr1 << std::endl;
  } else {
    std::cout << "ptr1 is null" << std::endl;
  }
  
  if (ptr2 != nullptr) {
    std::cout << "ptr2: " << *ptr2 << std::endl;
  }
  
  // TODO: What would happen if we removed the null check?
  // Try removing the if statement and debugging the crash
}

// Exercise 2: Array bounds and buffer issues
void exercise2_array_bounds() {
  std::cout << "\n=== Exercise 2: Array Bounds ===" << std::endl;
  
  std::vector<int> numbers = {10, 20, 30, 40, 50};
  
  // TODO: Set breakpoint here, watch the index
  for (size_t i = 0; i < numbers.size(); i++) {
    std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
  }
  
  // Uncomment to see out of bounds access:
  // std::cout << "numbers[10] = " << numbers[10] << std::endl;  // Bug!
  
  // TODO: Try using .at() instead: numbers.at(10) - throws exception
}

// Exercise 3: Logic error - wrong variable used
int findMinimum(const std::vector<int>& nums) {
  if (nums.empty()) return 0;
  
  int min = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    // TODO: Set breakpoint here, watch min and nums[i]
    if (nums[i] < nums[0]) {  // BUG: Should compare with min, not nums[0]!
      min = nums[i];
    }
  }
  return min;
}

void exercise3_logic_error() {
  std::cout << "\n=== Exercise 3: Logic Error ===" << std::endl;
  
  std::vector<int> values = {50, 10, 80, 5, 90, 3, 100};
  int minimum = findMinimum(values);
  
  std::cout << "Minimum value: " << minimum << std::endl;
  std::cout << "(Should be 3, but might be wrong!)" << std::endl;
  
  // TODO: Debug findMinimum() to find why it returns wrong result
}

// Exercise 4: Reference and lifetime issues
int* createDanglingPointer() {
  int local = 100;
  return &local;  // BUG: Returning address of local variable!
}

void exercise4_lifetime() {
  std::cout << "\n=== Exercise 4: Variable Lifetime ===" << std::endl;
  
  // Uncomment to see undefined behavior:
  // int* bad_ptr = createDanglingPointer();
  // std::cout << "Dangling pointer value: " << *bad_ptr << std::endl;
  
  // Correct approach:
  std::unique_ptr<int> good_ptr = std::make_unique<int>(100);
  std::cout << "Smart pointer value: " << *good_ptr << std::endl;
  
  // TODO: Debug both approaches and understand the difference
}

// Exercise 5: Complex nested loops with off-by-one error
void exercise5_nested_loops() {
  std::cout << "\n=== Exercise 5: Nested Loops ===" << std::endl;
  
  std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  
  int sum = 0;
  
  // TODO: Set breakpoint inside inner loop
  // Watch i, j, matrix[i][j], and sum
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[i].size(); j++) {
      sum += matrix[i][j];
      std::cout << "matrix[" << i << "][" << j << "] = " 
                << matrix[i][j] << ", sum = " << sum << std::endl;
    }
  }
  
  std::cout << "Total sum: " << sum << std::endl;
  
  // Uncomment to see bounds error:
  // std::cout << matrix[3][0] << std::endl;  // Out of bounds!
}

// Exercise 6: String manipulation bugs
std::string reverseString(const std::string& str) {
  if (str.empty()) return "";
  
  std::string result;
  // TODO: Set breakpoint here, watch i and result
  for (int i = str.length() - 1; i >= 0; i--) {
    result += str[i];
  }
  return result;
}

void exercise6_strings() {
  std::cout << "\n=== Exercise 6: String Debugging ===" << std::endl;
  
  std::string text = "Debug";
  std::string reversed = reverseString(text);
  
  std::cout << "Original: " << text << std::endl;
  std::cout << "Reversed: " << reversed << std::endl;
  
  // TODO: What happens with empty string?
  std::string empty_reversed = reverseString("");
  std::cout << "Empty reversed: '" << empty_reversed << "'" << std::endl;
}

// Exercise 7: Memory leak simulation
void exercise7_memory_leak() {
  std::cout << "\n=== Exercise 7: Memory Management ===" << std::endl;
  
  // Bad: Memory leak
  // int* leak = new int[100];
  // for (int i = 0; i < 100; i++) {
  //   leak[i] = i;
  // }
  // TODO: Leak is never deleted! Run with valgrind to detect
  
  // Good: Using smart pointers (no leak)
  std::unique_ptr<int[]> safe(new int[100]);
  for (int i = 0; i < 100; i++) {
    safe[i] = i;
  }
  std::cout << "Smart pointer example: safe[50] = " << safe[50] << std::endl;
  // Automatically cleaned up when safe goes out of scope
}

// Exercise 8: Conditional logic bug
std::string checkNumber(int n) {
  // TODO: Set breakpoint here, try different values of n
  if (n > 0) {
    return "Positive";
  } else if (n < 0) {
    return "Negative";
  } else if (n == 0) {
    return "Zero";
  }
  return "Unknown";  // Should never reach here
}

void exercise8_conditionals() {
  std::cout << "\n=== Exercise 8: Conditional Logic ===" << std::endl;
  
  std::cout << "5 is: " << checkNumber(5) << std::endl;
  std::cout << "-3 is: " << checkNumber(-3) << std::endl;
  std::cout << "0 is: " << checkNumber(0) << std::endl;
  
  // TODO: Try removing one condition and see what happens
}

// Exercise 9: Division by zero (must be fixed)
/*
double safeDivide(double a, double b) {
  // BUG: No check for zero!
  return a / b;
}

void exercise9_division() {
  std::cout << "\n=== Exercise 9: Safe Division ===" << std::endl;
  
  std::cout << "10 / 2 = " << safeDivide(10, 2) << std::endl;
  std::cout << "10 / 0 = " << safeDivide(10, 0) << std::endl;  // Crash!
  
  // TODO: Add zero check and handle error properly
}
*/

// Exercise 10: Working with call stack
void level3() {
  std::cout << "Level 3 reached" << std::endl;
  // TODO: Set breakpoint here, examine call stack
}

void level2() {
  std::cout << "Level 2 calling level 3..." << std::endl;
  level3();
}

void level1() {
  std::cout << "Level 1 calling level 2..." << std::endl;
  level2();
}

void exercise10_callstack() {
  std::cout << "\n=== Exercise 10: Call Stack ===" << std::endl;
  level1();
  // TODO: Set breakpoint in level3(), view call stack
  // Click on different stack frames to see variables at each level
}

void run_all() {
  std::cout << "\n╔════════════════════════════════╗" << std::endl;
  std::cout << "║ Advanced Debugging Worksheet  ║" << std::endl;
  std::cout << "╚════════════════════════════════╝" << std::endl;
  
  exercise1_pointers();
  exercise2_array_bounds();
  exercise3_logic_error();
  exercise4_lifetime();
  exercise5_nested_loops();
  exercise6_strings();
  exercise7_memory_leak();
  exercise8_conditionals();
  // exercise9_division();  // Uncomment after fixing
  exercise10_callstack();
  
  std::cout << "\n✓ All exercises complete!" << std::endl;
  std::cout << "\nPro tip: Run with valgrind to detect memory issues:" << std::endl;
  std::cout << "  valgrind --leak-check=full ./build/cpp_project" << std::endl;
}

} // namespace advanced_debugging

