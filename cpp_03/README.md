# CPP_03 - Inheritance

> **Subject:** [CPP_03 PDF](CPP_03.pdf)

## Module Overview

This module introduces inheritance in C++, focusing on single inheritance hierarchies, virtual functions, and the diamond problem. You'll learn how to create class hierarchies and implement polymorphic behavior through virtual methods.

## Key Learning Objectives

### **Inheritance Concepts**
- Single inheritance implementation
- Virtual function tables and dispatch
- Constructor and destructor order in inheritance
- Protected member access
- Abstract vs concrete classes

### **Advanced Polymorphism**
- The diamond problem and virtual inheritance
- Virtual destructors importance
- Upcasting and downcasting concepts
- Dynamic binding vs static binding

## Exercises Summary

### **Exercise 00 - ClapTrap**
**Files:** `Makefile`, `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`
**Goal:** Create a base ClapTrap class with proper inheritance structure

**Learning Focus:**
- Basic class design for inheritance
- Constructor/destructor implementation
- Member function design
- Output formatting and debugging

### **Exercise 01 - ClapTrap Copy**
**Files:** `Makefile`, `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`
**Goal:** Implement copy behavior for ClapTrap

**Learning Focus:**
- Copy constructor in inheritance context
- Copy semantics in class hierarchies
- Default constructor importance
- Object initialization order

### **Exercise 02 - ScavTrap**
**Files:** `Makefile`, `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `main.cpp`
**Goal:** Create ScavTrap inheriting from ClapTrap

**Learning Focus:**
- Single inheritance implementation
- Constructor delegation to base class
- Inherited vs new functionality
- Protected member access

### **Exercise 03 - Diamond Problem**
**Files:** `Makefile`, `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `main.cpp`
**Goal:** Demonstrate and solve the diamond inheritance problem

**Learning Focus:**
- Multiple inheritance challenges
- Virtual inheritance solution
- Constructor order in complex hierarchies
- Member access resolution

## Core Concepts Explained

### **Single Inheritance Basics**

```cpp
// Base class
class ClapTrap {
protected:
    std::string name;
    int hit_points;
    int energy_points;
    
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

// Derived class
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
    
    // Inherited functions available:
    // attack(), takeDamage(), beRepaired()
};
```

### **Constructor Order in Inheritance**

```cpp
// Constructor execution order:
// 1. Base class constructor
// 2. Derived class constructor

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ClapTrap constructor called" << std::endl;
    std::cout << "ScavTrap constructor called" << std::endl;
}

// Destructor execution order:
// 1. Derived class destructor
// 2. Base class destructor

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}
```

### **Virtual Functions**

```cpp
class ClapTrap {
protected:
    std::string name;
    
public:
    ClapTrap(std::string name);
    virtual ~ClapTrap();  // Virtual for polymorphic deletion
    
    virtual void attack(std::string const& target);
    void takeDamage(unsigned int amount);
};

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    
    // Override base class function
    void attack(std::string const& target) override;
    void guardGate();
};

// Usage demonstrates polymorphism
void demonstrate_virtual() {
    ClapTrap* traps[2];
    traps[0] = new ClapTrap("Clappy");
    traps[1] = new ScavTrap("Scavvy");
    
    // Calls appropriate function based on actual type
    for (int i = 0; i < 2; i++) {
        traps[i]->attack("Target");  // Polymorphic call
    }
    
    delete[] traps;  // Both destructors called due to virtual destructor
}
```

### **The Diamond Problem**

```cpp
// Problem: Multiple inheritance diamond
class A {
public:
    void func() { std::cout << "A::func()" << std::endl; }
    int value;
};

class B : public A {
public:
    void func() { std::cout << "B::func()" << std::endl; }
};

class C : public A {
public:
    void func() { std::cout << "C::func()" << std::endl; }
};

// Diamond: D inherits from both B and C
class D : public B, public C {
public:
    void func() { std::cout << "D::func()" << std::endl; }
    
    // Problem: Which A::value do we inherit?
};

// Solution: Virtual inheritance
class A {
public:
    void func() { std::cout << "A::func()" << std::endl; }
    int value;
};

class B : virtual public A {
public:
    void func() { std::cout << "B::func()" << std::endl; }
};

class C : virtual public A {
public:
    void func() { std::cout << "C::func()" << std::endl; }
};

class D : public B, public C {
public:
    void func() { std::cout << "D::func()" << std::endl; }
    // Solution: Only one A base, no ambiguity
};
```

### **Virtual Inheritance**

```cpp
// Virtual inheritance solves diamond problem
class ClapTrap {
protected:
    std::string name;
    int hit_points;
    int energy_points;
    
public:
    ClapTrap(std::string name);
    virtual ~ClapTrap();
    void attack(std::string const& target);
};

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
};

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(std::string name);
    ~FragTrap();
    void vaulthunter_dot_exe(std::string const& target);
};

// Final class inheriting from both
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void whoAmI();
    
    // Access to ClapTrap members is unambiguous due to virtual inheritance
};
```

## Implementation Patterns

### **Base Class Design**

```cpp
// ClapTrap.hpp
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string name;
    int hit_points;
    int max_hit_points;
    int energy_points;
    int max_energy_points;
    int attack_damage;
    
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();
    
    ClapTrap& operator=(const ClapTrap& other);
    
    virtual void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    // Accessors
    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
};

#endif
```

### **Derived Class Implementation**

```cpp
// ScavTrap.hpp
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
    static const int default_hit_points = 100;
    static const int default_energy_points = 50;
    static const int default_attack_damage = 20;
    
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    
    ScavTrap& operator=(const ScavTrap& other);
    
    void attack(std::string const& target);
    void guardGate(void);
};

#endif
```

