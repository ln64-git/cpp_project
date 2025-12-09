# Debugging Basics Worksheet

Learn fundamental debugging techniques using your IDE's visual debugger.

## 🎯 Learning Goals

- Master basic stepping commands (F10, F11)
- Inspect and watch variables
- Use conditional breakpoints
- Understand program flow
- Find and fix simple bugs

## 📋 Exercises

### Exercise 1: Stepping Through Code

Learn to use F10 to step over code line by line.

**What to practice:**

- Set breakpoint at the start of the function
- Step through with F10
- Watch variables `a`, `b`, `sum`, `product` change in Variables panel

### Exercise 2: Loop Debugging

Debug loops and watch variables change with each iteration.

**What to practice:**

- Set breakpoint inside the loop
- Watch `i` and `total` values
- Step through multiple iterations
- Understand loop behavior

### Exercise 3: Function Calls (Step Into)

Learn to use F11 to step into function calls.

**What to practice:**

- Set breakpoint before function call
- Use F11 to step INTO `multiply()`
- Watch how execution enters the function
- Use Shift+F11 to step out

### Exercise 4: Conditional Breakpoints

Set breakpoints that only trigger under specific conditions.

**What to practice:**

- Set a breakpoint inside the loop
- Right-click breakpoint → Edit Breakpoint
- Add condition: `i == 5`
- Run and see it only breaks when i equals 5

### Exercise 5: Fix the Bug

Find and fix a division by zero bug.

**What to practice:**

- Uncomment the buggy code
- Debug to find where it crashes
- Add proper error handling
- Test your fix

## 🎮 Keyboard Shortcuts

| Key               | Action                                        |
| ----------------- | --------------------------------------------- |
| **F9**            | Toggle breakpoint on current line             |
| **F5**            | Start debugging / Continue to next breakpoint |
| **F10**           | Step Over - execute current line              |
| **F11**           | Step Into - enter function calls              |
| **Shift+F11**     | Step Out - exit current function              |
| **Ctrl+Shift+F5** | Restart debugging                             |
| **Shift+F5**      | Stop debugging                                |

## 🔍 Debugger Panels

### Variables Panel

- Shows all local variables automatically
- Expand objects to see their contents
- Values update as you step through code

### Watch Panel

- Add specific expressions to monitor
- Examples: `i * 2`, `numbers.size()`, `ptr != nullptr`
- Stays visible across all stack frames

### Call Stack Panel

- Shows the chain of function calls
- Click frames to see variables at each level
- Understand how you got to current location

### Debug Console

- Type variable names to inspect them
- Evaluate expressions on the fly
- Call functions to test behavior

## 💡 Tips for Success

1. **Start simple** - Begin with Exercise 1 and work through in order
2. **Take your time** - Step through slowly, watch what happens
3. **Experiment** - Try different things, break stuff on purpose
4. **Use the panels** - Variables and Watch panels are your friends
5. **Read TODO comments** - They guide you through each exercise

## 🚀 How to Run

### Option 1: Run from main.cpp

```cpp
// In src/main.cpp, uncomment:
debugging_basics::run_all();
```

Then: `./build.sh && ./build/cpp_project`

### Option 2: Debug this file directly

1. Open `debugging_basics.cpp`
2. Set breakpoint in any exercise function
3. Press F5 to start debugging
4. Follow along with exercises

## ✅ Checklist

- [ ] Complete Exercise 1 - Step through simple code
- [ ] Complete Exercise 2 - Debug a loop
- [ ] Complete Exercise 3 - Step into functions
- [ ] Complete Exercise 4 - Use conditional breakpoint
- [ ] Complete Exercise 5 - Fix the division bug
- [ ] Comfortable using F10, F11, F9
- [ ] Can inspect variables in Variables panel
- [ ] Can add expressions to Watch panel

## 🎓 Next Steps

Once you complete this worksheet:

1. Move on to `02_debugging_advanced`
2. Practice these skills in your own code
3. Try debugging without looking at solutions first

---

**Remember:** Debugging is a skill that improves with practice. The more you debug, the faster you'll become at finding bugs!
