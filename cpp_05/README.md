# CPP_05 - Exceptions & Repetition

> **Subject:** [CPP_05 PDF](CPP_05.pdf)

## Module Overview

This module introduces exception handling in C++, focusing on creating custom exceptions, ensuring class invariants, and implementing robust error handling patterns. You'll learn how to write exception-safe code and maintain object consistency under error conditions.

## Key Learning Objectives

### **Exception Handling**
- Creating and throwing custom exceptions
- Try-catch blocks and exception propagation
- Exception safety in class design
- Class invariant protection through exceptions
- Resource management with exceptions

### **Advanced OOP Patterns**
- Bureaucratic hierarchy simulation
- Form management with exceptions
- Presidential pardon patterns
- Exception hierarchy design

## Exercises Summary

### **Exercise 00 - Bureaucrat**
**Files:** `Makefile`, `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`
**Goal:** Create a Bureaucrat class with grade management and exceptions

**Learning Focus:**
- Custom exception creation and throwing
- Grade boundary enforcement
- Exception handling in member functions
- Orthodox Canonical Form with exceptions

### **Exercise 01 - Form**
**Files:** `Makefile`, `Form.hpp`, `Form.cpp`, `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`
**Goal:** Implement a Form class with bureaucratic requirements

**Learning Focus:**
- Abstract base class design
- Exception hierarchy implementation
- Signed/unsigned state management
- Grade requirements for forms

### **Exercise 02 - Presidential Pardon**
**Files:** `Makefile`, `Bureaucrat.hpp`, `Bureaucrat.cpp`, `Form.hpp`, `Form.cpp`, `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp`, `main.cpp`
**Goal:** Create a special presidential pardon form

**Learning Focus:**
- Inheritance with exceptions
- Special form requirements
- Execution failure handling
- Exception chain management

### **Exercise 03 - Intern**
**Files:** `Makefile`, `Bureaucrat.hpp`, `Bureaucrat.cpp`, `Form.hpp`, `Form.cpp`, `Intern.hpp`, `Intern.cpp`, `ShrubberyCreationForm.hpp`, `ShrubberyCreationForm.cpp`, `RobotomyRequestForm.hpp`, `RobotomyRequestForm.cpp`, `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp`, `main.cpp`
**Goal:** Complete the bureaucracy simulation with interns and form management

**Learning Focus:**
- Exception-safe object construction
- Form creation and signing
- Intern management patterns
- Complete system integration

## Core Concepts Explained

### **Exception Fundamentals**

```cpp
// Custom exception class
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too high!";
    }
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too low!";
    }
};

// Throwing exceptions
void checkGrade(int grade) {
    if (grade > 150) {
        throw GradeTooHighException();
    }
    if (grade < 1) {
        throw GradeTooLowException();
    }
}

// Catching exceptions
void testGrade(int grade) {
    try {
        checkGrade(grade);
        std::cout << "Grade " << grade << " is valid" << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
```

### **Exception Safety in Classes**

```cpp
class Bureaucrat {
private:
    std::string name;
    int grade;
    
    // Helper function to validate grade
    void validateGrade(int new_grade) {
        if (new_grade > 150) {
            throw GradeTooHighException();
        }
        if (new_grade < 1) {
            throw GradeTooLowException();
        }
    }
    
public:
    Bureaucrat(std::string name, int grade) : name(name) {
        validateGrade(grade);  // May throw
        this->grade = grade;
        std::cout << name << " created with grade " << grade << std::endl;
    }
    
    // Exception-safe increment
    void incrementGrade() {
        validateGrade(grade + 1);  // May throw
        grade++;  // Only increment if validation passes
    }
    
    // Exception-safe decrement
    void decrementGrade() {
        validateGrade(grade - 1);  // May throw
        grade--;  // Only decrement if validation passes
    }
    
    // Getters
    std::string getName() const { return name; }
    int getGrade() const { return grade; }
};
```

### **Abstract Forms with Exceptions**

