# CPP_01 - Memory & Pointers

> **Subject:** [CPP_01 PDF](CPP_01.pdf)

## Module Overview

This module introduces fundamental concepts of memory management in C++, focusing on stack vs heap allocation, pointer operations, and Resource Acquisition Is Initialization (RAII) principles. You'll learn how to properly manage memory and create basic object-oriented programs.

## Key Learning Objectives

### **Memory Management Concepts**
- Understanding stack vs heap allocation
- Pointer operations and dereferencing
- Memory allocation and deallocation with `new`/`delete`
- RAII principles and automatic resource management
- Memory leak prevention

### **Object-Oriented Foundations**
- Basic class design and implementation
- Constructor and destructor patterns
- Member functions and access control
- Object lifetime management

## Exercises Summary

### **Exercise 00 - Zombie Class**
**Files:** `Makefile`, `main.cpp`, `Zombie.h`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`
**Goal:** Implement a Zombie class with proper memory management

**Learning Focus:**
- Class design with private attributes
- Constructor/destructor implementation
- Heap vs stack object creation
- Memory management patterns

### **Exercise 01 - Zombie Horde**
**Files:** `Makefile`, `main.cpp`, `Zombie.h`, `Zombie.cpp`, `zombieHorde.cpp`
**Goal:** Create multiple zombies in a single allocation

**Learning Focus:**
- Array allocation on heap
- Constructor parameter passing
- Loop-based object initialization
- Efficient memory management

### **Exercise 02 - Pointers and References**
**Files:** `Makefile`, `main.cpp`
**Goal:** Demonstrate memory addresses and reference behavior

**Learning Focus:**
- Pointer vs reference differences
- Memory address visualization
- Reference binding behavior
- String storage mechanisms

## Core Concepts Explained

### **Stack vs Heap Memory**

```cpp
// Stack allocation - automatic management
void stack_example() {
    Zombie stack_zombie("Stackie");  // Automatically destroyed when function ends
    // stack_zombie goes out of scope here
}

// Heap allocation - manual management
void heap_example() {
    Zombie* heap_zombie = new Zombie("Heapie");  // Manual creation
    // Must manually delete to free memory
    delete heap_zombie;
}
```

**Key Differences:**
- **Stack:** Fast, automatic, limited size
- **Heap:** Slower, manual, dynamic size
- **Lifetime:** Stack = scope-based, Heap = explicit control

### **Pointer Operations**

```cpp
// Pointer declaration and initialization
Zombie* zombie_ptr;           // Uninitialized pointer
Zombie* heap_zombie = new Zombie("Pointerie");  // Initialized pointer

// Pointer dereferencing
heap_zombie->announce();       // Access member through pointer
(*heap_zombie).announce();      // Alternative syntax

// Pointer arithmetic (for arrays)
Zombie* zombie_array = new Zombie[10];
Zombie* second_zombie = zombie_array + 1;  // Points to second element
```

### **RAII Pattern**

```cpp
// RAII - Resource Acquisition Is Initialization
class Zombie {
private:
    std::string name;
    
public:
    Zombie(std::string z_name) : name(z_name) {  // Acquire resource
        announce();  // Use resource
    }
    
    ~Zombie() {  // Release resource automatically
        std::cout << name << " is destroyed" << std::endl;
    }
};

// Usage - automatic cleanup
void create_zombie() {
    Zombie stack_zombie("RAII");  // Constructor called
}  // Destructor called automatically when scope ends
```

## Implementation Patterns

### **Basic Class Design**
```cpp
// Zombie.h - Header file
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string name;  // Private attribute
    
public:
    Zombie(std::string name);  // Constructor
    ~Zombie();              // Destructor
    void announce(void);     // Public method
};

#endif
```

```cpp
// Zombie.cpp - Implementation
#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string z_name) : name(z_name) {
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

### **Factory Functions**
```cpp
// Create individual zombie on heap
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);  // Allocate on heap
    return zombie;  // Return pointer
}

// Create zombie on stack (automatic cleanup)
void randomChump(std::string name) {
    Zombie stack_zombie(name);  // Stack allocation
    stack_zombie.announce();      // Use zombie
}  // Automatically destroyed here
```

### **Array Allocation**
```cpp
// Allocate array of zombies
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];  // Allocate N zombies
    
    for (int i = 0; i < N; i++) {
        // Each zombie gets unique name
        horde[i] = Zombie(name + std::to_string(i));
    }
    
    return horde;  // Return pointer to first element
}

// Clean up array
delete[] horde;  // Use delete[] for arrays
```

### **Reference vs Pointer Behavior**
```cpp
void reference_example() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;      // Pointer to string
    std::string& stringREF = str;       // Reference to string
    
    // Display addresses
    std::cout << "String address: " << &str << std::endl;
    std::cout << "Pointer value: " << stringPTR << std::endl;
    std::cout << "Reference address: " << &stringREF << std::endl;
    
    // Both point to same memory
    std::cout << "Pointer == Reference: " << (stringPTR == &stringREF) << std::endl;
}
```

