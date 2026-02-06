# CPP_07 - Templates

> **Subject:** [CPP_07 PDF](CPP_07.pdf)

## Module Overview

This module introduces C++ templates, focusing on generic programming through template functions and classes. You'll learn how to write code that works with multiple data types while maintaining type safety and performance.

## Key Learning Objectives

### **Template Programming**
- Function templates and type deduction
- Class templates and member implementation
- Template specialization and partial specialization
- Template instantiation and compilation

### **Generic Programming**
- Type-independent algorithms
- Container design patterns
- Iterator implementation with templates
- Compile-time polymorphism

## Exercises Summary

### **Exercise 00 - Easy Find**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement a simple template function to find elements

**Learning Focus:**
- Basic function template syntax
- Type deduction in templates
- Template instantiation patterns
- Iterator compatibility

### **Exercise 01 - Iter**
**Files:** `Makefile`, `main.cpp`
**Goal:** Create a template iterator class

**Learning Focus:**
- Template class design
- Iterator interface implementation
- Operator overloading in templates
- Container-iteration patterns

### **Exercise 02 - Array**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement a template array container

**Learning Focus:**
- Template container design
- Element access and bounds checking
- Copy semantics in template classes
- Exception handling in templates

## Core Concepts Explained

### **Function Templates**

```cpp
// Basic function template
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage with different types
int max_int = max(10, 20);           // T = int
double max_double = max(3.14, 2.71);   // T = double
std::string max_str = max("hello", "world"); // T = std::string

// Template with multiple parameters
template<typename T, typename U>
void printPair(T first, U second) {
    std::cout << "(" << first << ", " << second << ")" << std::endl;
}

// Template with non-type parameters
template<typename T, int SIZE>
void printArray(T (&arr)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
```

### **Class Templates**

```cpp
// Basic template class
template<typename T>
class Pair {
private:
    T first;
    T second;
    
public:
    Pair(T f, T s) : first(f), second(s) {}
    
    T getFirst() const { return first; }
    T getSecond() const { return second; }
    
    void setFirst(T f) { first = f; }
    void setSecond(T s) { second = s; }
};

// Usage with different types
Pair<int> int_pair(10, 20);
Pair<std::string> string_pair("hello", "world");
Pair<double> double_pair(3.14, 2.71);
```

### **Template Specialization**

```cpp
// General template
template<typename T>
class Container {
private:
    T data;
    
public:
    Container(T d) : data(d) {}
    
    void print() {
        std::cout << "Generic: " << data << std::endl;
    }
};

// Full specialization for const char*
template<>
class Container<const char*> {
private:
    const char* data;
    
public:
    Container(const char* d) : data(d) {}
    
    void print() {
        std::cout << "String: " << data << " (length: " << strlen(data) << ")" << std::endl;
    }
};

// Usage
Container<int> int_container(42);
int_container.print();  // "Generic: 42"

Container<const char*> string_container("Hello World");
string_container.print();  // "String: Hello World (length: 11)"
```

### **Iterator Template Implementation**

```cpp
// Template iterator class
template<typename T>
class ArrayIterator {
private:
    T* current;
    
public:
    ArrayIterator(T* ptr) : current(ptr) {}
    
    // Dereference operator
    T& operator*() const {
        return *current;
    }
    
    // Arrow operator
    T* operator->() const {
        return current;
    }
    
    // Increment operator
    ArrayIterator& operator++() {
        ++current;
        return *this;
    }
    
    // Comparison operators
    bool operator==(const ArrayIterator& other) const {
        return current == other.current;
    }
    
    bool operator!=(const ArrayIterator& other) const {
        return current != other.current;
    }
};

// Usage with container
template<typename T>
class Array {
private:
    T* data;
    unsigned int size;
    
public:
    Array(unsigned int n) : size(n) {
        data = new T[n];
    }
    
    ~Array() {
        delete[] data;
    }
    
    // Iterator access
    ArrayIterator<T> begin() {
        return ArrayIterator<T>(data);
    }
    
    ArrayIterator<T> end() {
        return ArrayIterator<T>(data + size);
    }
    
    // Element access
    T& operator[](unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};
```