### **Virtual Inheritance Solution**

```cpp
// DiamondTrap demonstrates virtual inheritance
class DiamondTrap : public ScavTrap, public FragTrap {
private:
    static const int default_hit_points = 100;
    static const int default_energy_points = 50;
    static const int default_attack_damage = 30;
    
public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    
    DiamondTrap& operator=(const DiamondTrap& other);
    
    void whoAmI(void);
    void attack(std::string const& target);
    
    // Combine functionality from both parents
    void guardGate(void);
    void vaulthunter_dot_exe(std::string const& target);
};

// Implementation resolves base class calls
void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap " << this->name 
              << " created from ScavTrap and FragTrap" << std::endl;
}
```

## Common Pitfalls & Solutions

### **Pitfall 1: Missing Virtual Destructor**
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

// Only Base destructor called - memory leak!
Base* ptr = new Derived();
delete ptr;

// ✅ Solution: Virtual destructor
class Base {
public:
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};
// Both destructors called correctly
```

### **Pitfall 2: Constructor Delegation Issues**
```cpp
// ❌ Problem: Not calling base constructor
ScavTrap::ScavTrap(std::string name) {
    // Base class not properly initialized
    this->name = name;  // Direct access - bad practice
}

// ✅ Solution: Proper constructor delegation
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Base class properly initialized
    // Additional ScavTrap-specific initialization
    this->attack_damage = 20;
}
```

### **Pitfall 3: Diamond Problem Ambiguity**
```cpp
// ❌ Problem: Ambiguous base class access
class Diamond : public ScavTrap, public FragTrap {
public:
    void useName() {
        std::cout << this->name;  // ❌ Ambiguous: which name?
    }
};

// ✅ Solution: Virtual inheritance
class ScavTrap : virtual public ClapTrap { /* ... */ };
class FragTrap : virtual public ClapTrap { /* ... */ };

class Diamond : public ScavTrap, public FragTrap {
public:
    void useName() {
        std::cout << this->name;  // ✅ Unambiguous - single ClapTrap base
    }
};
```

### **Pitfall 4: Incorrect Virtual Function Override**
```cpp
// ❌ Problem: Wrong function signature
class Base {
public:
    virtual void func(int value);
};

class Derived : public Base {
public:
    void func(double value);  // ❌ Different signature - overload, not override
};

// ✅ Solution: Match exact signature
class Derived : public Base {
public:
    void func(int value);  // ✅ Correct override
};

// Better yet, use override keyword (C++11, but good practice to understand)
class Derived : public Base {
public:
    void func(int value) override;  // Compile-time verification
};
```

## Building & Testing

### **Build Commands**
```bash
# Build the inheritance project
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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
# Test basic inheritance
$> ./claptrap
ClapTrap constructor called
ClapTrap attacks target, causing 5 points of damage!

# Test derived class
$> ./claptrap
ClapTrap constructor called
ScavTrap constructor called
ScavTrap attacks target, causing 20 points of damage!

# Test virtual inheritance
$> ./claptrap
ClapTrap constructor called
ScavTrap constructor called
FragTrap constructor called
DiamondTrap constructor called
DiamondTrap attacks target, causing 30 points of damage!
DiamondTrap is on guard!
```

## Best Practices

### **Inheritance Design**
- Use inheritance for "is-a" relationships, not "has-a"
- Keep inheritance hierarchies shallow and focused
- Prefer composition over inheritance when appropriate
- Use virtual inheritance only when necessary (diamond problem)

### **Virtual Functions**
- Always make base class destructor virtual
- Mark functions virtual when they might be overridden
- Understand the cost of virtual function calls
- Use const correctness in virtual functions

### **Constructor/Destructor Order**
- Remember constructor order: base → derived
- Remember destructor order: derived → base
- Always call base class constructors explicitly
- Use virtual inheritance to avoid duplicate base construction

## Further Learning Resources

### **Official Documentation**
- [Inheritance - cppreference](https://en.cppreference.com/w/cpp/language/inheritance)
- [Virtual Functions - cppreference](https://en.cppreference.com/w/cpp/language/virtual)
- [Virtual Inheritance - cppreference](https://en.cppreference.com/w/cpp/language/virtual_inheritance)

### **Educational Resources**
- [Inheritance Explained - GeeksforGeeks](https://www.geeksforgeeks.org/inheritance-in-c/)
- [Virtual Functions - GeeksforGeeks](https://www.geeksforgeeks.org/virtual-functions-in-cpp/)
- [Diamond Problem - GeeksforGeeks](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)
- [Virtual Inheritance - GeeksforGeeks](https://www.geeksforgeeks.org/virtual-inheritance-in-c/)

### **Practice Suggestions**
- Create your own inheritance hierarchies
- Practice with different access specifiers
- Experiment with virtual vs non-virtual functions
- Study the impact of inheritance on memory layout

## Connection to Next Module

This module provides the **foundation for advanced polymorphism** in CPP_04. The concepts you'll need:

- **Inheritance basics** for abstract classes and interfaces
- **Virtual function understanding** for pure virtual functions
- **Constructor order** for complex initialization scenarios
- **Base/derived relationships** for interface design

**Next: [CPP_04 - Subtype Polymorphism](../cpp_04/README.md)**

---

## Summary

CPP_03 introduces inheritance concepts through practical trap-themed exercises. You'll master:
- Single inheritance implementation and design
- Virtual functions and polymorphic behavior
- Constructor/destructor order in inheritance
- The diamond problem and virtual inheritance solutions
- Protected member access and usage
- Object slicing prevention techniques

These concepts are crucial for understanding abstract classes, interfaces, and advanced polymorphism patterns in subsequent modules.