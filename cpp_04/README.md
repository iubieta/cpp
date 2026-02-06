# CPP_04 - Subtype Polymorphism

> **Subject:** [CPP_04 PDF](CPP_04.pdf)

## Module Overview

This module introduces advanced polymorphism concepts, focusing on abstract classes, interfaces, and subtype polymorphism. You'll learn how to design flexible class hierarchies using pure virtual functions and abstract base classes.

## Key Learning Objectives

### **Advanced Polymorphism**
- Abstract classes and pure virtual functions
- Interface design and implementation
- Multiple inheritance for interface combination
- Dynamic dispatch and object slicing prevention

### **Design Patterns**
- Interface segregation principles
- Abstract base class design
- Polymorphic collections and usage
- Type-safe downcasting techniques

## Exercises Summary

### **Exercise 00 - Polymorphism**
**Files:** `Makefile`, `A.hpp`, `A.cpp`, `B.hpp`, `B.cpp`, `C.hpp`, `C.cpp`, `main.cpp`
**Goal:** Create a simple polymorphic hierarchy

**Learning Focus:**
- Abstract class design
- Pure virtual function implementation
- Base class pointer usage
- Polymorphic behavior demonstration

### **Exercise 01 - I Don't Want to Set the World on Fire**
**Files:** `Makefile`, `A.hpp`, `A.cpp`, `B.hpp`, `B.cpp`, `C.hpp`, `C.cpp`, `main.cpp`
**Goal:** Implement a specific polymorphic scenario

**Learning Focus:**
- Multiple inheritance for interfaces
- Object identification patterns
- Polymorphic deletion importance
- Interface combination techniques

### **Exercise 02 - Abstract Class**
**Files:** `Makefile`, `AWeapon.hpp`, `AWeapon.cpp`, `Character.hpp`, `Character.cpp`, `main.cpp`
**Goal:** Create abstract weapon and character classes

**Learning Focus:**
- Abstract class implementation
- Interface segregation
- Composition with abstract types
- Polymorphic method invocation

### **Exercise 03 - Interface & Recap**
**Files:** `Makefile`, `AMateria.hpp`, `AMateria.cpp`, `IMateriaSource.hpp`, `IMateriaSource.cpp`, `MateriaSource.hpp`, `MateriaSource.cpp`, `main.cpp`
**Goal:** Complete interface design with factory pattern

**Learning Focus:**
- Complete interface implementation
- Factory method pattern
- Polymorphic creation and management
- Advanced inheritance design

## Core Concepts Explained

### **Abstract Classes**

```cpp
// Abstract class - cannot be instantiated
class Animal {
protected:
    std::string type;
    
public:
    Animal(std::string animal_type) : type(animal_type) {}
    
    // Pure virtual function makes class abstract
    virtual void makeSound() = 0;
    
    // Virtual destructor for proper cleanup
    virtual ~Animal() {}
};

// Concrete derived classes
class Dog : public Animal {
public:
    Dog() : Animal("Dog") {}
    
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat") {}
    
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Usage
void demonstrateAbstract() {
    // Animal animal;  // ❌ Cannot instantiate abstract class
    Animal* dog = new Dog();     // ✅ Can create derived
    Animal* cat = new Cat();
    
    dog->makeSound();  // "Woof!"
    cat->makeSound();  // "Meow!"
    
    delete dog;
    delete cat;
}
```

### **Pure Virtual Functions**

```cpp
class Shape {
public:
    // Pure virtual function - no implementation
    virtual double area() = 0;
    virtual double perimeter() = 0;
    
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    double perimeter() override {
        return 2 * (width + height);
    }
};
```

### **Interface Design**

```cpp
// Interface - pure abstract class
class IDrawable {
public:
    virtual void draw() = 0;
    virtual ~IDrawable() {}
};

class IMovable {
public:
    virtual void move(int dx, int dy) = 0;
    virtual ~IMovable() {}
};

// Multiple inheritance for interface combination
class Sprite : public IDrawable, public IMovable {
private:
    int x, y;
    
public:
    Sprite(int start_x, int start_y) : x(start_x), y(start_y) {}
    
    void draw() override {
        std::cout << "Drawing sprite at (" << x << ", " << y << ")" << std::endl;
    }
    
    void move(int dx, int dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving sprite to (" << x << ", " << y << ")" << std::endl;
    }
};
```

### **Polymorphic Collections**

