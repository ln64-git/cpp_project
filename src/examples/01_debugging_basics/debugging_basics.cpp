// Debugging Basics Worksheet
// Practice using breakpoints, stepping, and inspecting variables

#include <iostream>
#include <vector>

namespace debugging_basics {

// Exercise 1: Step through and watch variables
void exercise1_stepping() {
  std::cout << "\n=== Exercise 1: Stepping ===" << std::endl;

  int a = 5;
  int b = 10;
  int sum = a + b;
  int product = a * b;

  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Product: " << product << std::endl;

  // TODO: Set breakpoint on line above, step through with F10
  // Watch a, b, sum, product in Variables panel
}

// Exercise 2: Debug a loop
void exercise2_loops() {
  std::cout << "\n=== Exercise 2: Loop Debugging ===" << std::endl;

  std::vector<int> numbers = {2, 4, 6, 8, 10};
  int total = 0;

  for (size_t i = 0; i < numbers.size(); i++) {
    total += numbers[i];
    // TODO: Set breakpoint here, watch i and total change
  }

  std::cout << "Total: " << total << std::endl;
}

// Exercise 3: Function calls with F11 (Step Into)
int multiply(int x, int y) { return x * y; }

void exercise3_functions() {
  std::cout << "\n=== Exercise 3: Function Calls ===" << std::endl;

  int result = multiply(7, 3); // TODO: Use F11 here to step INTO multiply()
  std::cout << "Result: " << result << std::endl;
}

// Exercise 4: Conditional breakpoints
void exercise4_conditionals() {
  std::cout << "\n=== Exercise 4: Conditional Breakpoints ===" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << "i = " << i << std::endl;
    // TODO: Set breakpoint with condition: i == 5
    // Right-click breakpoint -> Edit Breakpoint -> Enter: i == 5
  }
}

// Exercise 5: Fix the bug (uncomment to try)
/*
int divide(int a, int b) {
  return a / b;  // BUG: What if b is 0?
}

void exercise5_fix_bug() {
  std::cout << "\n=== Exercise 5: Fix the Bug ===" << std::endl;
  std::cout << "10 / 2 = " << divide(10, 2) << std::endl;
  std::cout << "10 / 0 = " << divide(10, 0) << std::endl;  // This will crash!
}
*/

void run_all() {
  std::cout << "\n╔════════════════════════════════╗" << std::endl;
  std::cout << "║  Debugging Basics Worksheet   ║" << std::endl;
  std::cout << "╚════════════════════════════════╝" << std::endl;

  exercise1_stepping();
  exercise2_loops();
  exercise3_functions();
  exercise4_conditionals();
  // exercise5_fix_bug();  // Uncomment after fixing the bug

  std::cout << "\n✓ All exercises complete!" << std::endl;
}

} // namespace debugging_basics
