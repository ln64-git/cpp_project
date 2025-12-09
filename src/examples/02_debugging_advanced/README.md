# Advanced Debugging Worksheet

Practice debugging complex issues including pointers, memory, logic errors, and more.

## 🎯 Learning Goals

- Debug pointer and memory issues
- Find logic errors in complex code
- Understand variable lifetime and scope
- Detect memory leaks
- Navigate call stacks effectively
- Use memory debugging tools (Valgrind)

## 📋 Exercises

### Exercise 1: Pointer Issues
Debug null and dangling pointer problems.

**What to practice:**
- Inspect pointer values (nullptr vs valid address)
- Understand pointer dereferencing
- Check pointers before use
- Identify null pointer crashes

**Key concept:** Always check `ptr != nullptr` before dereferencing

### Exercise 2: Array Bounds
Find and prevent buffer overflow and out-of-bounds access.

**What to practice:**
- Watch array indices in loops
- Compare index with size
- Use `.at()` for bounds checking
- Understand undefined behavior

**Key concept:** Array index must be `< size()`, not `<= size()`

### Exercise 3: Logic Errors
Find bugs where code runs but produces wrong results.

**What to practice:**
- Set breakpoints in suspicious functions
- Watch intermediate values
- Compare expected vs actual behavior
- Trace through algorithm step by step

**Key concept:** The bug is comparing with `nums[0]` instead of `min`

### Exercise 4: Variable Lifetime
Understand stack vs heap, local vs dynamic memory.

**What to practice:**
- Understand local variable scope
- See why returning local address is dangerous
- Learn smart pointers (`unique_ptr`, `shared_ptr`)
- Proper memory management

**Key concept:** Never return address of local variables

### Exercise 5: Nested Loops
Debug complex nested loops with multiple indices.

**What to practice:**
- Track multiple loop variables (i, j)
- Watch nested conditions
- Understand 2D array access
- Step through iterations carefully

**Key concept:** Set breakpoint inside inner loop, watch both indices

### Exercise 6: String Manipulation
Debug string operations and edge cases.

**What to practice:**
- Handle empty strings
- Check string length before access
- Watch string building in loops
- Understand string indices

**Key concept:** Always check for empty strings before indexing

### Exercise 7: Memory Leaks
Detect and fix memory that's never freed.

**What to practice:**
- Understand `new` vs `delete`
- Use smart pointers to avoid leaks
- Run with Valgrind to detect leaks
- Proper RAII patterns

**Key concept:** Every `new` needs a `delete`, or use smart pointers

### Exercise 8: Conditional Logic
Debug complex if/else chains.

**What to practice:**
- Step through each condition
- Watch which branches execute
- Verify condition coverage
- Test edge cases

**Key concept:** Test all branches: positive, negative, zero

### Exercise 9: Division by Zero (Challenge)
Fix dangerous division operation.

**What to practice:**
- Add input validation
- Handle error conditions
- Test edge cases
- Return sensible defaults or throw exceptions

**Key concept:** Check divisor before dividing

### Exercise 10: Call Stack Navigation
Understand function call chains and stack frames.

**What to practice:**
- Set breakpoint deep in call chain
- Examine Call Stack panel
- Click different stack frames
- See how execution got there

**Key concept:** Call stack shows the path: main → level1 → level2 → level3

## 🛠️ Advanced Debugging Tools

### Valgrind (Memory Debugger)
```bash
valgrind --leak-check=full ./build/cpp_project
```

**Detects:**
- Memory leaks (allocated but never freed)
- Invalid memory access
- Use of uninitialized memory
- Double frees

**How to use:**
1. Build your program normally
2. Run with valgrind
3. Look for "definitely lost" or "invalid read/write"
4. Fix reported issues

### AddressSanitizer (ASan)
```bash
# Build with sanitizer
g++ -fsanitize=address -g advanced_debugging.cpp -o debug

# Run (crashes on error with detailed report)
./debug
```

**Detects:**
- Buffer overflows (stack and heap)
- Use-after-free
- Double-free
- Memory leaks

### GDB Commands Quick Reference
```bash
gdb ./build/cpp_project

# Breakpoints
break advanced_debugging.cpp:42
break findMinimum

# Running
run
continue
next  # F10
step  # F11

# Inspection
print ptr
print *ptr
print numbers[i]
info locals

# Stack
backtrace
frame 2
up
down
```

## 🎮 Advanced Techniques

### Conditional Breakpoints
```
Condition: i == 3 && sum > 100
Action: Print "sum is {sum}" and continue
```

### Watch Expressions
```
*ptr                    # Dereference pointer
numbers.size()          # Call methods
i < numbers.size()      # Check conditions
```

### Data Breakpoints (Watch points)
```bash
# In GDB:
watch variable_name    # Break when value changes
```

## 💡 Debugging Strategy

1. **Reproduce consistently** - Make bug happen reliably
2. **Minimize test case** - Smallest code that shows bug
3. **Form hypothesis** - What do you think is wrong?
4. **Test hypothesis** - Set breakpoints, check assumptions
5. **Fix and verify** - Test fix thoroughly

### Binary Search for Bugs
1. Set breakpoint in middle of code
2. Check if bug has occurred yet
3. Search in first or second half
4. Repeat until found

### Common Bug Patterns
- **Off-by-one**: `i <= size` should be `i < size`
- **Uninitialized**: Variables used before set
- **Wrong variable**: Using `arr[0]` instead of `current`
- **Memory leaks**: `new` without `delete`
- **Null pointers**: Dereferencing without checking

## ✅ Checklist

- [ ] Exercise 1 - Debug pointer issues
- [ ] Exercise 2 - Fix array bounds errors
- [ ] Exercise 3 - Find and fix logic error
- [ ] Exercise 4 - Understand variable lifetime
- [ ] Exercise 5 - Debug nested loops
- [ ] Exercise 6 - Handle string edge cases
- [ ] Exercise 7 - Detect memory leaks with Valgrind
- [ ] Exercise 8 - Debug conditional logic
- [ ] Exercise 9 - Fix division by zero
- [ ] Exercise 10 - Navigate call stack
- [ ] Run with Valgrind successfully
- [ ] Can debug pointer issues confidently
- [ ] Understand memory management basics

## 🎓 Advanced Topics to Explore

After completing this worksheet:

1. **Threading bugs** - Race conditions, deadlocks
2. **Template debugging** - Complex type errors
3. **Performance profiling** - Find bottlenecks (gprof, perf)
4. **Core dumps** - Post-mortem debugging
5. **Remote debugging** - Debug on different machines
6. **Reverse debugging** - Step backwards (rr, gdb reverse)

## 🚀 How to Run

### Run exercises
```cpp
// In src/main.cpp, uncomment:
advanced_debugging::run_all();
```

### Run with Valgrind
```bash
./build.sh
valgrind --leak-check=full --show-leak-kinds=all ./build/cpp_project
```

### Build with sanitizers
```bash
# Edit CMakeLists.txt or compile directly:
g++ -fsanitize=address -g advanced_debugging.cpp -o debug
./debug
```

## 📚 Resources

- **Valgrind Guide**: https://valgrind.org/docs/manual/quick-start.html
- **GDB Tutorial**: https://www.gdbtutorial.com/
- **C++ Core Guidelines**: https://isocpp.github.io/CppCoreGuidelines/
- **AddressSanitizer**: https://github.com/google/sanitizers

---

**Pro Tip:** The best debuggers combine IDE tools, command-line debuggers (GDB), and memory checkers (Valgrind/ASan). Master all three!