### **Template Container with Bounds Checking**

```cpp
template<typename T>
class SafeArray {
private:
    T* elements;
    unsigned int array_size;
    
    void checkBounds(unsigned int index) const {
        if (index >= array_size) {
            throw std::out_of_range("Array index out of bounds");
        }
    }
    
public:
    SafeArray(unsigned int size) : array_size(size) {
        elements = new T[size];
    }
    
    ~SafeArray() {
        delete[] elements;
    }
    
    // Copy constructor
    SafeArray(const SafeArray& other) : array_size(other.array_size) {
        elements = new T[array_size];
        for (unsigned int i = 0; i < array_size; i++) {
            elements[i] = other.elements[i];
        }
    }
    
    // Assignment operator
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] elements;
            array_size = other.array_size;
            elements = new T[array_size];
            for (unsigned int i = 0; i < array_size; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    
    // Element access with bounds checking
    T& operator[](unsigned int index) {
        checkBounds(index);
        return elements[index];
    }
    
    const T& operator[](unsigned int index) const {
        checkBounds(index);
        return elements[index];
    }
    
    // Utility methods
    unsigned int size() const { return array_size; }
};
```

## Implementation Patterns

### **Easy Find Function Template**

```cpp
// Function template to find element in array
template<typename T>
int easyfind(T* array, int length, T const& value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Usage examples
int int_array[] = {1, 2, 3, 4, 5};
int index = easyfind(int_array, 5, 3);  // Returns 2
int not_found = easyfind(int_array, 5, 6);  // Returns -1

std::string str_array[] = {"apple", "banana", "cherry"};
int str_index = easyfind(str_array, 3, std::string("banana"));  // Returns 1
```

### **Iterator Class Template**

```cpp
template<typename T>
class ArrayIterator {
private:
    T* ptr;
    
public:
    ArrayIterator() : ptr(NULL) {}
    ArrayIterator(T* p) : ptr(p) {}
    
    // Required iterator operations
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    
    ArrayIterator& operator++() {
        ++ptr;
        return *this;
    }
    
    ArrayIterator operator++(int) {
        ArrayIterator temp = *this;
        ++ptr;
        return temp;
    }
    
    bool operator==(const ArrayIterator& other) const {
        return ptr == other.ptr;
    }
    
    bool operator!=(const ArrayIterator& other) const {
        return ptr != other.ptr;
    }
};
```

### **Array Container Template**

```cpp
template<typename T>
class Array {
private:
    T* data;
    unsigned int _size;
    
public:
    // Constructor
    Array() : data(NULL), _size(0) {}
    
    // Copy constructor
    Array(const Array& other) : _size(other._size) {
        data = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Destructor
    ~Array() {
        delete[] data;
    }
    
    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            _size = other._size;
            data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // Element access
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return data[index];
    }
    
    // Const element access
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return data[index];
    }
    
    // Size information
    unsigned int size() const { return _size; }
    
    // Iterator support
    ArrayIterator<T> begin() { return ArrayIterator<T>(data); }
    ArrayIterator<T> end() { return ArrayIterator<T>(data + _size); }
};
```

## Common Pitfalls & Solutions

### **Pitfall 1: Template Definition in Separate Files**
```cpp
// ❌ Problem: Template defined in .cpp file
// template.hpp
template<typename T>
void myTemplateFunction(T value);

// template.cpp
template<typename T>
void myTemplateFunction(T value) {
    // implementation
}

// ❌ Won't link - template not instantiated

// ✅ Solution: Templates in header files
// template.hpp
template<typename T>
void myTemplateFunction(T value) {
    // implementation
}
// Include .hpp wherever needed
```

