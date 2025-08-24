# 🐚 Minishell - A Custom Unix Shell Implementation

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

**A fully functional Unix shell implementation written in C**

[![42 School Project](https://img.shields.io/badge/42%20Project-Minishell-blue)](https://github.com/your-username/minishell)
![Score](https://img.shields.io/badge/Score-125%2F125-brightgreen)
![Language](https://img.shields.io/badge/Language-C-blue)

---

*"The goal of this project is to create a simple shell. A shell that will make you nostalgic for the good old MS-DOS days."*

</div>

## 📋 Table of Contents

- [🎯 Project Overview](#-project-overview)
- [✨ Features](#-features)
- [🏗️ Architecture](#️-architecture)
- [🛠️ Installation](#️-installation)
- [🚀 Usage](#-usage)
- [🔧 Built-in Commands](#-built-in-commands)
- [💡 Advanced Features](#-advanced-features)
- [🧪 Testing](#-testing)
- [📁 Project Structure](#-project-structure)
- [👥 Contributors](#-contributors)
- [🏆 Achievements](#-achievements)
- [📚 Resources](#-resources)
- [📄 License](#-license)

## 🎯 Project Overview

Minishell is a comprehensive implementation of a Unix shell, developed as part of the 42 School curriculum. This project demonstrates deep understanding of system calls, process management, signal handling, and command-line parsing. Our implementation faithfully recreates the behavior of bash while maintaining clean, efficient code architecture.

### 🎖️ Project Score: **125/125** ⭐

## ✨ Features

### Core Functionality
- 🔄 **Command Execution**: Execute system commands with full path resolution
- 📝 **Command History**: Navigate through previously executed commands
- 🔀 **Pipes**: Chain commands with unlimited pipe sequences (`|`)
- 📤 **Redirections**: Input/output redirection with `<`, `>`, and `>>`
- 🔤 **Environment Variables**: Full support for environment variable expansion
- 💬 **Quote Handling**: Proper parsing of single and double quotes
- 🎯 **Signal Management**: Handle `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` like bash

### Advanced Features
- 🌟 **Here Documents**: `<<` operator with delimiter handling
- 🔍 **Wildcard Expansion**: `*` pattern matching in current directory
- 🎪 **Subshell Support**: Execute commands in subshells with `()`
- ⚡ **Logical Operators**: `&&` and `||` for conditional execution
- 🎨 **Custom Prompt**: Dynamic prompt with current directory and git branch

## 🏗️ Architecture

```
minishell/
├── src/
│   ├── parsing/          # Command parsing and tokenization
│   ├── execution/        # Command execution engine
│   ├── builtins/         # Built-in command implementations
│   ├── signals/          # Signal handling
│   ├── utils/            # Utility functions
│   └── main.c            # Main program loop
├── includes/
│   └── minishell.h       # Header file with structures and prototypes
├── libft/                # Custom C library
├── Makefile              # Build configuration
└── README.md             # This file
```

## 🛠️ Installation

### Prerequisites
- **GCC** or **Clang** compiler
- **GNU Make**
- **Readline library** (`sudo apt-get install libreadline-dev` on Ubuntu/Debian)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/your-username/minishell.git
cd minishell

# Compile the project
make

# Run minishell
./minishell
```

### Make Targets
```bash
make          # Compile the project
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile the entire project
make bonus    # Compile with bonus features
```

## 🚀 Usage

### Basic Commands
```bash
$ ls -la
$ pwd
$ echo "Hello, World!"
$ cat file.txt
```

### Pipes and Redirections
```bash
$ ls | grep .c | wc -l
$ echo "Hello" > output.txt
$ cat < input.txt > output.txt
$ ls >> log.txt
```

### Environment Variables
```bash
$ echo $HOME
$ export MY_VAR="Hello World"
$ echo $MY_VAR
```

### Here Documents
```bash
$ cat << EOF
> This is a here document
> It continues until EOF
> EOF
```

## 🔧 Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `echo` | Display text with optional `-n` flag | `echo [-n] [text]` |
| `cd` | Change directory with relative/absolute paths | `cd [directory]` |
| `pwd` | Print current working directory | `pwd` |
| `export` | Set environment variables | `export VAR=value` |
| `unset` | Unset environment variables | `unset VAR` |
| `env` | Display all environment variables | `env` |
| `exit` | Exit the shell with optional exit code | `exit [code]` |

### Built-in Command Features
- ✅ **Error Handling**: Proper error messages and exit codes
- ✅ **Edge Cases**: Handle special characters and empty arguments  
- ✅ **Bash Compatibility**: Behavior matches bash exactly

## 💡 Advanced Features

### Signal Handling
- **Ctrl+C**: Interrupt current command and display new prompt
- **Ctrl+D**: Exit shell when no input is provided
- **Ctrl+\**: Quit signal handling during command execution

### Quote Parsing
```bash
$ echo "Hello $USER"        # Variable expansion in double quotes
$ echo 'Hello $USER'        # Literal string in single quotes  
$ echo "It's a \"test\""    # Escaped quotes handling
```

### Wildcard Expansion
```bash
$ ls *.c                    # Expand to all .c files
$ echo test*                # Expand pattern in current directory
```

## 🧪 Testing

### Test Categories
- **Unit Tests**: Individual function testing
- **Integration Tests**: Full command execution testing
- **Edge Case Tests**: Memory leaks, signal handling, error conditions
- **Compatibility Tests**: Compare output with bash

### Running Tests
```bash
# Basic functionality test
make test

# Memory leak testing with valgrind
make test_valgrind

# Comprehensive test suite
make test_full
```

### Test Coverage
- ✅ All built-in commands
- ✅ Pipe chains with multiple commands
- ✅ Complex redirections
- ✅ Environment variable expansion
- ✅ Quote parsing edge cases
- ✅ Signal handling scenarios
- ✅ Memory management verification

## 📁 Project Structure

```
minishell/
├── 📂 src/
│   ├── 📂 parsing/
│   │   ├── lexer.c           # Token generation
│   │   ├── parser.c          # AST construction
│   │   ├── expander.c        # Variable expansion
│   │   └── quote_parser.c    # Quote handling
│   ├── 📂 execution/
│   │   ├── executor.c        # Main execution engine
│   │   ├── pipes.c           # Pipe handling
│   │   ├── redirections.c    # I/O redirection
│   │   └── process.c         # Process management
│   ├── 📂 builtins/
│   │   ├── echo.c            # Echo implementation
│   │   ├── cd.c              # Directory changing
│   │   ├── pwd.c             # Current directory
│   │   ├── export.c          # Environment variables
│   │   ├── unset.c           # Variable removal
│   │   ├── env.c             # Environment display
│   │   └── exit.c            # Shell exit
│   ├── 📂 signals/
│   │   └── signal_handler.c  # Signal management
│   ├── 📂 utils/
│   │   ├── error.c           # Error handling
│   │   ├── memory.c          # Memory management
│   │   └── string_utils.c    # String operations
│   └── main.c                # Program entry point
├── 📂 includes/
│   └── minishell.h           # Main header file
├── 📂 libft/                 # Custom C library
└── 📄 Makefile               # Build configuration
```

## 👥 Contributors

<table>
<tr>
<td align="center">
<a href="https://github.com/M03TAHALLA">
<img src="https://github.com/M03TAHALLA.png" width="100px;" alt=""/><br />
<sub><b>mtahalla</b></sub>
</a><br />
<sub>🏗️ Architecture & Core Development</sub>
</td>
<td align="center">
<a href="https://github.com/xMouka">
<img src="https://github.com/xMouka.png" width="100px;" alt=""/><br />
<sub><b>fbalyout (xMouka)</b></sub>
</a><br />
<sub>⚡ Execution Engine & Testing</sub>
</td>
</tr>
</table>

## 🏆 Achievements

- 🎯 **Perfect Score**: 125/125 on first evaluation
- 🔍 **Zero Memory Leaks**: Comprehensive memory management
- ⚡ **Performance Optimized**: Efficient parsing and execution
- 🛡️ **Robust Error Handling**: Graceful error recovery
- 📱 **Cross-Platform**: Works on Linux and macOS
- 🎨 **Clean Code**: Well-documented and maintainable

### Key Learning Outcomes
- Deep understanding of Unix system calls
- Advanced knowledge of process management
- Expertise in signal handling
- Proficiency in memory management
- Strong debugging and testing skills

## 📚 Resources

### Documentation
- [Bash Manual](https://www.gnu.org/software/bash/manual/)
- [POSIX Shell Specification](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [Advanced Programming in UNIX Environment](https://www.apuebook.com/)

### System Calls Used
- `fork()`, `execve()`, `wait()`, `waitpid()`
- `pipe()`, `dup()`, `dup2()`
- `open()`, `close()`, `read()`, `write()`
- `signal()`, `kill()`, `getpid()`
- `malloc()`, `free()`, `exit()`

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines. The code is provided for educational purposes and portfolio demonstration.

---

<div align="center">

**Made with ❤️ by [mtahalla]([https://github.com/M03TAHALLA](https://github.com/M03TAHALLA)) & [fbalyout](https://github.com/xMouka)**

*42 School Project - 2024*

![42 Logo](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

</div>