```cpp
// Using polymorphic collections
void processShapes() {
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Circle(3.0);
    
    double total_area = 0;
    
    // Polymorphic processing
    for (int i = 0; i < 3; i++) {
        total_area += shapes[i]->area();
        std::cout << "Shape " << i << " area: " << shapes[i]->area() << std::endl;
    }
    
    std::cout << "Total area: " << total_area << std::endl;
    
    // Proper cleanup
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
}
```

### **Factory Pattern with Abstract Classes**

```cpp
// Abstract base class for materia
class AMateria {
protected:
    std::string type;
    
public:
    AMateria(std::string materia_type);
    virtual ~AMateria();
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
    
    std::string const& getType() const;
};

// Interface for materia source
class IMateriaSource {
public:
    virtual ~IMateriaSource();
    virtual AMateria* createMateria(std::string const& type) = 0;
};

// Concrete materia implementations
class Ice : public AMateria {
public:
    Ice();
    AMateria* clone() const override;
    void use(ICharacter& target) override;
};

class Cure : public AMateria {
public:
    Cure();
    AMateria* clone() const override;
    void use(ICharacter& target) override;
};

// Factory implementation
class MateriaSource : public IMateriaSource {
private:
    AMateria* materias[4];
    int materia_count;
    
public:
    MateriaSource();
    ~MateriaSource();
    
    void learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const& type);
};
```

## Implementation Patterns

### **Abstract Base Class Design**

```cpp
// AWeapon.hpp - Abstract weapon class
#ifndef AWEAPON_H
# define AWEAPON_H

#include <string>

class AWeapon {
protected:
    std::string name;
    int damage;
    std::string action;
    
public:
    AWeapon(std::string const& name, int damage, std::string const& action);
    virtual ~AWeapon();
    
    // Pure virtual function - makes class abstract
    virtual void attack() const = 0;
    
    // Accessors
    std::string const& getName() const;
    int getAPCost() const;
};

#endif
```

### **Concrete Implementations**

```cpp
// Concrete weapon implementations
class PlasmaRifle : public AWeapon {
public:
    PlasmaRifle();
    ~PlasmaRifle();
    
    void attack() const override {
        std::cout << "* piouuu piouuu piouuu *" << std::endl;
    }
};

class PowerFist : public AWeapon {
public:
    PowerFist();
    ~PowerFist();
    
    void attack() const override {
        std::cout << "* pschhh... SCHWING... *" << std::endl;
    }
};
```

### **Character with Abstract Composition**

```cpp
// Character.hpp - Uses abstract weapon
#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "AWeapon.hpp"

class AWeapon;

class Character {
private:
    std::string name;
    int ap;
    AWeapon* weapon;
    
public:
    Character(std::string const& name);
    Character(Character const& other);
    ~Character();
    
    Character& operator=(Character const& other);
    
    void equip(AWeapon* weapon);
    void attack(std::string const& target);
    void recoverAP();
    
    // Accessors
    std::string const& getName() const;
    int getAP() const;
    AWeapon* getWeapon() const;
};

#endif
```

### **Interface Implementation**

```cpp
// IMateriaSource.hpp - Interface
#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource();
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif

// MateriaSource.hpp - Concrete implementation
class MateriaSource : public IMateriaSource {
private:
    static const int max_materias = 4;
    AMateria* materias[max_materias];
    int materia_count;
    
public:
    MateriaSource();
    MateriaSource(MateriaSource const& other);
    MateriaSource& operator=(MateriaSource const& other);
    ~MateriaSource();
    
    void learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const& type);
};
```

## Common Pitfalls & Solutions

### **Pitfall 1: Object Slicing**
```cpp
// ❌ Problem: Object slicing
void processAnimal(Animal animal) {  // Pass by value
    animal.makeSound();  // May call Animal version, not derived
}

Dog dog;
processAnimal(dog);  // Dog sliced to Animal

// ✅ Solution: Use pointers or references
void processAnimal(Animal* animal) {  // Pass by pointer
    animal->makeSound();  // Polymorphic call
}

void processAnimal(Animal& animal) {  // Pass by reference
    animal.makeSound();  // Polymorphic call
}
```

### **Pitfall 2: Missing Virtual Destructor**
```cpp
// ❌ Problem: Non-virtual destructor in abstract class
class Base {
public:
    virtual void func() = 0;
    ~Base() {}  // ❌ Not virtual
};

class Derived : public Base {
public:
    void func() override { /* ... */ }
    ~Derived() { /* cleanup */ }
};

Base* ptr = new Derived();
delete ptr;  // ❌ Only Base destructor called - leak!

// ✅ Solution: Virtual destructor
class Base {
public:
    virtual void func() = 0;
    virtual ~Base() {}  // ✅ Virtual
};
```

