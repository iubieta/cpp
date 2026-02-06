# CPP_02 - OOP Fundamentals

> **Subject:** [CPP_02 PDF](CPP_02.pdf)

## Module Overview

This module introduces fundamental Object-Oriented Programming concepts in C++, focusing on the Orthodox Canonical Form, operator overloading, and advanced class design patterns. You'll learn how to create robust, copy-safe classes and implement custom behavior through operator overloading.

## Key Learning Objectives

### **Object-Oriented Programming**
- Orthodox Canonical Form implementation
- Copy constructor and assignment operator patterns
- Operator overloading for custom behavior
- Fixed-point number system implementation
- Ad-hoc polymorphism concepts

### **Advanced Class Design**
- Encapsulation and access control
- Proper resource management in classes
- Const correctness in member functions
- Efficient copying and assignment patterns

## Exercises Summary

### **Exercise 00 - Orthodox Canonical Form**
**Files:** `Makefile`, `main.cpp`, `Fixed.class.hpp`, `Fixed.class.cpp`
**Goal:** Implement a fixed-point number class in Orthodox Canonical Form

**Learning Focus:**
- Default constructor implementation
- Copy constructor deep copying
- Assignment operator with self-assignment check
- Integer/fixed-point conversion logic
- Comparison operator overloading

### **Exercise 01 - Fixed Point Exponents**
**Files:** `Makefile`, `main.cpp`
**Goal:** Add exponentiation functionality to Fixed class

**Learning Focus:**
- Exponent operator implementation
- Power calculation algorithms
- Const correctness in operators
- Performance considerations for repeated multiplication

### **Exercise 02 - Ad-hoc Polymorphism**
**Files:** `Makefile`, `main.cpp`, `Base.class.hpp`, `Base.class.cpp`, `Derived.class.hpp`, `Derived.class.cpp`
**Goal:** Implement simple polymorphism with object destruction

**Learning Focus:**
- Basic polymorphic behavior
- Virtual destructor implementation
- Base class pointer usage
- Dynamic dispatch understanding

### **Exercise 03 - BSP Functions**
**Files:** `Makefile`, `main.cpp`, `Fixed.class.hpp`, `Fixed.class.cpp`
**Goal:** Add mathematical functions to Fixed class

**Learning Focus:**
- Standalone function implementation
- Fixed-point arithmetic operations
- Integration with class methods
- Performance optimization techniques

## Core Concepts Explained

### **Orthodox Canonical Form**

The Orthodox Canonical Form ensures classes behave predictably in all common scenarios:

```cpp
class Fixed {
private:
    int raw_value;  // Internal representation
    
public:
    // 1. Default constructor
    Fixed();
    
    // 2. Copy constructor
    Fixed(const Fixed& other);
    
    // 3. Assignment operator
    Fixed& operator=(const Fixed& other);
    
    // 4. Destructor
    ~Fixed();
};
```

**Why Each Component Matters:**
- **Default constructor:** Enables object arrays and default initialization
- **Copy constructor:** Proper initialization from other objects
- **Assignment operator:** Safe value assignment after construction
- **Destructor:** Proper cleanup and resource release

### **Copy Constructor Implementation**

```cpp
// Copy constructor - creates new object from existing one
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->raw_value = other.raw_value;  // Copy the internal value
}

// Alternative: Use member initialization list
Fixed::Fixed(const Fixed& other) : raw_value(other.raw_value) {
    std::cout << "Copy constructor called" << std::endl;
}
```

### **Assignment Operator Pattern**

```cpp
// Assignment operator - safe assignment between existing objects
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    // 1. Check for self-assignment
    if (this != &other) {
        // 2. Copy the data
        this->raw_value = other.raw_value;
    }
    
    // 3. Return reference to self for chaining
    return *this;
}
```

### **Operator Overloading**

```cpp
// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.raw_value = this->raw_value + other.raw_value;
    return result;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->raw_value > other.raw_value;
}

// Stream operators (as free functions)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();  // Convert to float for display
    return os;
}
```

### **Fixed-Point Number System**

```cpp
class Fixed {
private:
    static const int fractional_bits = 8;
    int raw_value;  // Stores value shifted by fractional_bits
    
public:
    // Constructor from float
    Fixed(float value) {
        raw_value = roundf(value * (1 << fractional_bits));
    }
    
    // Convert back to float
    float toFloat(void) const {
        return (float)raw_value / (1 << fractional_bits);
    }
    
    // Convert to int
    int toInt(void) const {
        return raw_value >> fractional_bits;
    }
};
```

## Implementation Patterns

### **Complete Orthodox Canonical Form**

```cpp
// Fixed.hpp
#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    int raw_value;
    static const int fractional_bits = 8;
    
public:
    // Constructors
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);
    
    // Destructor
    ~Fixed();
    
    // Assignment
    Fixed& operator=(const Fixed& other);
    
    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    
    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    // Increment/decrement
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    
    // Conversion
    float toFloat(void) const;
    int toInt(void) const;
    
    // Static min/max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
};

// Stream operator (free function)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
```

### **Exponent Implementation**