```cpp
class Form {
protected:
    std::string name;
    bool is_signed;
    int grade_to_sign;
    
public:
    Form(std::string name, int grade_to_sign) 
        : name(name), is_signed(false), grade_to_sign(grade_to_sign) {}
    
    virtual ~Form() {}
    
    // Pure virtual execute function
    virtual void execute(Bureaucrat const& executor) const = 0;
    
    // Signing with grade check
    void beSigned(Bureaucrat& bureaucrat) {
        if (bureaucrat.getGrade() <= grade_to_sign) {
            is_signed = true;
            std::cout << bureaucrat.getName() << " signed " << name << std::endl;
        } else {
            throw GradeTooLowException();
        }
    }
    
    // Accessors
    std::string getName() const { return name; }
    bool getSigned() const { return is_signed; }
    int getGradeToSign() const { return grade_to_sign; }
};
```

### **Exception Hierarchy**

```cpp
// Base exception for form-related errors
class FormException : public std::exception {
protected:
    std::string message;
    
public:
    FormException(const std::string& msg) : message(msg) {}
    virtual ~FormException() throw() {}
    virtual const char* what() const throw() { return message.c_str(); }
};

// Specific exceptions
class FormNotSignedException : public FormException {
public:
    FormNotSignedException() 
        : FormException("Form is not signed!") {}
};

class GradeTooLowToExecuteException : public FormException {
public:
    GradeTooLowToExecuteException() 
        : FormException("Grade too low to execute form!") {}
};

// Usage in form execution
class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm(std::string target) 
        : Form("Shrubbery Creation", 145) {}
    
    void execute(Bureaucrat const& executor) const {
        if (!getSigned()) {
            throw FormNotSignedException();
        }
        if (executor.getGrade() < 137) {
            throw GradeTooLowToExecuteException();
        }
        
        std::cout << "Creating shrubbery for target" << std::endl;
    }
};
```

### **Exception-Safe Resource Management**

```cpp
class Intern {
private:
    std::string name;
    
public:
    Intern(std::string name) : name(name) {
        std::cout << "Intern " << name << " created" << std::endl;
    }
    
    // Exception-safe form creation
    Form* makeForm(std::string form_name, int grade_required) {
        try {
            if (form_name == "shrubbery creation") {
                return new ShrubberyCreationForm("Default");
            } else if (form_name == "robotomy request") {
                return new RobotomyRequestForm("Default");
            } else if (form_name == "presidential pardon") {
                return new PresidentialPardonForm("Default");
            }
        } catch (const std::exception& e) {
            std::cerr << "Intern couldn't create form: " << e.what() << std::endl;
        }
        
        std::cout << "Intern doesn't know how to create " << form_name << std::endl;
        return NULL;
    }
    
    std::string getName() const { return name; }
};
```

## Implementation Patterns

### **Bureaucrat Class**

```cpp
// Bureaucrat.hpp
#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    std::string name;
    int grade;
    
    static const int highest_grade = 1;
    static const int lowest_grade = 150;
    
    void validateGrade(int new_grade);
    
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    
    Bureaucrat& operator=(const Bureaucrat& other);
    
    void incrementGrade();
    void decrementGrade();
    
    std::string getName() const;
    int getGrade() const;
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
```

### **Form Hierarchy**

```cpp
// Form.hpp - Abstract base class
#ifndef FORM_H
# define FORM_H

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form {
protected:
    std::string name;
    bool is_signed;
    int grade_to_sign;
    
public:
    Form(std::string name, int grade_to_sign);
    Form(const Form& other);
    virtual ~Form();
    
    Form& operator=(const Form& other);
    
    virtual void execute(Bureaucrat const& executor) const = 0;
    
    void beSigned(Bureaucrat& bureaucrat);
    
    // Accessors
    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
};

#endif

// PresidentialPardonForm.hpp - Concrete form
class PresidentialPardonForm : public Form {
private:
    std::string target;
    
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    
    void execute(Bureaucrat const& executor) const;
};
```

### **Exception Classes**

```cpp
// Custom exceptions for specific error conditions
class GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too high!";
    }
};

class GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too low!";
    }
};

class FormNotSignedException : public std::exception {
public:
    const char* what() const throw() {
        return "Form is not signed!";
    }
};
```

## Common Pitfalls & Solutions

### **Pitfall 1: Throwing by Value Instead of Reference**
```cpp
// ❌ Problem: Throwing by value
void badFunction() {
    GradeTooHighException exception;  // Local object
    throw exception;  // ❌ Object slicing, undefined behavior
}

// ✅ Solution: Throw by reference
void goodFunction() {
    throw GradeTooHighException();  // ✅ Correct
}
```

