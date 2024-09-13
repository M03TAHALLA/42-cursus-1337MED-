<p align="center">
  <img src="https://lh3.googleusercontent.com/proxy/kaskFs0kmqsC-z-JVDzoG_AVDPH05QjfWn_Q6RKT3jPXe9nipn4szvJTvaDAP4eaGkfy7DFgEO3sNfWFgDqAkaWP3l1KHSo" alt="42 Logo" width="200px" />
</p>

<h1 align="center">LIBFT - 42 Cursus</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" />
  <img src="https://img.shields.io/badge/42-Project-success" />
</p>

<p align="center">
  A custom implementation of standard C library functions as part of the 42 Cursus at <a href="https://1337.ma">1337 School</a>.
</p>

---

## 📜 About the Project

LIBFT is the first project in the 42 curriculum. The goal is to recreate standard C library functions, which will be useful in future 42 projects. By writing these functions from scratch, students develop a deeper understanding of C, pointers, memory management, and algorithmic problem-solving.

This project also introduces you to **Makefiles**, which are essential for managing builds in larger projects.

---

## 🛠️ Features

The library implements the following categories of functions:

### Memory Functions
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memccpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`

### String Manipulation
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strchr`, `ft_strrchr`, `ft_strdup`, `ft_strncmp`, `ft_calloc`

### Character Checks
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

### Conversions
- `ft_atoi`,`ft_toupper`, `ft_tolower`

### String Manipulation 2 (Additional Functions)
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`

### File Descriptor Output Functions (Additional Functions)
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked Lists (Optional)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`
---

## 🚀 Installation

Clone the repository and compile the library using the Makefile:

```bash
git clone https://github.com/M03TAHALLA/42-cursus-1337MED-.git
cd 42-cursus-1337MED-/LIBFT
make
```
----


## 📦 Usage

To use this library in your project, follow these steps:

1. **Include the Header File**  
   In your source file, include the `libft.h` header to access the functions from the library:
   
   ```c
   #include "libft.h"
   ```
   
2. **Link the Library During Compilation**  
   When compiling your project, make sure to link the libft.a file. Here's an example of how to do this using `gcc`:
   
   ```bash
   gcc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
   ```
   - `L.` tells the compiler to look for the library in the current directory.
   - `- lft` links the libft.a library.

3. **Run Your Program**  
   After successfully compiling, run your program as usual:
   
   ```bash
   ./your_program
   ```
---

## 👤 Author

- **Tahalla Mohammed**  
  GitHub: [@M03TAHALLA](https://github.com/M03TAHALLA)
