# C++ Type Casting Guide

> **Subject:** [CPP 06 - Conversion entre tipos de datos](CPP_06.pdf)

## Project Overview

This project serves as a comprehensive exploration of **type casting in C++98** through three progressively complex exercises. Each exercise focuses on a different casting operator, helping you understand when and how to use each type safely and effectively.

## Original Subject Summary

### Learning Objectives
Through three exercises, you'll master:
- **Type parsing and conversion** (ex00 - ScalarConverter)
- **Pointer serialization** (ex01 - Serializer)  
- **Run-time type identification** (ex02 - Type Identification)

### Key Requirements
- **C++98 Standard:** All code must compile and run with C++98
- **42 School Format:** Proper headers and coding style
- **Robust Error Handling:** Graceful handling of invalid inputs
- **Memory Management:** Proper use of `new/delete` with no leaks

---

## Understanding Type Casting

Type casting is the process of converting a value from one data type to another. In C++, there are four casting operators, each with specific safety guarantees and use cases:

1. **`static_cast`** - Safe compile-time conversions
2. **`dynamic_cast`** - Safe run-time type checking
3. **`reinterpret_cast`** - Low-level bit reinterpretation
4. **`const_cast`** - Modifying const qualification

---

## static_cast - Safe Compile-Time Casting

### Core Concept
`static_cast` performs compile-time type checking to ensure conversions are valid. It's the most common and safest form of casting when the conversion is known to be valid.

### When It's Safe to Use
- Converting between numeric types (int ↔ double)
- Upcasting in inheritance (derived → base)
- Converting between compatible types
- User-defined conversion operators

### Practical Example: Unit Conversion
Imagine you're working with a scientific application:
```cpp
double celsius = 25.0;
double fahrenheit = static_cast<double>(celsius) * 9.0/5.0 + 32.0;
int rounded_temp = static_cast<int>(fahrenheit);  // 77
```
This demonstrates safe conversion from double to int, accepting precision loss.

### What It Cannot Do
```cpp
// Dangerous - compiler prevents this
class Animal {};
class Dog : public Animal {};

Animal* animal = new Animal();
Dog* dog = static_cast<Dog*>(animal);  // ❌ Undefined behavior!
```

### Exercise 00 Relevance
In **ScalarConverter**, static_cast converts parsed strings to different display types:
```cpp
// After parsing "42.0" into a double
double parsed = 42.0;
int display_int = static_cast<int>(parsed);      // 42
char display_char = static_cast<char>(parsed);    // '*'
float display_float = static_cast<float>(parsed); // 42.00f
```

---

## dynamic_cast - Safe Run-Time Type Identification

### Core Concept
`dynamic_cast` performs type checking at runtime, enabling safe downcasting in polymorphic hierarchies. It requires **Run-Time Type Information (RTTI)** through a virtual function (usually a destructor).

### Pointer vs Reference Casting
```cpp
// Pointer version - returns nullptr if cast fails
Derived* derived = dynamic_cast<Derived*>(base_ptr);
if (derived) {
    // Successfully converted to Derived
}

// Reference version - throws exception if cast fails
try {
    Derived& derived = dynamic_cast<Derived&>(base_ref);
    // Successfully converted to Derived
} catch (std::bad_cast&) {
    // Cast failed
}
```

### Practical Example: Component System
Imagine a game engine with different component types:
```cpp
class Component { public: virtual ~Component() = default; };
class RenderComponent : public Component {};
class PhysicsComponent : public Component {};

void processComponent(Component* component) {
    if (auto* renderer = dynamic_cast<RenderComponent*>(component)) {
        render(renderer);  // Handle rendering
    }
    if (auto* physics = dynamic_cast<PhysicsComponent*>(component)) {
        updatePhysics(physics);  // Handle physics
    }
}
```

### Exercise 02 Relevance
The **Type Identification** exercise demonstrates dynamic_cast for determining actual object type:
```cpp
void identify(Base* obj) {
    if (dynamic_cast<A*>(obj)) {
        std::cout << "Type is A" << std::endl;
    } else if (dynamic_cast<B*>(obj)) {
        std::cout << "Type is B" << std::endl;
    }
}
```

---

## reinterpret_cast - Low-Level Bit Reinterpretation

### Core Concept
`reinterpret_cast` tells the compiler to treat the same sequence of bits as if it were a different type. It's powerful but dangerous because no type checking occurs.

### When It's Actually Useful
- Converting between pointer types (void* ↔ T*)
- Serializing data structures
- Network protocol implementation
- Hardware interfacing

### Practical Example: Network Protocol
Imagine sending data over a network:
```cpp
// Send integer data as bytes
int value = 12345;
unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
// Now you can send 'bytes' over the network

// On receiving end
int received_value = *reinterpret_cast<int*>(received_bytes);
```

### Important Dangers
```cpp
// Dangerous - memory layout might be different
float f = 3.14f;
int* i = reinterpret_cast<int*>(&f);
std::cout << *i;  // ❌ Undefined behavior!
```