## Common Pitfalls & Solutions

### **Pitfall 1: Memory Leaks**
```cpp
// ❌ Problem: Forgetting to delete
void memory_leak() {
    Zombie* zombie = new Zombie("Leaky");
    // Never delete - memory leak!
}

// ✅ Solution: Always pair new/delete
void proper_cleanup() {
    Zombie* zombie = new Zombie("Clean");
    // Use zombie...
    delete zombie;  // Proper cleanup
}

// ✅ Better: Use RAII
void automatic_cleanup() {
    Zombie zombie("RAII");  // Automatic cleanup
}  // Destructor called automatically
```

### **Pitfall 2: Dangling Pointers**
```cpp
// ❌ Problem: Pointer to local variable
Zombie* dangling_pointer() {
    Zombie local_zombie("Local");
    return &local_zombie;  // local_zombie destroyed here
}  // Pointer is now dangling!

// ✅ Solution: Return heap-allocated object
Zombie* valid_pointer() {
    Zombie* heap_zombie = new Zombie("Heap");
    return heap_zombie;  // Safe - object exists after function
}
```

### **Pitfall 3: Wrong Delete Form**
```cpp
// ❌ Problem: Using wrong delete
Zombie* single_zombie = new Zombie("Single");
Zombie* zombie_array = new Zombie[10];

delete zombie_array;     // ❌ Wrong - undefined behavior
delete[] single_zombie;  // ❌ Wrong - undefined behavior

// ✅ Solution: Match new/delete form
delete single_zombie;      // ✅ Correct
delete[] zombie_array;      // ✅ Correct
```

### **Pitfall 4: Null Pointer Dereference**
```cpp
// ❌ Problem: Using uninitialized pointer
Zombie* zombie_ptr;
zombie_ptr->announce();  // ❌ Undefined behavior

// ✅ Solution: Initialize or check pointers
Zombie* zombie_ptr = NULL;
if (zombie_ptr) {
    zombie_ptr->announce();  // ✅ Safe
}

// Or initialize immediately
Zombie* zombie_ptr = new Zombie("Initialized");
zombie_ptr->announce();  // ✅ Safe
```

## Building & Testing

### **Build Commands**
```bash
# Build all exercises
make

# Build specific exercise
make newZombie
make randomChump

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = zombie_program

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
# Test individual zombie creation
$> ./newZombie
Leaky is created
Leaky: BraiiiiiiinnnzzzZ...

# Test stack zombie creation
$> ./randomChump "Testie"
Stackie is created
Stackie: BraiiiiiiinnnzzzZ...
Stackie is destroyed

# Test zombie horde
$> ./zombieHorde 5 "Horde"
Horde0 is created
Horde1 is created
...
Horde0: BraiiiiiiinnnzzzZ...
Horde1: BraiiiiiiinnnzzzZ...
```

## Best Practices

### **Memory Management**
- Always initialize pointers
- Pair every `new` with a `delete`
- Use `delete[]` for arrays, `delete` for single objects
- Prefer RAII over manual management when possible

### **Pointer Safety**
- Check for NULL before dereferencing
- Avoid returning pointers to local variables
- Use `const` for pointers that shouldn't modify data
- Clear pointers after deletion

### **Class Design**
- Make members private when possible
- Use constructor initialization lists
- Implement proper destructors
- Keep classes focused and single-purpose

## Further Learning Resources

### **Official Documentation**
- [Pointers - cppreference](https://en.cppreference.com/w/cpp/language/pointer)
- [new/delete - cppreference](https://en.cppreference.com/w/cpp/language/new)
- [Destructors - cppreference](https://en.cppreference.com/w/cpp/language/destructor)

### **Educational Resources**
- [Pointers Explained Simply - GeeksforGeeks](https://www.geeksforgeeks.org/pointers-in-cpp-explained-simply/)
- [Memory Allocation - GeeksforGeeks](https://www.geeksforgeeks.org/memory-management-in-cpp/)
- [RAII in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/raii-in-cpp/)
- [Stack vs Heap Memory - GeeksforGeeks](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)

### **Practice Suggestions**
- Experiment with different allocation strategies
- Practice pointer arithmetic
- Try implementing smart pointer concepts
- Study memory layout and alignment

## Connection to Next Module

This module provides the **foundation for object-oriented programming** in CPP_02. The concepts you'll need:

- **Class design principles** for advanced OOP concepts
- **Memory management** for copy constructor implementation
- **Object lifetime** for assignment operator patterns
- **Pointer usage** for operator overloading

**Next: [CPP_02 - OOP Fundamentals](../cpp_02/README.md)**

---

## Summary

CPP_01 introduces essential memory management concepts through practical zombie-themed exercises. You'll master:
- Stack vs heap allocation strategies
- Pointer operations and safety
- RAII principles and automatic resource management
- Basic class design and implementation
- Memory leak prevention techniques

These fundamentals are crucial for understanding advanced object-oriented programming concepts and patterns in subsequent modules.