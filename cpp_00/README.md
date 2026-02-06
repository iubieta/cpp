# CPP_00 - Basic C++ & Output

> **Subject:** [CPP_00 PDF](CPP_00.pdf)

## Module Overview

This module introduces the fundamentals of C++ programming, focusing on basic syntax, compilation, and input/output operations. You'll learn the essential building blocks that form the foundation for all advanced C++ concepts.

## Key Learning Objectives

### **Core C++ Concepts**
- Understanding C++ compilation process and flags
- Basic C++ syntax and structure
- String manipulation and character operations
- Command-line argument handling
- Output formatting and control

### **42 School Standards**
- 42 School header format implementation
- Makefile creation and usage
- Proper error handling patterns
- Code organization and structure

## Exercises Summary

### **Exercise 00 - Megaphone**
**Files:** `Makefile`, `megaphone.cpp`
**Goal:** Create a program that converts input strings to uppercase

**Learning Focus:**
- Basic I/O operations
- Character manipulation using `toupper()`
- Command-line argument processing
- Output formatting and control

**Key Concepts:**
```cpp
// Character manipulation example
char convert_to_upper(char c) {
    return std::toupper(c);
}

// String processing loop
for (int i = 0; argv[1][i]; i++) {
    std::cout << convert_to_upper(argv[1][i]);
}
```

## Core Concepts Explained

### **C++ Compilation Process**
```cpp
// Compilation with required flags
c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o megaphone
```

**Flags Explanation:**
- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors
- `-std=c++98`: Use C++98 standard

### **String and Character Operations**
C++ provides rich character manipulation functions:

```cpp
// Converting character case
char upper = std::toupper(lower_char);

// Processing command-line arguments
if (argc == 2) {
    std::string input = argv[1];
    // Process string
}

// Looping through strings
for (size_t i = 0; input[i]; i++) {
    std::cout << input[i];
}
```

### **Output Formatting**
```cpp
// Standard output
std::cout << "Hello, World!" << std::endl;

// Output without newline
std::cout << "Continued output";
```

## Implementation Patterns

### **Basic Program Structure**
```cpp
#include <iostream>
#include <cctype>

// Main function signature
int main(int argc, char** argv) {
    // Program logic here
    return 0;  // Success
}
```

### **Command-line Argument Handling**
```cpp
// Check for correct number of arguments
if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
    return 1;  // Error
}

// Process the argument
std::string input = argv[1];
// Process string...
```

### **Character Processing Loop**
```cpp
// Process each character
for (int i = 0; input[i]; i++) {
    char current = input[i];
    char processed = std::toupper(current);
    std::cout << processed;
}
std::cout << std::endl;
```

## Common Pitfalls & Solutions

### **Pitfall 1: Not Handling Empty Input**
```cpp
// ❌ Problem
if (argc == 2) {
    // Process only when 2 arguments
}

// ✅ Solution: Handle all cases
if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
} else if (argc == 2) {
    // Process the string
}
```

### **Pitfall 2: Forgetting String Terminator**
```cpp
// ❌ Problem: May read beyond string bounds
for (int i = 0; ; i++) {  // No termination condition

// ✅ Solution: Check for null terminator
for (int i = 0; input[i] != '\0'; i++) {
    // Process character
}
```

### **Pitfall 3: Missing Include Headers**
```cpp
// Required headers for character operations
#include <iostream>    // For std::cout
#include <cctype>      // For std::toupper
#include <string>      // For std::string (if used)
```

## Building & Testing

### **Build Commands**
```bash
# Build the program
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### **Testing Examples**
```bash
# Test with normal string
$> ./megaphone "hello world"
HELLO WORLD

# Test with mixed case
$> ./megaphone "Shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

# Test with punctuation
$> ./megaphone "Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT " ! " "SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

# Test without arguments
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## Best Practices

### **Code Organization**
- Keep main() function clean and focused
- Use meaningful variable names
- Separate logic from I/O when possible

### **Error Handling**
- Always check command-line arguments
- Return appropriate exit codes
- Provide helpful error messages

### **C++98 Compliance**
- Use `NULL` instead of `nullptr`
- Use `std::toupper()` from `<cctype>`
- Avoid C++11 specific features
- Use `std::cout` instead of `printf()`

## Further Learning Resources

### **Official Documentation**
- [Character handling - cppreference](https://en.cppreference.com/w/cpp/string/byte/toupper)
- [Command-line arguments - cppreference](https://en.cppreference.com/w/cpp/utility/program/main)

### **Educational Resources**
- [C++ Basics - GeeksforGeeks](https://www.geeksforgeeks.org/c-plus-plus/)
- [String Manipulation in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/string-manipulation-in-cpp/)
- [Command-line Arguments - GeeksforGeeks](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

### **Practice Suggestions**
- Experiment with different character operations
- Try combining multiple string transformations
- Practice with various command-line scenarios
- Explore other string processing functions

## Connection to Next Module

This module establishes the **foundation for memory management** in CPP_01. The concepts you'll need:

- **String understanding** for memory allocation concepts
- **Character processing** for pointer operations
- **Program structure** for class design

**Next: [CPP_01 - Memory & Pointers](../cpp_01/README.md)**

---

## Summary

CPP_00 introduces essential C++ programming concepts through practical string manipulation exercises. You'll master:
- Basic C++ syntax and compilation
- Character and string operations
- Command-line program creation
- 42 School coding standards

This foundation is crucial for understanding more complex topics like memory management and object-oriented programming in subsequent modules.