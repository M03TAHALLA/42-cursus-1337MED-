# 🍝 Philosophers

> *"I never thought philosophy would be so deadly"*

A multithreading and synchronization project that simulates the classic **Dining Philosophers Problem**. This project explores the fundamentals of concurrent programming, thread management, and race condition prevention.

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Score](https://img.shields.io/badge/Score-125%2F125-success?style=flat)](https://github.com/yourusername/philosophers)
[![Threads](https://img.shields.io/badge/Threads-pthreads-blue?style=flat)](https://man7.org/linux/man-pages/man7/pthreads.7.html)
[![Processes](https://img.shields.io/badge/Processes-Semaphores-orange?style=flat)](https://man7.org/linux/man-pages/man7/sem_overview.7.html)

## 📖 Table of Contents

- [About](#about)
- [The Problem](#the-problem)
- [Project Structure](#project-structure)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Technical Concepts](#technical-concepts)
- [Testing](#testing)
- [Performance](#performance)
- [Contributing](#contributing)
- [License](#license)

## 🎯 About

The **Philosophers** project is a classic computer science problem that demonstrates the challenges of concurrent programming. It simulates philosophers sitting around a table, alternating between eating, thinking, and sleeping, while sharing a limited number of forks.

This implementation includes both:
- **Mandatory Part**: Using threads and mutexes
- **Bonus Part**: Using processes and semaphores

## 🧠 The Problem

### The Scenario
- **N philosophers** sit around a circular table
- There is a **bowl of spaghetti** in the center
- There are **N forks** (one between each pair of philosophers)
- Philosophers alternate between **eating**, **thinking**, and **sleeping**
- To eat, a philosopher needs **both adjacent forks**
- If a philosopher doesn't eat within a specified time, they **die of starvation**

### The Challenge
- **No communication** between philosophers
- **Avoid deadlock** (all philosophers waiting for forks)
- **Prevent starvation** (ensure all philosophers can eat)
- **No data races** or undefined behavior

## 📁 Project Structure

```
philosophers/
├── philo/                          # Mandatory part (threads + mutexes)
│   ├── src/
│   │   ├── main.c                  # Program entry point
│   │   ├── init.c                  # Initialization functions
│   │   ├── simulation.c            # Main simulation loop
│   │   ├── philosopher.c           # Philosopher thread routine
│   │   ├── monitor.c               # Death monitoring
│   │   ├── utils.c                 # Utility functions
│   │   └── cleanup.c               # Memory cleanup
│   ├── includes/
│   │   └── philo.h                 # Header file
│   └── Makefile                    # Build configuration
│
├── philo_bonus/                    # Bonus part (processes + semaphores)
│   ├── src/
│   │   ├── main.c                  # Program entry point
│   │   ├── init.c                  # Initialization functions
│   │   ├── simulation.c            # Process management
│   │   ├── philosopher.c           # Philosopher process routine
│   │   ├── monitor.c               # Death monitoring
│   │   ├── utils.c                 # Utility functions
│   │   └── cleanup.c               # Resource cleanup
│   ├── includes/
│   │   └── philo_bonus.h           # Header file
│   └── Makefile                    # Build configuration
│
└── README.md                       # This file
```

## ✨ Features

### Mandatory Part (philo)
- ✅ **Thread-based implementation** using `pthread`
- ✅ **Mutex protection** for shared resources (forks)
- ✅ **Precise timing** with microsecond accuracy
- ✅ **Death detection** within 10ms requirement
- ✅ **Clean memory management** with no leaks
- ✅ **Race condition prevention**

### Bonus Part (philo_bonus)
- ✅ **Process-based implementation** using `fork()`
- ✅ **Semaphore synchronization** for resource management
- ✅ **Inter-process communication**
- ✅ **Signal handling** for clean termination
- ✅ **Distributed resource management**

## 🚀 Installation

### Prerequisites
- **GCC** compiler
- **Make** build system
- **POSIX-compliant** system (Linux, macOS)
- **pthread** library support
- **semaphore** support for bonus part

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/philosophers.git
cd philosophers

# Build mandatory part
cd philo
make

# Build bonus part
cd ../philo_bonus
make

# Build both parts
make all
```

### Clean Build Files
```bash
make clean      # Remove object files
make fclean     # Remove object files and executables
make re         # Rebuild everything
```

## 🎮 Usage

### Command Syntax
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters
- `number_of_philosophers`: Number of philosophers (and forks)
- `time_to_die`: Time in ms after which a philosopher dies if they haven't eaten
- `time_to_eat`: Time in ms it takes to eat (holding two forks)
- `time_to_sleep`: Time in ms spent sleeping
- `number_of_times_each_philosopher_must_eat`: (Optional) Simulation stops after each philosopher eats this many times

### Examples

```bash
# Basic simulation - 4 philosophers, die after 410ms, eat for 200ms, sleep for 200ms
./philo 4 410 200 200

# Simulation with meal limit - stops after each philosopher eats 5 times
./philo 5 800 200 200 5

# Edge case - single philosopher (should die)
./philo 1 400 200 200

# Stress test - many philosophers with tight timing
./philo 200 410 200 200
```

### Output Format
```
[timestamp_ms] [philosopher_id] has taken a fork
[timestamp_ms] [philosopher_id] is eating
[timestamp_ms] [philosopher_id] is sleeping
[timestamp_ms] [philosopher_id] is thinking
[timestamp_ms] [philosopher_id] died
```

## 🔧 Implementation Details

### Mandatory Part Architecture

#### Core Structures
```c
typedef struct s_philosopher {
    int             id;
    int             meals_eaten;
    long            last_meal_time;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
} t_philosopher;

typedef struct s_data {
    int                 philo_count;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 must_eat_count;
    long                start_time;
    bool                simulation_end;
    pthread_mutex_t     *forks;
    pthread_mutex_t     print_mutex;
    pthread_mutex_t     death_mutex;
    t_philosopher       *philosophers;
} t_data;
```

#### Key Algorithms

**Fork Acquisition Strategy:**
- Philosophers with odd IDs pick up left fork first
- Philosophers with even IDs pick up right fork first
- Prevents circular wait and deadlock

**Death Detection:**
- Dedicated monitoring thread checks each philosopher
- Uses precise timing with `gettimeofday()`
- Immediate termination upon death detection

### Bonus Part Architecture

#### Process Management
- Each philosopher runs as a separate process
- Main process coordinates and monitors children
- Uses `fork()` for process creation
- Signal handling for clean termination

#### Semaphore Usage
```c
sem_t *forks_sem;       // Controls access to forks
sem_t *print_sem;       // Synchronizes output
sem_t *death_sem;       // Signals death detection
```

## 🧮 Technical Concepts

### Threading Concepts (Mandatory)
- **Mutexes**: Ensure exclusive access to shared resources
- **Thread Synchronization**: Coordinate philosopher actions
- **Race Condition Prevention**: Protect critical sections
- **Deadlock Avoidance**: Strategic resource ordering

### Process Concepts (Bonus)
- **Inter-Process Communication**: Semaphores for coordination
- **Process Isolation**: Each philosopher is independent
- **Signal Handling**: Clean process termination
- **Resource Sharing**: Semaphore-controlled fork access

### Timing and Precision
- **Microsecond Timing**: Using `gettimeofday()` for precision
- **Sleep Functions**: `usleep()` for accurate delays
- **Death Detection**: Within 10ms requirement
- **Timestamp Calculation**: Relative to simulation start

## 🧪 Testing

### Test Categories

#### Basic Functionality
```bash
# Should not die
./philo 4 410 200 200

# Should die
./philo 1 400 200 200

# With meal limit
./philo 5 800 200 200 7
```

#### Edge Cases
```bash
# Invalid arguments
./philo 0 400 200 200
./philo 4 -1 200 200
./philo 4 400 200 200 0

# Resource stress
./philo 200 410 200 200
```

#### Performance Tests
```bash
# Long running simulation
./philo 4 2000 400 400

# Quick death detection
./philo 4 200 400 200
```

### Debugging Tools
- **Valgrind**: Memory leak detection
- **Helgrind**: Race condition detection
- **Custom logging**: Detailed execution traces

## ⚡ Performance

### Optimization Strategies

**Mandatory Part:**
- Efficient mutex usage patterns
- Minimal critical sections
- Optimized death detection loops
- Smart fork acquisition ordering

**Bonus Part:**
- Lightweight semaphore operations
- Efficient process communication
- Minimal system call overhead
- Fast signal handling

### Benchmarks
- **100 philosophers**: Stable execution
- **Death detection**: < 10ms accuracy
- **Memory usage**: Zero leaks
- **CPU efficiency**: Minimal overhead

## 🤝 Contributing

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Follow the 42 Norm coding standard
4. Test thoroughly
5. Submit a pull request

### Coding Standards
- **42 Norm Compliance**: Mandatory formatting rules
- **Memory Management**: No leaks allowed
- **Error Handling**: Comprehensive error checking
- **Documentation**: Clear code comments

## 📊 Project Stats

- **Language**: C
- **Lines of Code**: ~1500+
- **Functions**: 25+
- **Test Cases**: 50+
- **Development Time**: 3-4 weeks
- **Difficulty**: ⭐⭐⭐⭐⭐

## 🎓 Learning Outcomes

This project teaches:
- **Concurrent Programming**: Thread and process management
- **Synchronization**: Mutexes and semaphores
- **Race Conditions**: Detection and prevention
- **Deadlock**: Understanding and avoidance
- **System Programming**: Low-level resource management
- **Debugging**: Complex multithreaded applications

## 📝 License

This project is part of the 42 School curriculum. Code is available for educational purposes.

## 🙏 Acknowledgments

- **42 School** for providing this challenging project
- **Edsger Dijkstra** for the original dining philosophers problem
- **POSIX** threading and semaphore standards
- The **42 community** for peer learning and support

---

**Made with ❤️ by [TAHALLA MOHAMMED 'mtahalla'] | 42 Student**

*"In the realm of concurrent programming, timing is everything, and everything is timing 😉 ."*