### Exercise 01 Relevance
The **Serializer** exercise shows how reinterpret_cast converts between pointers and integers:
```cpp
// Convert object pointer to integer for transmission
uintptr_t serialized = reinterpret_cast<uintptr_t>(data_pointer);

// Convert back to pointer on the other side
Data* restored = reinterpret_cast<Data*>(serialized);
```

---

## const_cast - Modifying Const Qualification

### Core Concept
`const_cast` can add or remove `const` from types. Use it carefully - modifying something that's actually const causes undefined behavior.

### Safe Use Cases
```cpp
// When working with legacy APIs that aren't const-correct
void oldAPI(char* data) { /* modifies data */ }

void modernFunction(const std::string& data) {
    oldAPI(const_cast<char*>(data.c_str()));  // Safe if oldAPI doesn't modify
}
```

### When to Avoid
```cpp
// Dangerous - modifying actual constant
const int value = 42;
int* mutable_value = const_cast<int*>(&value);
*mutable_value = 100;  // ❌ Undefined behavior!
```

---

## Choosing the Right Cast

### Decision Tree
1. **Need to remove/add const?** → Use `const_cast`
2. **Converting numbers/compatible types?** → Use `static_cast`  
3. **Downcasting in inheritance?** → Use `dynamic_cast`
4. **Serializing/low-level operations?** → Use `reinterpret_cast`

### Safety Hierarchy
1. **No cast needed** (safest)
2. **static_cast** (compile-time checked)
3. **dynamic_cast** (run-time checked)
4. **const_cast** (const correctness)
5. **reinterpret_cast** (no type checking)

### Performance Considerations
- **static_cast**: Zero runtime overhead
- **dynamic_cast**: Runtime type checking overhead
- **reinterpret_cast**: Zero runtime overhead, high risk
- **const_cast**: Zero runtime overhead

---

## Common Pitfalls to Avoid

### Undefined Behavior Scenarios
- **Casting away const and then modifying**: Modifying actually constant data
- **Downcasting unrelated types**: Using static_cast for inheritance casting
- **Assuming reinterpret_cast preserves meaning**: Treating float bits as int directly

### Best Practices
- Always prefer the safest cast that works
- Use `dynamic_cast` when unsure about exact type in inheritance
- Document why a cast is necessary in comments
- Consider redesigning if frequent complex casting is needed

---

## Exercise Implementation Patterns

### Exercise 00: ScalarConverter
```cpp
// Pattern: Parse string, then static_cast to display types
static void convert(const std::string& input) {
    // Parse input into a fundamental type (double works well)
    double parsed_value = parseInput(input);  // Your parsing logic
    
    // Convert to display types using static_cast
    char char_result = static_cast<char>(parsed_value);
    int int_result = static_cast<int>(parsed_value);
    float float_result = static_cast<float>(parsed_value);
    double double_result = parsed_value;
    
    // Display results with proper formatting
    displayResults(char_result, int_result, float_result, double_result);
}
```

### Exercise 01: Serializer
```cpp
// Pattern: Pointer ↔ Integer conversion
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
```

### Exercise 02: Type Identification
```cpp
// Pattern: RTTI with dynamic_cast
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A";
    else if (dynamic_cast<B*>(p)) std::cout << "B";
    else if (dynamic_cast<C*>(p)) std::cout << "C";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A";
        return;
    } catch (std::bad_cast&) {}
    // Try other types...
}
```

---

## Building and Testing

### Build Commands
```bash
# Build individual exercises
make -C ex00    # Build ScalarConverter
make -C ex01    # Build Serializer
make -C ex02    # Build Type Identifier

# Test commands
./ex00/convert test          # Run comprehensive conversion tests
./ex01/serializer           # Test pointer serialization
./ex02/identify             # Test type identification

# Cleanup
make -C ex00 fclean && make -C ex01 fclean && make -C ex02 fclean
```

### Testing Strategy
Each exercise includes built-in test programs that demonstrate:
- **Exercise 00:** Various literal types (chars, ints, floats, doubles, special values)
- **Exercise 01:** Round-trip pointer serialization verification
- **Exercise 02:** Random object generation and type identification

---

## Further Learning

### cppreference Resources
- [Type conversions](https://en.cppreference.com/w/cpp/language/type_conversion)
- [static_cast](https://en.cppreference.com/w/cpp/language/static_cast)
- [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
- [const_cast](https://en.cppreference.com/w/cpp/language/const_cast)

### Practice Suggestions
- Experiment with each cast type in isolation
- Study the difference between compile-time and run-time type checking
- Explore when casting indicates a design problem
- Practice safe memory management with casting

---

## Conclusion

Mastering C++ casting operators is essential for writing robust, efficient code. This project provides a solid foundation through practical exercises that demonstrate:

1. **Safe type conversions** with `static_cast`
2. **Low-level data manipulation** with `reinterpret_cast`
3. **Run-time type identification** with `dynamic_cast`
4. **Const correctness** with `const_cast`

Remember: the best cast is no cast. Always consider whether a cast is truly necessary or if there's a better design alternative.

---

**⚠️ Important Notes:**
- Always include proper error handling in production code
- Use memory management techniques appropriate for C++98
- Test all edge cases when implementing type conversions
- Consider undefined behavior implications when using dangerous casts