```cpp
// Power function for fixed-point numbers
Fixed Fixed::pow(Fixed const& base, int exponent) const {
    if (exponent == 0) {
        return Fixed(1);  // Any number to power 0 is 1
    }
    
    if (exponent < 0) {
        // Handle negative exponents
        return Fixed(0);  // Simplified for this example
    }
    
    Fixed result(1);
    Fixed current(base);
    
    for (int i = 0; i < exponent; i++) {
        result = result * current;
    }
    
    return result;
}
```

### **Virtual Polymorphism**

```cpp
// Base class with virtual destructor
class Base {
public:
    Base() { std::cout << "Base constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

// Derived class
class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

// Usage demonstrating polymorphic destruction
void demonstrate_polymorphism() {
    Base* ptr = new Derived();  // Base constructor, then Derived
    delete ptr;  // Derived destructor, then Base (correct!)
}
```

## Common Pitfalls & Solutions

### **Pitfall 1: Incomplete Copy Constructor**
```cpp
// ❌ Problem: Shallow copy
Fixed::Fixed(const Fixed& other) {
    this->raw_value = other.raw_value;  // Missing initialization
}

// ✅ Solution: Proper member initialization
Fixed::Fixed(const Fixed& other) : raw_value(other.raw_value) {
    // No additional work needed
}
```

### **Pitfall 2: Assignment Operator Issues**
```cpp
// ❌ Problem: No self-assignment check
Fixed& Fixed::operator=(const Fixed& other) {
    this->raw_value = other.raw_value;  // Problem if assigning to self
    return *this;
}

// ❌ Problem: No return reference
void Fixed::operator=(const Fixed& other) {
    this->raw_value = other.raw_value;
    // Can't chain assignments
}

// ✅ Solution: Complete assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {  // Self-assignment check
        this->raw_value = other.raw_value;
    }
    return *this;  // Enable chaining
}
```

### **Pitfall 3: Const Incorrectness**
```cpp
// ❌ Problem: Modifying in const method
float Fixed::toFloat(void) const {
    this->raw_value = 0;  // ❌ Can't modify const object
    return (float)this->raw_value / (1 << 8);
}

// ✅ Solution: Preserve const correctness
float Fixed::toFloat(void) const {
    return (float)this->raw_value / (1 << 8);  // ✅ No modification
}
```

### **Pitfall 4: Missing Virtual Destructor**
```cpp
// ❌ Problem: Non-virtual destructor
class Base {
public:
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

// Only Base destructor called!
Base* ptr = new Derived();
delete ptr;  // Memory leak - Derived destructor not called

// ✅ Solution: Virtual destructor
class Base {
public:
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};
// Now both destructors called correctly
```

## Building & Testing

### **Build Commands**
```bash
# Build the Fixed class project
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp
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
# Test Orthodox Canonical Form
$> ./fixed
Default constructor called
Copy constructor called
Copy assignment operator called
Destructor called
Destructor called

# Test fixed-point arithmetic
$> ./fixed
5.05 * 2 = 10.10
5.05 + 2 = 7.05

# Test stream operator
$> ./fixed
Fixed value: 42.25
```

## Best Practices

### **Orthodox Canonical Form**
- Always implement all four components consistently
- Use member initialization lists in constructors
- Check for self-assignment in assignment operator
- Return reference from assignment operator

### **Operator Overloading**
- Implement both const and non-const versions when appropriate
- Preserve logical meaning of operators
- Implement free functions for binary operators
- Consider performance in operator chains

### **Const Correctness**
- Mark methods that don't modify object as const
- Use const references for parameters when possible
- Implement const versions of member functions
- Avoid const_cast unless absolutely necessary

## Further Learning Resources

### **Official Documentation**
- [Copy Constructor - cppreference](https://en.cppreference.com/w/cpp/language/copy_constructor)
- [Assignment Operator - cppreference](https://en.cppreference.com/w/cpp/language/copy_assignment)
- [Operator Overloading - cppreference](https://en.cppreference.com/w/cpp/language/operators)

### **Educational Resources**
- [Classes and Objects - GeeksforGeeks](https://www.geeksforgeeks.org/classes-objects-cpp/)
- [Operator Overloading in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/operator-overloading-cpp/)
- [Orthodox Canonical Form - GeeksforGeeks](https://www.geeksforgeeks.org/orthodox-canonical-class-form/)
- [Virtual Functions - GeeksforGeeks](https://www.geeksforgeeks.org/virtual-functions-in-cpp/)

### **Practice Suggestions**
- Implement different number systems (complex numbers, fractions)
- Practice operator overloading with custom types
- Study performance implications of copy operations
- Explore move semantics (C++11+ concept)

## Connection to Next Module

This module provides the **foundation for inheritance** in CPP_03. The concepts you'll need:

- **Class design principles** for inheritance hierarchies
- **Copy semantics** for derived class behavior
- **Virtual function basics** for polymorphism
- **Object lifetime management** for complex hierarchies

**Next: [CPP_03 - Inheritance](../cpp_03/README.md)**

---

## Summary

CPP_02 introduces fundamental OOP concepts through practical fixed-point number exercises. You'll master:
- Orthodox Canonical Form implementation
- Copy constructor and assignment operator patterns
- Operator overloading for custom behavior
- Fixed-point arithmetic implementation
- Basic polymorphism concepts
- Const correctness and resource management

These patterns form the foundation for understanding inheritance, polymorphism, and advanced object-oriented design in subsequent modules.