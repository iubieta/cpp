# CPP_09 - STL Algorithms

> **Subject:** [CPP_09 PDF](CPP_09.pdf)

## Module Overview

This module introduces STL algorithms and advanced data structures, focusing on algorithm selection, complexity analysis, and implementing efficient solutions to complex problems. You'll learn how to use existing STL algorithms and create custom algorithms.

## Key Learning Objectives

### **Algorithm Fundamentals**
- Understanding algorithm complexity and selection
- STL algorithm categories and usage patterns
- Iterator-based algorithm design
- Performance analysis and optimization

### **Advanced Data Structures**
- Bitcoin exchange implementation
- Reverse Polish Notation calculator
- Pmerge algorithm with merge sort
- Custom algorithm design patterns

## Exercises Summary

### **Exercise 00 - Bitcoin Exchange**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement a bitcoin exchange system

**Learning Focus:**
- Algorithm design for resource allocation
- Data structure selection and optimization
- Performance analysis and improvement
- Complex system integration

### **Exercise 01 - Reverse Polish Notation**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement RPN calculator using STL containers

**Learning Focus:**
- Stack-based algorithm implementation
- Expression parsing and evaluation
- STL container usage in algorithms
- Error handling in mathematical operations

### **Exercise 02 - PmergeMe**
**Files:** `Makefile`, `main.cpp`
**Goal:** Implement merge sort algorithm with comparison

**Learning Focus:**
- Sorting algorithm implementation
- Performance comparison and analysis
- STL algorithm integration
- Multi-threading considerations

## Core Concepts Explained

### **Algorithm Categories**

```cpp
// Non-modifying sequence operations
std::find()        // Find element
std::count()       // Count elements
std::equal()      // Compare sequences
std::search()      // Find subsequence
std::min_element() // Find minimum
std::max_element() // Find maximum

// Modifying sequence operations
std::copy()        // Copy elements
std::fill()        // Fill range
std::transform()   // Transform elements
std::replace()     // Replace elements
std::remove()      // Remove elements

// Sorting operations
std::sort()       // Sort sequence
std::stable_sort() // Stable sort
std::partial_sort() // Partial sort
std::nth_element()  // Find nth element

// Binary search operations (require sorted input)
std::binary_search()   // Binary search
std::lower_bound()     // Find insertion point
std::upper_bound()     // Find insertion point
std::equal_range()     // Find range of equal elements
```

### **Complexity Analysis**

```cpp
// O(1) - Constant time
std::vector::push_back()  // Average case
std::list::front()        // Direct access
std::set::empty()        // Size check

// O(log n) - Logarithmic time
std::map::find()         // Tree-based lookup
std::set::insert()        // Tree-based insertion
std::binary_search()      // Binary search

// O(n) - Linear time
std::vector::find()       // Linear search
std::list::remove()       // Linear scan
std::accumulate()         // Process all elements

// O(n log n) - Linearithmic time
std::sort()              // Efficient sort
std::stable_sort()        // Stable sort
std::make_heap()         // Heap operations
```

### **Bitcoin Exchange Algorithm**

```cpp
// Bitcoin exchange with matching and optimization
class BitcoinExchange {
private:
    struct Request {
        std::string name;
        int amount;
        int timestamp;
        std::string status;
    };
    
    std::vector<Request> buy_requests;
    std::vector<Request> sell_requests;
    
public:
    void addRequest(bool is_buy, const std::string& name, int amount) {
        Request req = {name, amount, getCurrentTime(), "pending"};
        
        if (is_buy) {
            buy_requests.push_back(req);
        } else {
            sell_requests.push_back(req);
        }
        
        // Try to match immediately
        matchRequests();
    }
    
    void matchRequests() {
        // Sort both lists by amount
        std::sort(buy_requests.begin(), buy_requests.end(), 
                  [](const Request& a, const Request& b) {
                      return a.amount < b.amount;
                  });
        
        std::sort(sell_requests.begin(), sell_requests.end(), 
                  [](const Request& a, const Request& b) {
                      return a.amount < b.amount;
                  });
        
        // Match using two-pointer approach
        size_t buy_idx = 0, sell_idx = 0;
        
        while (buy_idx < buy_requests.size() && sell_idx < sell_requests.size()) {
            Request& buy = buy_requests[buy_idx];
            Request& sell = sell_requests[sell_idx];
            
            if (buy.amount >= sell.amount) {
                // Match found
                buy.status = "matched";
                sell.status = "matched";
                
                std::cout << "Matched: " << buy.name << " bought " 
                          << sell.amount << " from " << sell.name << std::endl;
                
                buy_idx++;
            } else {
                // Sell request is cheaper, skip it
                sell_idx++;
            }
        }
    }
    
private:
    int getCurrentTime() const {
        // Simple timestamp simulation
        static int counter = 0;
        return ++counter;
    }
};
```

