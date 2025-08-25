# CPP 

## Index

* [Rules](#rules)

  * [Compilation](#compilation)
  * [Format](#format)
  * [Allowed and Forbidden Functions](#allowed-and-forbidden-functions)
  * [Requirements](#requirements)
* [📘 CPP00 – Basics of C++ and OOP](#-cpp00--basics-of-c-and-oop)

  * [Namespaces](#1-namespaces)
  * [std::string (instead of char\*)](#2-stdstring-instead-of-char)
  * [Streams (I/O in C++)](#3-streams-io-in-c)
  * [Classes and Objects](#4-classes-and-objects)
  * [Encapsulation](#5-encapsulation)
  * [Member Functions](#6-member-functions)
* [📘 CPP01 – Memory, Pointers, and References](#-cpp01--memory-pointers-and-references)

  * [Constructors and Destructors](#1-constructors-and-destructors)
  * [Stack vs Heap](#2-stack-vs-heap)
  * [References vs Pointers](#3-references-vs-pointers)
  * [File Streams](#4-file-streams)
  * [Function Pointers (member functions)](#5-function-pointers-member-functions)
* [📘 CPP02 – Ad-hoc polymorphism, operator overloading, and Orthodox Canonical Form](#-cpp02--ad-hoc-polymorphism-operator-overloading-and-orthodox-canonical-form)

  * [Orthodox Canonical Form](#1-orthodox-canonical-form)
  * [Fixed-point Numbers](#2-fixed-point-numbers)
  * [Constructors with Conversions](#3-constructors-with-conversions)
  * [Operator Overloading](#4-operator-overloading)
  * [Static Member Functions](#5-static-member-functions)

---

## Rules

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


## 2. **`std::string` (instead of `char*`)**
* Safer and easier than C-style strings.
* Common operations:

  * `s.size()` → length.
  * `s.find("abc")` → position or `npos` if not found.
  * `s.substr(pos, len)` → substring.
  * `+` → concatenation.

**Why useful:** Avoids buffer overflows, simplifies text manipulation.


## 3. **Input/Output Streams in C++**

In cpp there are narrow (1 byte) and wide (2 or 4 bytes) streams
and you shouldn't mix them

### Narrow streams

* **Input**: `std::cin`
* **Output**: `std::cout`
* **Strings**: `std::string` (`char`-based)
* **Literals**: `"hello"`

✅ Works everywhere, safe for ASCII.
❌ May break with accented characters (`ñ`, `á`) in Windows consoles.

### Wide streams

* **Input**: `std::wcin`
* **Output**: `std::wcout`
* **Strings**: `std::wstring` (`wchar_t`-based)
* **Literals**: `L"hello"`

✅ Can handle Unicode (like `ñ`, accents) if locale is configured.
❌ On Windows, you need `_O_U16TEXT`; column alignment with `setw` may break.

### Locale setup

Before using wide streams, set locale:

Locale is a set of rules that tells your program how to handle culture-specific things such as:
- Character encoding (UTF-8, UTF-16, system code page, etc.)
- Alphabet and collation order (how strings are sorted: ä after a, etc.)
- Number formatting (decimal separator: 1,23 vs. 1.23)
- Date/time formatting (24/08/2025 vs. 08/24/2025)
- Currency symbols (€ vs. $)

```cpp
#include <locale>
#include <clocale>

int main() {
    std::setlocale(LC_ALL, "");           // C locale
    std::locale::global(std::locale("")); // C++ locale
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
}
```

### Reading with `>>` vs. `getline`

### `>>`

* Reads until first whitespace.
* Works directly for numbers:

  ```cpp
  int n;
  if (!(std::cin >> n)) { /* error */ }
  ```
* On failure:

  ```cpp
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  ```

### `getline`

* Reads an entire line (keeps spaces).
* Usage:

  ```cpp
  std::getline(std::cin, str);     // narrow
  std::getline(std::wcin, wstr);   // wide
  ```
#### Processing lines with **stringstream**
String stream works as a personalt I/O stream as `cin` or `cout`
You have three main variants of string streams, all declared in <sstream>:
- std::stringstream → both input and output (can read & write).
- std::istringstream → input only (read from a string, like cin).
- std::ostringstream → output only (write into a string, like cout).

  ```cpp
  //Checkin if wstr is a number
  std::wistringstream iss(wstr);
  int n;
  if (!(iss >> n)) { /* not a number */ }
  ```


### Output formatting (`setw`)

* `std::setw(n)` sets **minimum width** for the next output:

  ```cpp
  std::cout << std::setw(10) << "hi";
  ```
* Works with `std::left` / `std::right`.
* Applies **only once**.

⚠️ Issue on Windows with `wcout`:

* `setw` counts characters, but the console counts some Unicode (like `ñ`, emojis) as two cells.
* Result: table columns misalign.

👉 Practical fix: implement a custom `padRight` function that measures string length and appends spaces.

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

# 📘 **CPP01 – Memory, Pointers, and References**

## 1. **Constructors and Destructors**
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


## 2. **Stack vs Heap**
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


## 3. **References vs Pointers**

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


## 4. **File Streams**

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


## 5. **Function Pointers (member functions)**

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

# 📘 **CPP02 – Ad-hoc polymorphism, operator overloading, and Orthodox Canonical Form**

## 1. **Orthodox Canonical Form**

* **What it is:** A standardized way of writing classes in C++98 with the 4 special functions :
  1. Default constructor
  2. Copy constructor
  3. Copy assignment operator
  4. Destructor

* **Why useful:**

  * Ensures safe copying, assignment, and cleanup.
  * Critical when managing resources (dynamic memory, file handles).
  * Sets the foundation for RAII (Resource Acquisition Is Initialization).

```cpp
class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    // 1. Default constructor
    Fixed() : value(0) {
    }

    // 2. Copy constructor
    Fixed(const Fixed& other) {
        *this = other; // reuse operator=
    }

    // 3. Copy assignment operator
    Fixed& operator=(const Fixed& other) {
        if (this != &other)  // check self-assignment
            this->value = other.value;
        return *this;
    }

    // 4. Destructor
    ~Fixed() {
    }
};
```

## 2. **Fixed-point Numbers**

* **What it is:** A number representation where a fixed number of bits are reserved for the fractional part. It is saved as an integer escaled up by n power of 2. Where n is the number of bits reserved for the fractional part.
  * `raw = round( int * 2^n )` 
* **Why useful:**
  * Floats are efficient but imprecise; integers are precise but lack fractions.
  * Using fixed n for the scaling up proccesing you can add, substract and compare raws directly.
  * Used in graphics, DSP (digital signal processing), and embedded systems because its more efficient.
⚠️**Warning:** Multiplication and division is not direct between raws.

```cpp
class Fixed {
private:
    int                 _raw;               // valor crudo escalado
    static const int    _fbits = 8;         // bits fraccionales (n)
public:
    Fixed() : _raw(0) {}
    // int -> Fixed
    Fixed(int i) : _raw(i << _fbits) {}
    // float -> Fixed
    Fixed(float f) : _raw(static_cast<int>(roundf(f * (1 << _fbits)))) {}
    // conversiones de vuelta
    float toFloat() const { return static_cast<float>(_raw) / (1 << _fbits); }
    int   toInt()   const { return _raw >> _fbits; }
    int   getRawBits() const { return _raw; }
    void  setRawBits(int r) { _raw = r; }
};
```

## 3. **Constructors with Conversions**

A good class definition have:
* **Multiple constructors** that take different types of input variables (int, float, ...) makes a class more solid and flexible.
* **Conversion methods** to convert this class objects to other types: `toInt()`, `toFloat()`.

* **Why useful:**
  * Enables smooth conversions between types.
  * Improves usability of your class, like a real scalar type.


## 4. **Operator Overloading**

* **What it is:** redefinition of operators for your class types
* **Why useful:**
  * Makes custom types behave like built-in ones.
  * Enables *ad-hoc polymorphism*: different behavior depending on types.
```cpp
//instead of
Fixed c = a.add(b);
//redifining operators
Fixed c = a + b;
```

* **Comparison operators:** `> < >= <= == !=`
* **Arithmetic operators:** `+ - * /`
* **Increment/Decrement:** pre and post (`++a`, `a++`, `--a`, `a--`)

```cpp
class Fixed {
public:
    // comparison
    bool operator>(const Fixed& rhs) const;
    // arithmetic
    Fixed operator+(const Fixed& rhs) const;
    // pre-increment
    Fixed& operator++();    
    // post-increment
    Fixed operator++(int);  
};
```

## 5. **Static Member Functions**

* **What it is:** 
  	* Utility functions tied to the class but don’t need an instance.
	* Typically take objects of the class as parameters.
* **Why useful:** Improves expressiveness (like `std::min`, `std::max`).

```cpp
class Math {
public:
    static int add(int x, int y) {
        return x + y;
    }
};
// Usage
int result = Math::add(2, 3);  // 5
```

⚠️ Is good practice to be overloaded for const and non-const references.

---
