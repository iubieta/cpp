# CPP_08 - STL Containers

> **Subject:** [CPP_08 PDF](CPP_08.pdf)

## Module Overview

This module introduces STL (Standard Template Library) containers and iterators, focusing on using existing STL containers and implementing custom containers that follow STL conventions. You'll learn how to use and create efficient data structures.

## Key Learning Objectives

### **STL Fundamentals**
- Understanding STL container categories
- Iterator patterns and concepts
- Container selection criteria
- Algorithm integration with containers

### **Container Implementation**
- Custom container design following STL conventions
- Iterator implementation for custom containers
- Exception safety in container operations
- Memory management optimization

## Exercises Summary

### **Exercise 00 - Easy Find**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement find operation using STL algorithms

**Learning Focus:**
- STL algorithm usage
- Iterator concepts
- Container-iterator integration
- Generic programming patterns

### **Exercise 01 - Span**
**Files:** `Makefile`, `Span.hpp`, `Span.cpp`, `main.cpp`
**Goal:** Implement a custom array container with STL conventions

**Learning Focus:**
- STL-style container design
- Iterator implementation
- Exception handling in containers
- Range-based for loop compatibility

### **Exercise 02 - Mutated Abomination**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement complex container operations

**Learning Focus:**
- Advanced container operations
- Algorithm integration
- Performance considerations
- Memory optimization techniques

## Core Concepts Explained

### **STL Container Categories**

```cpp
// Sequence containers - maintain insertion order
std::vector<T>        // Dynamic array
std::deque<T>         // Double-ended queue
std::list<T>          // Doubly-linked list
std::forward_list<T>   // Singly-linked list
std::array<T, N>      // Fixed-size array

// Associative containers - sorted by key
std::set<T>           // Unique sorted elements
std::multiset<T>      // Duplicate allowed
std::map<K, V>        // Unique key-value pairs
std::multimap<K, V>    // Duplicate keys allowed

// Unordered containers - hash-based
std::unordered_set<T>
std::unordered_map<K, V>
```

### **Iterator Fundamentals**

```cpp
// Iterator categories
std::input_iterator<T>      // Read-only, forward
std::output_iterator<T>     // Write-only, forward
std::forward_iterator<T>    // Read/write, forward
std::bidirectional_iterator<T> // Read/write, both directions
std::random_access_iterator<T> // Read/write, random access

// Iterator operations
*iter          // Dereference
iter->member    // Arrow operator
++iter          // Pre-increment
iter++          // Post-increment
--iter          // Pre-decrement
iter--          // Post-decrement
iter1 == iter2  // Equality
iter1 != iter2  // Inequality
```

### **Custom Container Design (Span)**

```cpp
template<typename T>
class Span {
private:
    T* elements;
    unsigned int current_size;
    unsigned int max_capacity;
    
public:
    // Constructors
    Span() : elements(NULL), current_size(0), max_capacity(0) {}
    
    Span(unsigned int n) : max_capacity(n), current_size(0) {
        elements = new T[n];
    }
    
    // Copy constructor
    Span(const Span& other) : max_capacity(other.max_capacity), current_size(other.current_size) {
        elements = new T[max_capacity];
        for (unsigned int i = 0; i < other.current_size; i++) {
            elements[i] = other.elements[i];
        }
    }
    
    // Destructor
    ~Span() {
        delete[] elements;
    }
    
    // Assignment operator
    Span& operator=(const Span& other) {
        if (this != &other) {
            delete[] elements;
            max_capacity = other.max_capacity;
            current_size = other.current_size;
            elements = new T[max_capacity];
            for (unsigned int i = 0; i < other.current_size; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    
    // Element access
    T& operator[](unsigned int index) {
        if (index >= current_size) {
            throw std::out_of_range("Span index out of bounds");
        }
        return elements[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= current_size) {
            throw std::out_of_range("Span index out of bounds");
        }
        return elements[index];
    }
    
    // Modifiers
    void addElement(const T& element) {
        if (current_size >= max_capacity) {
            throw std::length_error("Span is full");
        }
        elements[current_size++] = element;
    }
    
    // Capacity
    unsigned int size() const { return current_size; }
    unsigned int capacity() const { return max_capacity; }
    
    // Iterators (STL-style)
    T* begin() { return elements; }
    T* end() { return elements + current_size; }
    const T* begin() const { return elements; }
    const T* end() const { return elements + current_size; }
};
```

### **STL Algorithms Integration**

