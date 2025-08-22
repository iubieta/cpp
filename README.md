# CPP 

### Compilation

* Compiler: **c++**
* Flags: `-Wall -Wextra -Werror` (`-std=c++98`)

### Format

* Class names in **UpperCamelCase**
* Files containing classes: `ClassName.extension`
* Output messages must always end with a newline
* **No Norminette!**

### Allowed and Forbidden Functions

* Any function from the **standard library** is allowed
* Any other function or library is forbidden
* The following are also forbidden:

  * `printf()`
  * `alloc()`
  * `free()`
* Forbidden: `using namespace <>` and `friend`
* Forbidden: **Containers** (`vector/list/map/...`) and **Algorithms** (anything that requires including `<algorithm>`) except in modules 08 and 09

### Requirements

* Avoid memory leaks
* Classes must follow the **Orthodox Canonical Form** unless stated otherwise
* No function definitions inside header files
* Header files must be independent and self-contained
* Double inclusion must be avoided using **include guards**

---

# 📘 **CPP00 – Basics of C++ and OOP**

## 1. **Namespaces**
* **What:** A way to group identifiers (variables, functions, classes) to avoid name collisions.
* **Why useful:** Prevents clashes when multiple libraries or files define the same names.

```cpp
namespace Foo {
    int x = 42;
}

int main() {
    std::cout << Foo::x << std::endl;  // Access with scope resolution
}
```

⚠️ `using namespace std;` is convenient, but in professional code it’s discouraged → it pollutes the global namespace.

---

## 2. **`std::string` (instead of `char*`)**
* Safer and easier than C-style strings.
* Common operations:

  * `s.size()` → length.
  * `s.find("abc")` → position or `npos` if not found.
  * `s.substr(pos, len)` → substring.
  * `+` → concatenation.

**Why useful:** Avoids buffer overflows, simplifies text manipulation.

---

## 3. **Streams (I/O in C++)**
* Replaces `printf` / `scanf`.
* `std::cout` → output.
* `std::cin` → input.
* `std::getline(std::cin, str)` → read full line (including spaces).
**Why useful:** Type-safe, extensible (can work with custom objects), and integrates with C++ classes.

---

## 4. **Classes and Objects**
* **Class = blueprint**, **Object = instance** of that blueprint.
* **Why useful:** Encapsulation, reusability, and modeling real-world entities.

```cpp
class Zombie {
private:
    std::string name;   // attribute

public:
    Zombie(std::string n) : name(n) {}   // constructor
    void announce() { std::cout << name << " BraiiiiiiinnnzzzZ...\n"; }
};
```

---

## 5. **Encapsulation**
* **What:** Keeping data (`private`) safe and only exposing what’s necessary (`public`).
* **Why useful:** Prevents external code from corrupting internal state.

```cpp
class Foo {
private:
    int value;  // hidden from outside

public:
    void setValue(int v) { value = v; }
    int getValue() const { return value; }
};
```
---

## 6. **Member Functions**
* Functions that belong to a class.
* Defined inside the class (inline) or outside using `::`.
* **Why useful:** Keeps behavior tightly coupled to data.
```cpp
class Foo {
public:
    void sayHello();
};

void Foo::sayHello() {
    std::cout << "Hello\n";
}
```
---

## **Good Practices in CPP00**
* Always split code into `.hpp/.h` (headers) and `.cpp` (implementations).
* Avoid global variables.
* Don’t abuse `using namespace`.

---

# 📘 **CPP01 – Memory, Pointers, and References**

## 7. **Constructors and Destructors**
* **Constructor:** Special method that initializes an object. Runs automatically at creation.
* **Destructor:** Cleans up resources when the object goes out of scope or is deleted.
* **Why useful:**

  * Ensures objects are always initialized.
  * Helps manage resources (files, memory, sockets) automatically.

```cpp
class Test {
public:
    Test() { std::cout << "Constructor\n"; }
    ~Test() { std::cout << "Destructor\n"; }
};
```

---

## 8. **Stack vs Heap**
* **Stack (automatic storage):**

  * Objects are created/destroyed automatically.
  * Faster, safer.

```cpp
Zombie z("Bob");  // stack
```

* **Heap (dynamic storage):**

  * Objects allocated with `new`, destroyed with `delete`.
  * Required for objects with unknown lifetime or size at compile time.

```cpp
Zombie* z = new Zombie("Jim");
delete z;  // must delete manually
```

**Why useful:** Understanding memory models is essential for avoiding leaks and crashes.

---
## 9. **References vs Pointers**

* **Pointer (`T* p`):** can be `nullptr`, can change what it points to.
* **Reference (`T& r`):** alias for an object, cannot be null, must be initialized.

```cpp
int a = 10;
int* p = &a;   // pointer
int& r = a;    // reference
```

**Why useful:**

* Use references when you want safe access to an existing object.
* Use pointers when ownership or nullability matters.

---

## 10. **File Streams**

* Reading: `std::ifstream`.
* Writing: `std::ofstream`.
* Methods:

  * `getline(file, str)` → read line.
  * `file << data` → write data.

```cpp
std::ifstream in("input.txt");
std::ofstream out("output.txt");
```

**Why useful:** Encapsulates file handling with automatic closing (when object goes out of scope).

---

## 11. **Function Pointers (member functions)**

* Pointers that store the address of a function.
* Member function pointers need the class scope.

```cpp
class Harl {
    void debug();
    typedef void (Harl::*func)();
    std::map<std::string, func> actions;
};
```

**Why useful:** They allow flexible mapping of strings → actions (like implementing a custom switch/case for functions).

---
