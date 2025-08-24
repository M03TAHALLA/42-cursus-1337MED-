# 🧠 CPP Module 01 - Memory Allocation, Pointers & References

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Memory](https://img.shields.io/badge/Memory-Management-red?style=for-the-badge)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

**Mastering memory management, pointers, references, and the switch to heap allocation**

[![42 School Project](https://img.shields.io/badge/42%20Project-CPP01-blue)](https://github.com/your-username/CPP01)
![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)
![Language](https://img.shields.io/badge/Language-C++-blue)
![Standard](https://img.shields.io/badge/Standard-C++98-red)

---

*"Memory management is the foundation of robust C++ programming. Master it, and you master C++."*

</div>

## 📋 Table of Contents

- [🎯 Project Overview](#-project-overview)
- [✨ Learning Objectives](#-learning-objectives)
- [📚 Exercises](#-exercises)
- [🏗️ Project Structure](#️-project-structure)
- [🛠️ Compilation & Usage](#️-compilation--usage)
- [💡 Key Concepts](#-key-concepts)
- [🧪 Testing](#-testing)
- [📖 Code Examples](#-code-examples)
- [🎓 Skills Acquired](#-skills-acquired)
- [📁 File Organization](#-file-organization)
- [🏆 Achievements](#-achievements)
- [📚 Resources](#-resources)
- [📄 License](#-license)

## 🎯 Project Overview

CPP Module 01 dives deep into memory management in C++, introducing crucial concepts like dynamic allocation with `new` and `delete`, references vs pointers, and proper resource management. This module builds upon CPP00's foundation by exploring how objects live and die in memory, establishing patterns that prevent memory leaks and undefined behavior.

### 🎖️ Project Score: **100/100** ⭐

## ✨ Learning Objectives

### Memory Management Mastery
- 🔄 **Dynamic Allocation**: `new` and `delete` operators
- 📦 **Stack vs Heap**: Understanding memory segments
- 🛠️ **References**: Alternative to pointers for cleaner code
- 🔒 **RAII Principles**: Resource Acquisition Is Initialization
- 📝 **Object Lifetime**: Constructor/destructor timing
- 📊 **Memory Safety**: Preventing leaks and dangling pointers

### Advanced C++ Features
- 🎯 **Member Function Pointers**: Pointers to class methods
- 🔗 **File Streams**: Reading and writing files
- 💡 **String Manipulation**: Advanced std::string operations
- 🎨 **Switch Statements**: Efficient conditional logic

## 📚 Exercises

### Exercise 00: BraiiiiiiinnnzzzZ
**Files**: `ex00/Zombie.cpp`, `ex00/Zombie.hpp`, `ex00/main.cpp`

Introduction to heap allocation and object destruction:
- **Dynamic Zombie Creation**: `newZombie()` allocates on heap
- **Stack Zombie Creation**: `randomChump()` creates on stack
- **Memory Management**: Proper cleanup with `delete`
- **Destructor Timing**: Observing when objects are destroyed

```cpp
Zombie* heapZombie = newZombie("HeapWalker");
heapZombie->announce();
delete heapZombie;  // Manual cleanup required

randomChump("StackWalker");  // Automatic cleanup
```

### Exercise 01: Moar brainz!
**Files**: `ex01/Zombie.cpp`, `ex01/Zombie.hpp`, `ex01/zombieHorde.cpp`

Array allocation and batch object management:
- **Dynamic Array Creation**: `zombieHorde()` creates zombie arrays
- **Constructor Parameterization**: Setting names after allocation
- **Batch Operations**: Managing multiple objects efficiently
- **Array Cleanup**: Single `delete[]` for entire array

```cpp
Zombie* horde = zombieHorde(5, "Walker");
// All 5 zombies announce themselves
delete[] horde;  // Clean up entire horde
```

### Exercise 02: HI THIS IS BRAIN
**Files**: `ex02/main.cpp`

Understanding references vs pointers:
- **Reference Declaration**: Creating aliases to variables
- **Pointer Comparison**: Demonstrating pointer flexibility
- **Memory Addresses**: Comparing address access methods
- **Value Access**: Different ways to access stored values

```cpp
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;
std::string& stringREF = brain;

// All point to same memory location
// All access same value differently
```

### Exercise 03: Unnecessary violence
**Files**: `ex03/Weapon.cpp`, `ex03/HumanA.cpp`, `ex03/HumanB.cpp`

References vs pointers in class design:
- **HumanA Class**: Uses weapon reference (always armed)
- **HumanB Class**: Uses weapon pointer (optionally armed)  
- **Design Patterns**: When to use references vs pointers
- **Object Relationships**: Composition and aggregation

```cpp
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);     // Reference - always has weapon
HumanB jim("Jim");           // Pointer - might get weapon later
jim.setWeapon(club);
```

### Exercise 04: Sed is for losers
**Files**: `ex04/main.cpp`, `ex04/FileReplacer.cpp`

File manipulation and string processing:
- **File Stream Operations**: Reading and writing files
- **String Replacement**: Custom `sed`-like functionality
- **Error Handling**: Robust file operation validation
- **Command-line Processing**: Argument parsing and validation

```cpp
./replace filename "old_string" "new_string"
// Creates filename.replace with substitutions
```

### Exercise 05: Harl 2.0
**Files**: `ex05/Harl.cpp`, `ex05/Harl.hpp`, `ex05/main.cpp`

Function pointers and member function arrays:
- **Member Function Pointers**: Array of method pointers
- **Dynamic Method Selection**: Runtime function selection
- **Switch Alternatives**: Elegant conditional execution
- **Logging System**: Professional logging implementation

```cpp
Harl harl;
harl.complain("DEBUG");
harl.complain("INFO");
harl.complain("WARNING");
harl.complain("ERROR");
```

### Exercise 06: Harl filter
**Files**: `ex06/Harl.cpp`, `ex06/main.cpp`

Switch statements and filtering systems:
- **Switch Implementation**: Efficient conditional logic
- **Level Filtering**: Displaying messages above threshold
- **Fall-through Behavior**: Leveraging switch characteristics
- **Command-line Integration**: Argument-based filtering

```cpp
./harlFilter WARNING
// Shows WARNING and ERROR messages only
```

## 🏗️ Project Structure

```
CPP01/
├── ex00/                    # BraiiiiiiinnnzzzZ
│   ├── Zombie.hpp           # Zombie class declaration
│   ├── Zombie.cpp           # Zombie implementation
│   ├── newZombie.cpp        # Heap allocation function
│   ├── randomChump.cpp      # Stack allocation function
│   ├── main.cpp             # Test program
│   └── Makefile             # Build configuration
├── ex01/                    # Moar brainz!
│   ├── Zombie.hpp           # Enhanced Zombie class
│   ├── Zombie.cpp           # Zombie implementation
│   ├── zombieHorde.cpp      # Array allocation function
│   ├── main.cpp             # Horde testing
│   └── Makefile             # Build configuration
├── ex02/                    # HI THIS IS BRAIN
│   ├── main.cpp             # Reference vs pointer demo
│   └── Makefile             # Build configuration
├── ex03/                    # Unnecessary violence
│   ├── Weapon.hpp           # Weapon class header
│   ├── Weapon.cpp           # Weapon implementation
│   ├── HumanA.hpp           # HumanA class header
│   ├── HumanA.cpp           # HumanA implementation
│   ├── HumanB.hpp           # HumanB class header
│   ├── HumanB.cpp           # HumanB implementation
│   ├── main.cpp             # Combat simulation
│   └── Makefile             # Build configuration
├── ex04/                    # Sed is for losers
│   ├── FileReplacer.hpp     # File processing class
│   ├── FileReplacer.cpp     # File operations implementation
│   ├── main.cpp             # Main program logic
│   └── Makefile             # Build configuration
├── ex05/                    # Harl 2.0
│   ├── Harl.hpp             # Harl class header
│   ├── Harl.cpp             # Harl implementation
│   ├── main.cpp             # Complaint testing
│   └── Makefile             # Build configuration
├── ex06/                    # Harl filter
│   ├── Harl.hpp             # Harl class header (reused)
│   ├── Harl.cpp             # Enhanced Harl with filtering
│   ├── main.cpp             # Filter application
│   └── Makefile             # Build configuration
└── README.md                # This documentation
```

## 🛠️ Compilation & Usage

### Prerequisites
- **C++ Compiler**: g++ or clang++ with C++98 support
- **Make**: GNU Make for build automation

### Compilation Flags
```bash
-Wall -Wextra -Werror -std=c++98
```

### Build & Run Instructions

```bash
# Exercise 00 - Zombies
cd ex00 && make && ./brainz

# Exercise 01 - Zombie Horde  
cd ex01 && make && ./horde

# Exercise 02 - Brain Reference
cd ex02 && make && ./brain

# Exercise 03 - Violence
cd ex03 && make && ./violence

# Exercise 04 - File Replace
cd ex04 && make && ./replace input.txt "old" "new"

# Exercise 05 - Harl Complaints
cd ex05 && make && ./harl

# Exercise 06 - Harl Filter
cd ex06 && make && ./harlFilter "WARNING"
```

### Usage Examples

**Zombie Creation:**
```
Creating zombie on the heap: HeapZombie
HeapZombie: BraiiiiiiinnnzzzZ...
Creating zombie on the stack: StackZombie
StackZombie: BraiiiiiiinnnzzzZ...
StackZombie is destroyed
HeapZombie is destroyed
```

**File Replacement:**
```bash
# Create test file
echo "Hello old world, old friend!" > test.txt

# Run replacement
./replace test.txt "old" "new"

# Check result
cat test.txt.replace
# Output: Hello new world, new friend!
```

**Harl Complaints:**
```
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!

[ INFO ]  
I cannot believe adding extra bacon costs more money...
```

## 💡 Key Concepts

### Memory Management Patterns

**Stack vs Heap Allocation:**
```cpp
// Stack allocation - automatic cleanup
void stackExample() {
    Zombie stackZombie("Local");
    // Destructor called automatically at scope exit
}

// Heap allocation - manual cleanup required
void heapExample() {
    Zombie* heapZombie = new Zombie("Dynamic");
    // ... use zombie ...
    delete heapZombie;  // Manual cleanup essential
}
```

**Array Management:**
```cpp
// Dynamic array allocation
Zombie* createHorde(int n) {
    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++) {
        horde[i].setName("Walker " + std::to_string(i));
    }
    return horde;
}

// Proper cleanup
Zombie* horde = createHorde(5);
delete[] horde;  // Use delete[] for arrays
```

### References vs Pointers

| Feature | Reference | Pointer |
|---------|-----------|---------|
| **Initialization** | Must be initialized | Can be uninitialized |
| **Reassignment** | Cannot be reassigned | Can point to different objects |
| **Null Values** | Cannot be null | Can be null |
| **Arithmetic** | No pointer arithmetic | Supports arithmetic |
| **Syntax** | Direct access | Requires dereferencing |

```cpp
// Reference example - HumanA
class HumanA {
private:
    std::string _name;
    Weapon& _weapon;  // Reference - always valid
    
public:
    HumanA(std::string name, Weapon& weapon) 
        : _name(name), _weapon(weapon) {}
    
    void attack() {
        std::cout << _name << " attacks with their " 
                  << _weapon.getType() << std::endl;
    }
};

// Pointer example - HumanB  
class HumanB {
private:
    std::string _name;
    Weapon* _weapon;  // Pointer - might be null
    
public:
    HumanB(std::string name) : _name(name), _weapon(NULL) {}
    
    void setWeapon(Weapon& weapon) {
        _weapon = &weapon;
    }
    
    void attack() {
        if (_weapon)
            std::cout << _name << " attacks with their " 
                      << _weapon->getType() << std::endl;
        else
            std::cout << _name << " has no weapon!" << std::endl;
    }
};
```

### Function Pointers in Classes

```cpp
class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    void complain(std::string level) {
        // Array of member function pointers
        void (Harl::*functions[])(void) = {
            &Harl::debug,
            &Harl::info, 
            &Harl::warning,
            &Harl::error
        };
        
        std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        
        for (int i = 0; i < 4; i++) {
            if (levels[i] == level) {
                (this->*functions[i])();
                return;
            }
        }
    }
};
```

## 🧪 Testing

### Memory Management Tests
- **Leak Detection**: Valgrind testing for all exercises
- **Double Delete**: Prevention of double deletion errors
- **Null Pointer**: Handling null pointer scenarios
- **Array Bounds**: Preventing buffer overflows

### Functionality Tests
```bash
# Test zombie creation and destruction order
valgrind --leak-check=full ./brainz

# Test file replacement edge cases
./replace empty.txt "test" "new"      # Empty file
./replace missing.txt "old" "new"     # Missing file
./replace test.txt "" "replacement"   # Empty search string

# Test Harl with invalid levels
./harlFilter "INVALID"                # Invalid level
./harlFilter                          # No arguments
```

### Edge Case Scenarios
- **Memory Exhaustion**: Handling allocation failures
- **File Permissions**: Read-only and write-protected files
- **Large Files**: Performance with substantial file sizes
- **Unicode Content**: Handling special characters in replacements

## 📖 Code Examples

### Zombie Class with Proper Memory Management
```cpp
// Zombie.hpp
class Zombie {
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    
    void announce(void);
    void setName(std::string name);
};

// Zombie.cpp
Zombie::Zombie() : _name("Unnamed") {
    std::cout << "Zombie " << _name << " is born" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << _name << " is born" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

### File Processing with Error Handling
```cpp
class FileReplacer {
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    
public:
    FileReplacer(std::string filename, std::string s1, std::string s2);
    bool replace();
    
private:
    std::string replaceAll(std::string content);
    bool isValidInput();
};

bool FileReplacer::replace() {
    if (!isValidInput())
        return false;
        
    std::ifstream infile(_filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open " << _filename << std::endl;
        return false;
    }
    
    std::string content;
    std::string line;
    while (std::getline(infile, line)) {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();
    
    content = replaceAll(content);
    
    std::ofstream outfile((_filename + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        return false;
    }
    
    outfile << content;
    outfile.close();
    return true;
}
```

### Weapon System Design
```cpp
// Weapon.hpp
class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string type);
};

// Usage demonstrates reference vs pointer design
int main() {
    Weapon club("crude spiked club");
    
    // HumanA uses reference - weapon required at construction
    HumanA bob("Bob", club);
    bob.attack();
    
    // HumanB uses pointer - weapon optional
    HumanB jim("Jim");
    jim.attack();          // No weapon
    jim.setWeapon(club);
    jim.attack();          // Now has weapon
    
    return 0;
}
```

## 🎓 Skills Acquired

### Memory Management Mastery
- ✅ **Dynamic Allocation**: Proficient with `new` and `delete` operators
- ✅ **Resource Management**: Understanding of RAII principles
- ✅ **Memory Safety**: Prevention of leaks and dangling pointers
- ✅ **Stack vs Heap**: Strategic choice between allocation methods
- ✅ **Array Management**: Proper handling of dynamic arrays

### Advanced C++ Features
- ✅ **References**: Mastery of reference semantics and usage
- ✅ **Function Pointers**: Member function pointer arrays
- ✅ **File Streams**: Robust file I/O operations
- ✅ **String Processing**: Advanced std::string manipulation
- ✅ **Error Handling**: Comprehensive validation and error recovery

### Design Patterns
- ✅ **Composition vs Aggregation**: Choosing between references and pointers
- ✅ **Resource Ownership**: Clear ownership semantics
- ✅ **Constructor Design**: Initialization lists and member initialization
- ✅ **Destructor Patterns**: Proper cleanup and resource release
- ✅ **Factory Functions**: Dynamic object creation patterns

## 📁 File Organization

```
CPP01/
├── 📂 ex00/                           # Basic memory allocation
│   ├── 📄 Zombie.hpp                  # Zombie class declaration
│   ├── 📄 Zombie.cpp                  # Zombie implementation
│   ├── 📄 newZombie.cpp               # Heap allocation
│   ├── 📄 randomChump.cpp             # Stack allocation
│   ├── 📄 main.cpp                    # Testing program
│   └── 📄 Makefile                    # Build config
├── 📂 ex01/                           # Array allocation
│   ├── 📄 Zombie.hpp                  # Enhanced Zombie
│   ├── 📄 Zombie.cpp                  # Implementation
│   ├── 📄 zombieHorde.cpp             # Array creation
│   ├── 📄 main.cpp                    # Horde testing
│   └── 📄 Makefile                    # Build config
├── 📂 ex02/                           # References introduction
│   ├── 📄 main.cpp                    # Reference demo
│   └── 📄 Makefile                    # Build config
├── 📂 ex03/                           # References vs pointers
│   ├── 📄 Weapon.hpp/.cpp             # Weapon system
│   ├── 📄 HumanA.hpp/.cpp             # Reference-based human
│   ├── 📄 HumanB.hpp/.cpp             # Pointer-based human
│   ├── 📄 main.cpp                    # Combat demo
│   └── 📄 Makefile                    # Build config
├── 📂 ex04/                           # File processing
│   ├── 📄 FileReplacer.hpp/.cpp       # File manipulation
│   ├── 📄 main.cpp                    # Replace utility
│   └── 📄 Makefile                    # Build config
├── 📂 ex05/                           # Function pointers
│   ├── 📄 Harl.hpp/.cpp               # Logging system
│   ├── 📄 main.cpp                    # Complaint demo
│   └── 📄 Makefile                    # Build config
├── 📂 ex06/                           # Switch statements
│   ├── 📄 Harl.hpp/.cpp               # Enhanced logging
│   ├── 📄 main.cpp                    # Filter program
│   └── 📄 Makefile                    # Build config
└── 📄 README.md                       # Documentation
```

## 🏆 Achievements

- 🎯 **Perfect Score**: 100/100 on first evaluation
- 🔍 **Zero Memory Leaks**: Comprehensive memory management
- ⚡ **Efficient Design**: Optimal use of references vs pointers
- 🛡️ **Robust Error Handling**: Bulletproof file operations
- 📱 **Cross-Platform**: Compatible across Unix systems
- 🎨 **Clean Architecture**: Professional code organization

### Key Accomplishments
- **Memory Management Expertise**: Mastered dynamic allocation patterns
- **Reference Mastery**: Deep understanding of reference semantics
- **File I/O Proficiency**: Robust file processing implementations
- **Design Pattern Knowledge**: Appropriate use of composition and aggregation
- **Error Handling Excellence**: Comprehensive validation and recovery
- **Performance Optimization**: Efficient memory usage and minimal overhead

## 📚 Resources

### Documentation
- [C++ Dynamic Memory Management](https://en.cppreference.com/w/cpp/memory)
- [References in C++](https://en.cppreference.com/w/cpp/language/reference)
- [File I/O Streams](https://en.cppreference.com/w/cpp/io)
- [Function Pointers](https://en.cppreference.com/w/cpp/language/pointer#Pointers_to_functions)

### Key Topics Mastered
- **Dynamic Allocation**: `new`, `delete`, `new[]`, `delete[]`
- **References**: Declaration, initialization, usage patterns
- **Pointers vs References**: When to use each approach
- **Member Function Pointers**: Arrays of method pointers
- **File Streams**: `std::ifstream`, `std::ofstream`
- **String Operations**: `find()`, `substr()`, `replace()`
- **Switch Statements**: Fall-through behavior and efficient branching

### Memory Management Best Practices
- Always pair `new` with `delete`
- Use `delete[]` for arrays allocated with `new[]`
- Initialize pointers to `NULL` when not immediately assigned
- Prefer references when the object should always exist
- Use pointers when optional relationships are needed
- Implement RAII patterns for automatic resource management

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines. The code is provided for educational purposes and portfolio demonstration.

---

<div align="center">

**Made with 🧠 by [mtahalla](https://github.com/M03TAHALLA)

*42 School - CPP Module 01 - 2024*

![42 Logo](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Memory](https://img.shields.io/badge/Memory-Management-red?style=for-the-badge)

</div>