### **Pitfall 3: Instantiating Abstract Class**
```cpp
// ❌ Problem: Trying to instantiate abstract class
class Abstract {
public:
    virtual void func() = 0;
};

Abstract obj;  // ❌ Compilation error

// ✅ Solution: Use concrete derived class
class Concrete : public Abstract {
public:
    void func() override { /* implementation */ }
};

Concrete obj;  // ✅ Valid
Abstract* ptr = new Concrete();  // ✅ Also valid
```

### **Pitfall 4: Interface Implementation Issues**
```cpp
// ❌ Problem: Not implementing all pure virtual functions
class IDrawable {
public:
    virtual void draw() = 0;
    virtual void resize(int w, int h) = 0;
};

class BadShape : public IDrawable {
public:
    void draw() override { /* implementation */ }
    // ❌ Missing resize() - still abstract!
};

// ✅ Solution: Implement all pure virtual functions
class GoodShape : public IDrawable {
public:
    void draw() override { /* implementation */ }
    void resize(int w, int h) override { /* implementation */ }
    // ✅ Now concrete
};
```

## Building & Testing

### **Build Commands**
```bash
# Build the polymorphism project
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = polymorphism_demo

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp A.cpp B.cpp C.cpp AMateria.cpp MateriaSource.cpp Character.cpp
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
# Test abstract class behavior
$> ./polymorphism_demo
Abstract class demonstration:
Dog: Woof!
Cat: Meow!
Area of circle: 78.5398
Area of rectangle: 24.0000

# Test interface usage
$> ./polymorphism_demo
Drawing sprite at (10, 20)
Moving sprite to (15, 25)
Drawing sprite at (15, 25)

# Test factory pattern
$> ./polymorphism_demo
Creating Ice materia
Creating Cure materia
Using Ice on target
Using Cure on target
```

## Best Practices

### **Abstract Class Design**
- Make classes abstract when they have no complete implementation
- Use pure virtual functions for required behavior
- Always provide virtual destructor
- Keep abstract classes focused and cohesive

### **Interface Design**
- Keep interfaces small and focused
- Use pure virtual functions (= 0)
- Consider multiple inheritance for interface combination
- Document intended usage patterns

### **Polymorphic Usage**
- Use pointers or references for polymorphic behavior
- Avoid object slicing by value
- Ensure proper cleanup with virtual destructors
- Consider performance implications of virtual calls

## Further Learning Resources

### **Official Documentation**
- [Abstract Classes - cppreference](https://en.cppreference.com/w/cpp/language/abstract_class)
- [Pure Virtual Functions - cppreference](https://en.cppreference.com/w/cpp/language/virtual)
- [Multiple Inheritance - cppreference](https://en.cppreference.com/w/cpp/language/multiple_inheritance)

### **Educational Resources**
- [Abstract Classes in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/abstract-classes-in-cpp/)
- [Interface Design - GeeksforGeeks](https://www.geeksforgeeks.org/interfaces-in-cpp/)
- [Polymorphism Examples - GeeksforGeeks](https://www.geeksforgeeks.org/polymorphism-in-c/)
- [Factory Pattern - GeeksforGeeks](https://www.geeksforgeeks.org/factory-method-cpp-design-patterns/)

### **Practice Suggestions**
- Create your own abstract class hierarchies
- Experiment with different interface combinations
- Practice factory pattern implementations
- Study performance characteristics of virtual functions

## Connection to Next Module

This module provides the **foundation for exception handling** in CPP_05. The concepts you'll need:

- **Class design principles** for robust error handling
- **Polymorphic behavior** for exception hierarchies
- **Interface understanding** for exception design
- **Constructor patterns** for exception safety

**Next: [CPP_05 - Exceptions & Repetition](../cpp_05/README.md)**

---

## Summary

CPP_04 introduces advanced polymorphism concepts through practical interface and abstract class exercises. You'll master:
- Abstract class design and implementation
- Pure virtual functions and interfaces
- Multiple inheritance for interface combination
- Factory pattern implementation
- Polymorphic collection management
- Object slicing prevention techniques

These concepts are crucial for understanding exception handling, template programming, and advanced design patterns in subsequent modules.