# 🚀 CPP Module 00 - Introduction to C++

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Paradigm-orange?style=for-the-badge)

**First steps into Object-Oriented Programming with C++**

[![42 School Project](https://img.shields.io/badge/42%20Project-CPP00-blue)](https://github.com/your-username/CPP00)
![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)
![Language](https://img.shields.io/badge/Language-C++-blue)
![Standard](https://img.shields.io/badge/Standard-C++98-red)

---

*"Welcome to the world of Object-Oriented Programming! Your journey into C++ begins here."*

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

CPP Module 00 is the first module in the comprehensive C++ curriculum at 42 School. This project introduces fundamental C++ concepts, transitioning from C programming to object-oriented programming paradigms. Through carefully designed exercises, students learn basic C++ syntax, classes, member functions, and essential OOP principles.

### 🎖️ Project Score: **100/100** ⭐

## ✨ Learning Objectives

### Core C++ Concepts
- 🔄 **Namespaces**: Understanding scope and namespace usage
- 📦 **Classes & Objects**: Introduction to object-oriented design
- 🛠️ **Member Functions**: Methods and data encapsulation
- 🔒 **Access Specifiers**: Public, private, and protected members
- 📝 **Constructors & Destructors**: Object lifecycle management
- 📊 **Static Members**: Class-level variables and functions

### Programming Paradigms
- 🎯 **Encapsulation**: Data hiding and interface design
- 🔗 **Abstraction**: Simplifying complex systems
- 💡 **Code Organization**: Header files and implementation separation
- 🎨 **C++ Standards**: Adherence to C++98 standard

## 📚 Exercises

### Exercise 00: Megaphone
**File**: `ex00/megaphone.cpp`

A simple program that converts command-line arguments to uppercase, demonstrating:
- Basic C++ I/O with `std::cout` and `std::cin`
- String manipulation using C++ string class
- Command-line argument processing

```cpp
./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

### Exercise 01: My Awesome PhoneBook
**Files**: `ex01/PhoneBook.cpp`, `ex01/Contact.cpp`, `ex01/main.cpp`

A phonebook application showcasing:
- **Class Design**: `PhoneBook` and `Contact` classes
- **Data Encapsulation**: Private member variables with public interfaces
- **Array Management**: Fixed-size contact storage (8 contacts maximum)
- **User Interface**: Interactive command-line menu system
- **Input Validation**: Robust error handling for user input

**Features:**
- 📞 **ADD**: Store new contacts with validation
- 🔍 **SEARCH**: Display contacts in formatted table
- 🚪 **EXIT**: Graceful program termination

### Exercise 02: The Job Of Your Dreams
**Files**: `ex02/Account.cpp`, `ex02/tests.cpp`

Implementation of a banking account system demonstrating:
- **Static Members**: Class-level counters and amounts
- **Constructor/Destructor**: Proper object initialization and cleanup  
- **Member Functions**: Deposits, withdrawals, and account queries
- **Const Methods**: Read-only member functions
- **Display Functions**: Formatted output with timestamps

## 🏗️ Project Structure

```
CPP00/
├── ex00/
│   ├── megaphone.cpp         # Simple string conversion utility
│   └── Makefile              # Build configuration
├── ex01/
│   ├── PhoneBook.hpp         # PhoneBook class declaration
│   ├── PhoneBook.cpp         # PhoneBook implementation
│   ├── Contact.hpp           # Contact class declaration
│   ├── Contact.cpp           # Contact implementation
│   ├── main.cpp              # Main program entry
│   └── Makefile              # Build configuration
├── ex02/
│   ├── Account.hpp           # Account class declaration (provided)
│   ├── Account.cpp           # Account implementation
│   ├── tests.cpp             # Test suite (provided)
│   └── Makefile              # Build configuration
└── README.md                 # This documentation
```

## 🛠️ Compilation & Usage

### Prerequisites
- **C++ Compiler**: g++ or clang++ with C++98 support
- **Make**: GNU Make for build automation

### Compilation Flags
```bash
-Wall -Wextra -Werror -std=c++98
```

### Build Instructions

```bash
# Exercise 00 - Megaphone
cd ex00
make
./megaphone [arguments]

# Exercise 01 - PhoneBook
cd ex01
make
./phonebook

# Exercise 02 - Account
cd ex02
make
./account
```

### Usage Examples

**Megaphone:**
```bash
./megaphone hello world
HELLO WORLD

./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**PhoneBook:**
```
Welcome to Your Awesome PhoneBook!
Enter a command: ADD
First Name: John
Last Name: Doe
Nickname: Johnny
Phone Number: 555-0123
Darkest Secret: Loves pineapple pizza

Contact added successfully!
```

**Account System:**
```
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
...
```

## 💡 Key Concepts

### Object-Oriented Programming Fundamentals

**Classes and Objects:**
```cpp
class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    
public:
    Contact();
    ~Contact();
    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;
};
```

**Encapsulation:**
- Private data members for internal state
- Public methods for controlled access
- Getter and setter functions for data validation

**Static Members:**
```cpp
class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    
public:
    static int getNbAccounts();
    static int getTotalAmount();
};
```

### C++ vs C Differences
| Concept | C | C++ |
|---------|---|-----|
| I/O | `printf`, `scanf` | `std::cout`, `std::cin` |
| Strings | `char*`, `char[]` | `std::string` |
| Memory | Manual management | RAII principles |
| Functions | Global functions | Member functions |
| Organization | Files | Namespaces & Classes |

## 🧪 Testing

### Test Categories
- **Functionality Tests**: Verify core features work correctly
- **Edge Case Tests**: Boundary conditions and error handling
- **Memory Tests**: No memory leaks or undefined behavior
- **Compilation Tests**: Code compiles with strict flags

### PhoneBook Test Scenarios
```bash
# Test contact storage limit
ADD -> 9 contacts (should replace oldest)

# Test search functionality  
SEARCH -> Display formatted table

# Test input validation
ADD -> Empty fields (should prompt retry)

# Test program termination
EXIT -> Clean shutdown
```

### Account System Validation
- Constructor/destructor call order
- Static member updates
- Transaction validation
- Output format verification

## 📖 Code Examples

### Contact Class Implementation
```cpp
// Contact.hpp
class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();
    
    // Setters with validation
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    
    // Const getters
    std::string getFirstName() const;
    std::string getLastName() const;
    
    // Utility functions
    void displayContact() const;
    bool isEmpty() const;
};
```

### PhoneBook Class Features
```cpp
class PhoneBook {
private:
    Contact     _contacts[8];
    int         _currentIndex;
    int         _totalContacts;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact();
    void searchContacts() const;
    void displayContactsTable() const;
};
```

### Static Member Usage
```cpp
// Account.cpp
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;

Account::Account(int initial_deposit) : 
    _accountIndex(_nbAccounts++),
    _amount(initial_deposit)
{
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
```

## 🎓 Skills Acquired

### Technical Skills
- ✅ **C++ Syntax**: Mastery of basic C++ language features
- ✅ **OOP Principles**: Understanding of encapsulation and abstraction
- ✅ **Class Design**: Creating well-structured class hierarchies
- ✅ **Memory Management**: RAII and constructor/destructor patterns
- ✅ **Standard Library**: Using std::string and iostream effectively

### Programming Practices
- ✅ **Code Organization**: Proper header/implementation separation
- ✅ **Const Correctness**: Appropriate use of const methods and variables
- ✅ **Input Validation**: Robust error handling and user input processing
- ✅ **Documentation**: Clear, maintainable code with good naming conventions
- ✅ **Testing**: Comprehensive validation of program functionality

## 📁 File Organization

```
CPP00/
├── 📂 ex00/                    # Exercise 00: Megaphone
│   ├── 📄 megaphone.cpp        # Main program file
│   └── 📄 Makefile             # Build configuration
├── 📂 ex01/                    # Exercise 01: PhoneBook
│   ├── 📄 PhoneBook.hpp        # PhoneBook class header
│   ├── 📄 PhoneBook.cpp        # PhoneBook implementation
│   ├── 📄 Contact.hpp          # Contact class header
│   ├── 📄 Contact.cpp          # Contact implementation  
│   ├── 📄 main.cpp             # Program entry point
│   └── 📄 Makefile             # Build configuration
├── 📂 ex02/                    # Exercise 02: Account
│   ├── 📄 Account.hpp          # Account class header (given)
│   ├── 📄 Account.cpp          # Account implementation
│   ├── 📄 tests.cpp            # Test suite (given)
│   └── 📄 Makefile             # Build configuration
└── 📄 README.md                # Project documentation
```

## 🏆 Achievements

- 🎯 **Perfect Score**: 100/100 on first evaluation
- 🔍 **Zero Compilation Warnings**: Clean code with strict compiler flags
- ⚡ **Efficient Implementation**: Optimized memory usage and performance
- 🛡️ **Robust Error Handling**: Comprehensive input validation
- 📱 **Cross-Platform**: Compatible across different Unix systems
- 🎨 **Clean Architecture**: Well-organized, maintainable codebase

### Key Accomplishments
- **Object-Oriented Mastery**: Successfully transitioned from procedural to OOP
- **C++ Standards Compliance**: Strict adherence to C++98 standard
- **Professional Code Quality**: Industry-standard formatting and documentation
- **Comprehensive Testing**: Thorough validation of all functionality
- **Problem-Solving Skills**: Creative solutions to complex requirements

## 📚 Resources

### Documentation
- [C++ Reference](https://en.cppreference.com/)
- [C++98 Standard](https://www.iso.org/standard/25845.html)
- [Bjarne Stroustrup's C++ Page](https://www.stroustrup.com/)

### Key Topics Covered
- **Basic Syntax**: Variables, functions, control structures
- **Classes**: Member variables, member functions, constructors
- **Access Control**: Public, private, protected specifiers
- **Static Members**: Class-level data and functions
- **Const Correctness**: Immutable objects and methods
- **I/O Streams**: std::cout, std::cin, std::endl

### C++ Features Used
- `std::string` for string manipulation
- `std::cout` and `std::cin` for I/O operations
- `std::endl` and `std::flush` for output formatting
- Class constructors and destructors
- Static member variables and functions
- Const member functions

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines. The code is provided for educational purposes and portfolio demonstration.

---

<div align="center">

**Made with 💻 by [mtahalla](https://github.com/M03TAHALLA)

*42 School - CPP Module 00 - 2024*

![42 Logo](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>