### **Reverse Polish Notation**

```cpp
// RPN Calculator using STL stack
class RPNCalculator {
private:
    std::stack<std::string> operation_stack;
    
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int performOperation(int a, int b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        }
        return 0;
    }
    
public:
    int evaluate(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        
        while (iss >> token) {
            if (isOperator(token)) {
                if (operation_stack.size() < 2) {
                    throw std::runtime_error("Invalid RPN expression");
                }
                
                // Pop two operands
                int b = std::stoi(operation_stack.top());
                operation_stack.pop();
                int a = std::stoi(operation_stack.top());
                operation_stack.pop();
                
                // Perform operation and push result
                int result = performOperation(a, b, token);
                operation_stack.push(std::to_string(result));
            } else {
                // Push operand
                operation_stack.push(token);
            }
        }
        
        if (operation_stack.size() != 1) {
            throw std::runtime_error("Invalid RPN expression");
        }
        
        return std::stoi(operation_stack.top());
    }
};
```

### **Merge Sort Implementation**

```cpp
// Ford-Johnson merge sort algorithm for comparison
class PmergeMe {
private:
    template<typename T>
    static void merge(std::vector<T>& result, const std::vector<T>& left, 
                   const std::vector<T>& right) {
        size_t i = 0, j = 0;
        result.clear();
        result.reserve(left.size() + right.size());
        
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }
        }
        
        // Add remaining elements
        while (i < left.size()) {
            result.push_back(left[i++]);
        }
        while (j < right.size()) {
            result.push_back(right[j++]);
        }
    }
    
public:
    template<typename T>
    static std::vector<T> mergeSort(const std::vector<T>& input) {
        if (input.size() <= 1) {
            return input;
        }
        
        // Divide
        size_t mid = input.size() / 2;
        std::vector<T> left(input.begin(), input.begin() + mid);
        std::vector<T> right(input.begin() + mid, input.end());
        
        // Recursively sort and merge
        std::vector<T> sorted_left = mergeSort(left);
        std::vector<T> sorted_right = mergeSort(right);
        
        std::vector<T> result;
        merge(result, sorted_left, sorted_right);
        
        return result;
    }
    
    template<typename T>
    static void compareWithSTL(const std::vector<T>& test_data) {
        // Our implementation
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<T> our_result = mergeSort(test_data);
        auto our_time = std::chrono::high_resolution_clock::now() - start;
        
        // STL implementation
        start = std::chrono::high_resolution_clock::now();
        std::vector<T> stl_data = test_data;
        std::sort(stl_data.begin(), stl_data.end());
        auto stl_time = std::chrono::high_resolution_clock::now() - start;
        
        // Output comparison
        std::cout << "Data size: " << test_data.size() << std::endl;
        std::cout << "Our merge sort: " << our_time.count() << "ms" << std::endl;
        std::cout << "STL sort: " << stl_time.count() << "ms" << std::endl;
        std::cout << "Same result: " << (our_result == stl_data ? "Yes" : "No") << std::endl;
    }
};
```

### **Custom Algorithm Design**

```cpp
// Generic algorithm for finding median
template<typename T>
T findMedian(std::vector<T>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Cannot find median of empty dataset");
    }
    
    // Sort the data
    std::sort(data.begin(), data.end());
    
    size_t n = data.size();
    if (n % 2 == 1) {
        // Odd number of elements
        return data[n / 2];
    } else {
        // Even number of elements - return average of middle two
        return (data[n / 2 - 1] + data[n / 2]) / 2;
    }
}

// Custom algorithm for sliding window maximum
template<typename T>
std::vector<T> slidingMaximum(const std::vector<T>& data, size_t window_size) {
    std::vector<T> result;
    
    for (size_t i = 0; i + window_size <= data.size(); i++) {
        // Find maximum in current window
        auto max_it = std::max_element(data.begin() + i, 
                                       data.begin() + i + window_size);
        result.push_back(*max_it);
    }
    
    return result;
}

// Algorithm for top K frequent elements
template<typename T>
std::vector<std::pair<T, int>> topKFrequent(const std::vector<T>& data, size_t k) {
    std::map<T, int> frequency;
    
    // Count frequencies
    for (const auto& item : data) {
        frequency[item]++;
    }
    
    // Convert to vector for sorting
    std::vector<std::pair<T, int>> freq_vec(frequency.begin(), frequency.end());
    
    // Sort by frequency (descending)
    std::sort(freq_vec.begin(), freq_vec.end(),
              [](const std::pair<T, int>& a, const std::pair<T, int>& b) {
                  return a.second > b.second;
              });
    
    // Return top K
    if (freq_vec.size() > k) {
        freq_vec.resize(k);
    }
    
    return freq_vec;
}
```