```cpp
// Using STL algorithms with custom containers
void demonstrateAlgorithms() {
    std::vector<int> vec = {5, 2, 8, 1, 9, 3};
    
    // Sorting
    std::sort(vec.begin(), vec.end());
    
    // Finding
    auto it = std::find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "Found 8 at position " << std::distance(vec.begin(), it) << std::endl;
    }
    
    // Counting
    int count = std::count(vec.begin(), vec.end(), 5);
    std::cout << "Count of 5: " << count << std::endl;
    
    // Min/Max
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());
    
    // Accumulate
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    
    // For_each
    std::for_each(vec.begin(), vec.end(), [](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;
}
```

### **Range-Based For Loops**

```cpp
// Modern range-based for loop (C++11, but good to understand)
void modernLoop() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Range-based for loop
    for (int value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// C++98 equivalent using iterators
void legacyLoop() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Iterator-based for loop
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```

## Implementation Patterns

### **STL-Compatible Iterator**

```cpp
template<typename T>
class SpanIterator {
private:
    T* current;
    
public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::ptrdiff_t difference_type;
    
    SpanIterator(T* ptr) : current(ptr) {}
    
    // Required iterator operations
    reference operator*() const { return *current; }
    pointer operator->() const { return current; }
    
    SpanIterator& operator++() {
        ++current;
        return *this;
    }
    
    SpanIterator operator++(int) {
        SpanIterator temp = *this;
        ++current;
        return temp;
    }
    
    SpanIterator& operator--() {
        --current;
        return *this;
    }
    
    SpanIterator operator--(int) {
        SpanIterator temp = *this;
        --current;
        return temp;
    }
    
    // Random access
    SpanIterator operator+(difference_type n) {
        return SpanIterator(current + n);
    }
    
    difference_type operator-(const SpanIterator& other) const {
        return current - other.current;
    }
    
    reference operator[](difference_type n) const {
        return current[n];
    }
    
    bool operator==(const SpanIterator& other) const {
        return current == other.current;
    }
    
    bool operator!=(const SpanIterator& other) const {
        return current != other.current;
    }
};
```

### **Exception-Safe Container Operations**

```cpp
template<typename T>
class SafeVector {
private:
    std::vector<T> data;
    
public:
    // Exception-safe element access
    T& at(size_t index) {
        try {
            return data.at(index);  // std::vector::at() throws on bounds error
        } catch (const std::out_of_range& e) {
            throw std::out_of_range("SafeVector: " + std::string(e.what()));
        }
    }
    
    // Exception-safe addition
    void push_back(const T& value) {
        try {
            data.push_back(value);
        } catch (const std::bad_alloc& e) {
            throw std::runtime_error("SafeVector: Memory allocation failed");
        }
    }
    
    // Iterator access with bounds checking
    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("SafeVector index out of bounds");
        }
        return data[index];
    }
    
    // Size information
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    
    // Iterator access
    typename std::vector<T>::iterator begin() { return data.begin(); }
    typename std::vector<T>::iterator end() { return data.end(); }
    typename std::vector<T>::const_iterator begin() const { return data.begin(); }
    typename std::vector<T>::const_iterator end() const { return data.end(); }
};
```

### **Performance-Optimized Operations**

```cpp
template<typename T>
class OptimizedContainer {
private:
    T* data;
    size_t current_size;
    size_t capacity;
    
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_data = new T[new_capacity];
            
            // Move existing data
            for (size_t i = 0; i < current_size; i++) {
                new_data[i] = data[i];
            }
            
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }
    
public:
    OptimizedContainer() : data(NULL), current_size(0), capacity(0) {}
    
    ~OptimizedContainer() {
        delete[] data;
    }
    
    void push_back(const T& value) {
        if (current_size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);  // Exponential growth
        }
        data[current_size++] = value;
    }
    
    // Efficient size management
    size_t size() const { return current_size; }
    size_t get_capacity() const { return capacity; }
    
    // Iterator support
    T* begin() { return data; }
    T* end() { return data + current_size; }
};
```

## Common Pitfalls & Solutions

### **Pitfall 1: Iterator Invalidation**
```cpp
// ❌ Problem: Iterator invalidation during modification
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (*it == 3) {
        vec.push_back(6);  // ❌ Invalidates all iterators!
    }
    std::cout << *it << " ";
}

// ✅ Solution: Use index or store elements to erase
std::vector<int> vec = {1, 2, 3, 4, 5};
for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] == 3) {
        vec.push_back(6);  // OK when using indices
    }
    std::cout << vec[i] << " ";
}
```