### **Pitfall 2: Not Catching by Reference**
```cpp
// ❌ Problem: Catching by value causes object copying
try {
    checkGrade(200);
} catch (GradeTooHighException e) {  // ❌ Copies exception
    std::cerr << e.what() << std::endl;
}

// ✅ Solution: Catch by reference
try {
    checkGrade(200);
} catch (const GradeTooHighException& e) {  // ✅ No copying
    std::cerr << e.what() << std::endl;
}
```

### **Pitfall 3: Exception Safety in Constructors**
```cpp
// ❌ Problem: Resource leak in constructor
class BadClass {
    char* buffer;
    
public:
    BadClass() {
        buffer = new char[1000];
        checkGrade(200);  // May throw - leak!
    }
};

// ✅ Solution: RAII and proper ordering
class GoodClass {
    std::string buffer;  // Automatic management
    
public:
    GoodClass() : buffer(1000, 'x') {
        checkGrade(200);  // May throw - but buffer cleans up
    }
};
```

### **Pitfall 4: Ignoring Exception Specifications**
```cpp
// ❌ Problem: Missing exception specification (C++98 style)
void badFunction() {  // Can throw anything
    throw GradeTooHighException();
}

// ✅ Solution: Use exception specifications when appropriate
void goodFunction() throw(GradeTooHighException) {  // Document what can be thrown
    throw GradeTooHighException();
}

// Modern approach (C++11+): noexcept and dynamic exception specifications
void modernFunction() noexcept;  // Won't throw
```

## Building & Testing

### **Build Commands**
```bash
# Build the bureaucracy simulation
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = bureaucracy

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp \
       ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
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
# Test grade management
$> ./bureaucracy
Bureaucrat John created with grade 75
John grade incremented to 76
John, bureaucrat grade 76

# Test form signing
$> ./bureaucracy
Form Shrubbery Creation created
John signed Shrubbery Creation
Form is now signed

# Test exceptions
$> ./bureaucracy
Error: Grade is too high!
Error: Form is not signed!
Error: Grade too low to execute form!
```

## Best Practices

### **Exception Design**
- Create specific exception types for different error conditions
- Inherit from std::exception for compatibility
- Provide meaningful error messages via what()
- Keep exceptions lightweight and focused

### **Exception Safety**
- Validate parameters before modifying object state
- Use RAII for automatic resource cleanup
- Implement strong exception safety guarantees
- Document exception throwing behavior

### **Class Invariant Protection**
- Use exceptions to enforce class rules
- Validate object state after every modification
- Provide clear error messages for violations
- Maintain object consistency

## Further Learning Resources

### **Official Documentation**
- [Exception Handling - cppreference](https://en.cppreference.com/w/cpp/language/exceptions)
- [std::exception - cppreference](https://en.cppreference.com/w/cpp/error/exception)
- [Exception Specifications - cppreference](https://en.cppreference.com/w/cpp/language/except_spec)

### **Educational Resources**
- [Exception Handling in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/exception-handling-cpp/)
- [Custom Exceptions - GeeksforGeeks](https://www.geeksforgeeks.org/user-defined-custom-exceptions-in-cpp/)
- [Exception Safety - GeeksforGeeks](https://www.geeksforgeeks.org/exception-handling-best-practices/)
- [RAII in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/raii-in-cpp/)

### **Practice Suggestions**
- Create your own exception hierarchies
- Practice exception-safe class design
- Experiment with different exception safety levels
- Study standard library exception patterns

## Connection to Next Module

This module provides the **foundation for type casting** in CPP_06. The concepts you'll need:

- **Class design principles** for casting operations
- **Type safety understanding** for casting decisions
- **Object lifecycle management** for casting contexts
- **Error handling patterns** for casting failures

**Next: [CPP_06 - Type Casting](../cpp_06/README.md)**

---

## Summary

CPP_05 introduces exception handling concepts through practical bureaucracy simulation exercises. You'll master:
- Custom exception creation and throwing
- Exception-safe class design and implementation
- Class invariant protection through exceptions
- Exception hierarchy design and management
- Resource management with RAII and exceptions
- Bureaucratic workflow simulation

These exception handling and robust design principles are crucial for understanding type safety, casting operations, and advanced error management in subsequent modules.