## Implementation Patterns

### **Bitcoin Exchange with Optimization**

```cpp
class OptimizedBitcoinExchange {
private:
    struct Order {
        int id;
        bool is_buy;
        int amount;
        std::string customer;
        int timestamp;
        std::string status;
    };
    
    std::vector<Order> orders;
    int next_id;
    
public:
    OptimizedBitcoinExchange() : next_id(0) {}
    
    void addOrder(bool is_buy, const std::string& customer, int amount) {
        Order order = {
            next_id++,
            is_buy,
            amount,
            customer,
            getCurrentTime(),
            "pending"
        };
        
        orders.push_back(order);
        
        // Try to match immediately
        matchOrders();
    }
    
    void matchOrders() {
        // Separate buy and sell orders
        std::vector<Order> buys, sells;
        
        for (const auto& order : orders) {
            if (order.status == "pending") {
                if (order.is_buy) {
                    buys.push_back(order);
                } else {
                    sells.push_back(order);
                }
            }
        }
        
        // Sort both by amount
        std::sort(buys.begin(), buys.end(),
                  [](const Order& a, const Order& b) { return a.amount > b.amount; });
        
        std::sort(sells.begin(), sells.end(),
                  [](const Order& a, const Order& b) { return a.amount < b.amount; });
        
        // Match orders
        size_t buy_idx = 0, sell_idx = 0;
        int matched_count = 0;
        
        while (buy_idx < buys.size() && sell_idx < sells.size()) {
            Order& buy = buys[buy_idx];
            Order& sell = sells[sell_idx];
            
            if (buy.amount >= sell.amount) {
                // Match found
                buy.status = "matched";
                sell.status = "matched";
                matched_count++;
                
                std::cout << "Match #" << matched_count << ": "
                          << buy.customer << " bought " << sell.amount
                          << " from " << sell.customer << std::endl;
                
                buy_idx++;
            } else {
                // Sell too cheap, skip it
                sell_idx++;
            }
        }
        
        std::cout << "Total matches: " << matched_count << std::endl;
    }
    
private:
    int getCurrentTime() const {
        static int time = 0;
        return ++time;
    }
};
```

### **RPN Calculator with Error Handling**

```cpp
class SafeRPNCalculator {
private:
    std::stack<int> stack;
    
    void validateStack(size_t min_size, const std::string& operation) {
        if (stack.size() < min_size) {
            throw std::runtime_error("Invalid RPN: " + operation + " needs " + 
                                std::to_string(min_size) + " operands");
        }
    }
    
public:
    int evaluate(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        
        try {
            while (iss >> token) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    validateStack(2, token);
                    
                    int b = stack.top(); stack.pop();
                    int a = stack.top(); stack.pop();
                    
                    if (token == "/" && b == 0) {
                        throw std::runtime_error("Division by zero in RPN");
                    }
                    
                    if (token == "+") stack.push(a + b);
                    else if (token == "-") stack.push(a - b);
                    else if (token == "*") stack.push(a * b);
                    else if (token == "/") stack.push(a / b);
                } else {
                    // Validate numeric input
                    try {
                        stack.push(std::stoi(token));
                    } catch (const std::invalid_argument&) {
                        throw std::runtime_error("Invalid number in RPN: " + token);
                    }
                }
            }
            
            if (stack.size() != 1) {
                throw std::runtime_error("Invalid RPN: should have exactly one result");
            }
            
            return stack.top();
        } catch (const std::exception& e) {
            // Clear stack on error
            while (!stack.empty()) stack.pop();
            throw;
        }
    }
};
```

## Common Pitfalls & Solutions

### **Pitfall 1: Wrong Algorithm Selection**
```cpp
// ❌ Problem: Using O(n²) algorithm when O(n log n) exists
void inefficientSort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

// ✅ Solution: Use appropriate STL algorithm
void efficientSort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());  // O(n log n)
}
```

### **Pitfall 2: Iterator Invalidation in Algorithms**
```cpp
// ❌ Problem: Modifying container while iterating
void removeEvens(std::vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it % 2 == 0) {
            vec.erase(it);  // ❌ Invalidates iterator!
        }
    }
}

// ✅ Solution: Use erase-remove idiom
void removeEvens(std::vector<int>& vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                          [](int x) { return x % 2 == 0; }),
              vec.end());
}

// Or use index-based approach
void removeEvensIndex(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ) {
        if (vec[i] % 2 == 0) {
            vec.erase(vec.begin() + i);
        } else {
            i++;
        }
    }
}
```