### **Pitfall 2: Ambiguous Function Calls**
```cpp
// ❌ Problem: Template and non-template functions
void print(int value) {
    std::cout << "Non-template: " << value << std::endl;
}

template<typename T>
void print(T value) {
    std::cout << "Template: " << value << std::endl;
}

print(42);  // ❌ Ambiguous - which print()?

// ✅ Solution: Use explicit qualification or specialization
print<>(42);  // Explicitly choose template version
print<int>(42);  // Specify template type
```

### **Pitfall 3: Template Instantiation Issues**
```cpp
// ❌ Problem: Template cannot be instantiated for certain types
template<typename T>
class Container {
    T data;
public:
    void process() {
        data.someMethod();  // ❌ T may not have someMethod()
    }
};

// ✅ Solution: Use type constraints or concepts (C++20)
template<typename T>
class Container {
    T data;
public:
    void process() {
        // Check if type has required method
        if constexpr (hasSomeMethod<T>) {
            data.someMethod();
        }
    }
};
```

### **Pitfall 4: Template Compilation Bloat**
```cpp
// ❌ Problem: Template instantiated for many types
template<typename T>
void bigFunction() {
    // Large function - instantiated for every type
}

// ✅ Solution: Use common base functionality
template<typename T>
void smallFunction() {
    commonPart();  // Not templated
    templatedPart<T>();  // Only this part is templated
}
```

## Building & Testing

### **Build Commands**
```bash
# Build the template exercises
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = templates

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
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
# Test function template
$> ./templates
Testing max function:
max(10, 20) = 20
max(3.14, 2.71) = 3.14
max(hello, world) = world

# Test template class
$> ./templates
Testing Pair class:
Pair<int>: (10, 20)
Pair<string>: (hello, world)

# Test iterator
$> ./templates
Iterator test:
1 2 3 4 5
```

## Best Practices

### **Template Design**
- Keep templates simple and focused
- Use meaningful template parameter names
- Document template requirements and constraints
- Consider compilation time implications

### **Type Deduction**
- Let compiler deduce types when possible
- Use explicit specification when necessary
- Understand implicit conversion rules
- Test with various types

### **Error Handling**
- Provide clear error messages for template failures
- Use static_assert for compile-time checks
- Handle type-specific edge cases
- Document template limitations

## Further Learning Resources

### **Official Documentation**
- [Templates - cppreference](https://en.cppreference.com/w/cpp/language/templates)
- [Class Templates - cppreference](https://en.cppreference.com/w/cpp/language/class_template)
- [Function Templates - cppreference](https://en.cppreference.com/w/cpp/language/function_template)

### **Educational Resources**
- [Templates Explained - GeeksforGeeks](https://www.geeksforgeeks.org/templates-cpp/)
- [Template Specialization - GeeksforGeeks](https://www.geeksforgeeks.org/template-specialization-in-c/)
- [Template Metaprogramming - GeeksforGeeks](https://www.geeksforgeeks.org/template-metaprogramming/)
- [Iterator Implementation - GeeksforGeeks](https://www.geeksforgeeks.org/iterators-cpp-stl/)

### **Practice Suggestions**
- Create your own template containers
- Implement algorithms with templates
- Practice template specialization
- Study template metaprogramming techniques
- Experiment with type traits

## Connection to Next Module

This module provides the **foundation for STL containers** in CPP_08. The concepts you'll need:

- **Template class design** for container implementation
- **Iterator patterns** for STL compatibility
- **Generic algorithms** for container operations
- **Type safety** in template programming

**Next: [CPP_08 - STL Containers](../cpp_08/README.md)**

---

## Summary

CPP_07 introduces template programming concepts through practical generic programming exercises. You'll master:
- Function template design and type deduction
- Class template implementation and usage
- Template specialization for specific types
- Iterator interface implementation
- Generic container design patterns
- Template instantiation and compilation concepts

These template programming skills are crucial for understanding STL containers, algorithms, and advanced generic programming techniques in subsequent modules.