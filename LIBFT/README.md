<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/42_Logo.svg/1200px-42_Logo.svg.png" alt="42 Logo" width="200px" />
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
- `ft_strlen`, `ft_strcpy`, `ft_strncpy`, `ft_strcat`, `ft_strncat`, `ft_strchr`, `ft_strrchr`, `ft_strdup`

### Character Checks
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

### Conversions
- `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower`

### Linked Lists (Optional)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`

---

## 🚀 Installation

Clone the repository and compile the library using the Makefile:

```bash
git clone https://github.com/M03TAHALLA/42-cursus-1337MED-.git
cd 42-cursus-1337MED-/libft
make
This will generate the libft.a file, which can be linked to your C programs.

📦 Usage
To use LIBFT in your project, include the header file and link the library during compilation:

Include the header:

c
Copier le code
#include "libft.h"
Compile with the library:

bash
Copier le code
gcc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
Run your program:

bash
Copier le code
./your_program
🗂️ Project Structure
lua
Copier le code
|-- libft/
    |-- includes/      # Header files (.h)
    |-- srcs/          # Source files (.c)
    |-- Makefile       # Build script
    |-- README.md      # This file
Makefile: Common commands:
make: Compiles the library.
make clean: Removes object files.
make fclean: Removes object files and the compiled library.
make re: Rebuilds the library from scratch.
🤝 Contributing
Contributions are welcome! If you'd like to improve this project, follow these steps:

Fork the repository
Create your feature branch (git checkout -b feature/AmazingFeature)
Commit your changes (git commit -m 'Add some AmazingFeature')
Push to the branch (git push origin feature/AmazingFeature)
Open a Pull Request
📄 License
This project is licensed under the MIT License. See the LICENSE file for more details.

👤 Author
Tahalla Mohammed
GitHub: @M03TAHALLA
<p align="center"> <b>Project Link: </b><a href="https://github.com/M03TAHALLA/42-cursus-1337MED-.git">LIBFT GitHub Repository</a> </p> ```
How to Add Icons:
The shields (icons like badges) are generated using the shields.io service.
The image logo for 42 can be directly embedded using the image URL in the <img> tag.