### **Pitfall 3: Complexity Misunderstanding**
```cpp
// ❌ Problem: Assuming O(1) when it's actually O(n)
int findMax(const std::list<int>& lst) {
    if (lst.empty()) return 0;
    
    int max_val = lst.front();
    for (const auto& val : lst) {
        if (val > max_val) {
            max_val = val;  // O(n) for list, not O(1)
        }
    }
    return max_val;
}

// ✅ Solution: Use appropriate container
int findMax(const std::vector<int>& vec) {
    if (vec.empty()) return 0;
    
    // O(n) for vector, but can do random access
    return *std::max_element(vec.begin(), vec.end());
}
```

### **Pitfall 4: Exception Handling in Algorithms**
```cpp
// ❌ Problem: Not handling algorithm exceptions
void riskyAlgorithm() {
    std::vector<int> vec = {1, 2, 3};
    vec.at(100);  // Throws out_of_range
    
    // Program continues with undefined state
}

// ✅ Solution: Proper exception handling
void safeAlgorithm() {
    try {
        std::vector<int> vec = {1, 2, 3};
        vec.at(100);  // Throws out_of_range
    } catch (const std::out_of_range& e) {
        std::cerr << "Algorithm error: " << e.what() << std::endl;
        // Handle error appropriately
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
}
```

## Building & Testing

### **Build Commands**
```bash
# Build the STL algorithms project
make

# Clean build artifacts
make clean

# Full rebuild
make re
```

### **Sample Makefile**
```makefile
NAME = stl_algorithms

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
# Test Bitcoin exchange
$> ./stl_algorithms
Bitcoin Exchange Simulation:
Added buy order: Alice wants to buy 10 BTC
Added sell order: Bob wants to sell 5 BTC
Match #1: Alice bought 5 from Bob
Total matches: 1

# Test RPN calculator
$> ./stl_algorithms
RPN Calculator:
Expression: "3 4 + 2 * 7 /"
Step 1: 3 4 + -> stack: [7]
Step 2: 7 2 * -> stack: [14]
Step 3: 14 7 / -> stack: [2]
Result: 2

# Test merge sort comparison
$> ./stl_algorithms
Performance Comparison:
Data size: 10000
Our merge sort: 45ms
STL sort: 38ms
Same result: Yes
```

## Best Practices

### **Algorithm Selection**
- Consider input size and distribution
- Understand complexity implications
- Profile critical sections
- Choose appropriate STL algorithms

### **Performance Optimization**
- Use iterators efficiently
- Minimize memory allocations
- Consider cache locality
- Use move semantics when possible (C++11+)

### **Error Handling**
- Validate inputs before processing
- Use appropriate exception types
- Maintain consistent state on errors
- Document algorithm limitations

## Further Learning Resources

### **Official Documentation**
- [STL Algorithms - cppreference](https://en.cppreference.com/w/cpp/algorithm)
- [Complexity Analysis - cppreference](https://en.cppreference.com/w/cpp/algorithm/complexity)
- [Heap Operations - cppreference](https://en.cppreference.com/w/cpp/algorithm/make_heap)

### **Educational Resources**
- [STL Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms-in-c/)
- [Algorithm Complexity - GeeksforGeeks](https://www.geeksforgeeks.org/time-complexity-sorting-algorithms/)
- [Data Structures - GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/)

### **Practice Suggestions**
- Implement different sorting algorithms
- Create custom data structures
- Practice algorithm optimization
- Study real-world algorithm applications
- Experiment with parallel algorithms

---

## Conclusion

This completes the C++ learning journey! From basic syntax in CPP_00 through advanced STL algorithms in CPP_09, you've mastered:

### **Complete C++ Skill Set**
- **Fundamentals:** Syntax, memory management, OOP
- **Advanced:** Inheritance, polymorphism, exceptions, templates
- **Professional:** STL containers, algorithms, design patterns

### **Key Achievements**
- Understanding of type systems and casting
- Mastery of object-oriented design principles
- Proficiency in template programming
- Expertise in STL containers and algorithms
- Experience with performance optimization

### **Next Steps**
- Explore modern C++ (C++11/14/17/20)
- Study concurrent programming
- Learn network programming
- Practice software architecture
- Contribute to open-source projects

---

**Congratulations! You've completed a comprehensive C++ curriculum that provides a solid foundation for professional software development.** 🎉