### **Pitfall 2: Wrong Container Selection**
```cpp
// ❌ Problem: Using inefficient container
std::list<int> lst;  // Bad for random access
for (int i = 0; i < 10000; i++) {
    lst.push_back(i);
}

// Random access is O(n) for list
int sum = 0;
for (auto it = lst.begin(); it != lst.end(); ++it) {
    sum += *it;  // Very slow!
}

// ✅ Solution: Choose appropriate container
std::vector<int> vec;  // Good for random access
for (int i = 0; i < 10000; i++) {
    vec.push_back(i);
}

// Random access is O(1) for vector
int sum = 0;
for (auto it = vec.begin(); it != vec.end(); ++it) {
    sum += *it;  // Fast!
}
```

### **Pitfall 3: Memory Leaks with Custom Containers**
```cpp
// ❌ Problem: Memory leak in destructor
class BadContainer {
    int* data;
public:
    BadContainer(size_t size) {
        data = new int[size];
    }
    // ❌ Missing destructor - memory leak!
};

// ✅ Solution: Proper resource management
class GoodContainer {
    int* data;
    size_t size;
    
public:
    GoodContainer(size_t s) : size(s) {
        data = new int[size];
    }
    
    ~GoodContainer() {
        delete[] data;  // ✅ Proper cleanup
    }
    
    // Even better: Follow Rule of Three
    GoodContainer(const GoodContainer& other);
    GoodContainer& operator=(const GoodContainer& other);
};
```

### **Pitfall 4: Exception Safety in Algorithms**
```cpp
// ❌ Problem: Exception unsafe operations
void unsafeOperation(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] *= 2;  // May throw, vec left in inconsistent state
    }
}

// ✅ Solution: Exception-safe operations
void safeOperation(std::vector<int>& vec) {
    std::vector<int> temp = vec;  // Make copy
    
    for (size_t i = 0; i < temp.size(); i++) {
        temp[i] *= 2;
    }
    
    vec = temp;  // All or nothing assignment
}
```

## Building & Testing

### **Build Commands**
```bash
# Build the STL container project
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = stl_containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Span.cpp
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
# Test custom Span container
$> ./stl_containers
Span created with capacity 5
Adding elements: 1 2 3 4 5
Span contents: 1 2 3 4 5

# Test STL algorithms
$> ./stl_containers
Original vector: 5 2 8 1 9 3
After sorting: 1 2 3 5 8 9
Max element: 9
Min element: 1
Sum: 28

# Test iterator operations
$> ./stl_containers
Range-based for: 1 2 3 4 5
Iterator-based for: 1 2 3 4 5
```

## Best Practices

### **Container Selection**
- **Vector**: Default choice, good for most cases
- **List**: Use when frequent insertions/deletions in middle
- **Deque**: Use when need frequent insertions at both ends
- **Set/Map**: Use when need ordered/unique elements
- **Unordered**: Use when need fast lookup, order doesn't matter

### **Iterator Usage**
- Use range-based for loops when possible (C++11+)
- Be aware of iterator invalidation
- Store positions if you need to modify while iterating
- Use const_iterators for read-only access

### **Algorithm Integration**
- Prefer STL algorithms over manual loops
- Understand algorithm complexity
- Use appropriate algorithms for your needs
- Consider lambda expressions (C++11) when available

## Further Learning Resources

### **Official Documentation**
- [STL Containers - cppreference](https://en.cppreference.com/w/cpp/container)
- [Iterators - cppreference](https://en.cppreference.com/w/cpp/iterator)
- [Algorithms - cppreference](https://en.cppreference.com/w/cpp/algorithm)

### **Educational Resources**
- [STL Overview - GeeksforGeeks](https://www.geeksforgeeks.org/stl-tutorial-in-c/)
- [Containers in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/containers-in-cpp-stl/)
- [Iterators in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/iterators-cpp-stl/)
- [Algorithm Selection - GeeksforGeeks](https://www.geeksforgeeks.org/algorithms-in-c-stl/)

### **Practice Suggestions**
- Implement your own containers
- Experiment with different STL containers
- Practice algorithm combinations
- Study performance characteristics
- Learn about allocator concepts

## Connection to Next Module

This module provides the **foundation for STL algorithms** in CPP_09. The concepts you'll need:

- **Container understanding** for algorithm application
- **Iterator concepts** for algorithm interfaces
- **Complexity analysis** for algorithm selection
- **Generic programming** for algorithm design

**Next: [CPP_09 - STL Algorithms](../cpp_09/README.md)**

---

## Summary

CPP_08 introduces STL containers and custom container design through practical exercises. You'll master:
- STL container categories and selection criteria
- Iterator implementation and concepts
- Custom container design following STL conventions
- Exception safety in container operations
- Algorithm integration with containers
- Performance optimization techniques

These container and iterator skills are crucial for understanding STL algorithms, data structures, and efficient programming patterns in the final module.