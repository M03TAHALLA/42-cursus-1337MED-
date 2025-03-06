
# Pipex Project

## Description

The Pipex project at 42 is a C programming project that involves creating a command-line program that simulates the behavior of a shell pipeline using file descriptors and system calls. The program takes multiple commands and processes them, chaining them with pipes in a manner similar to how pipes work in a shell.

## Project Objective

The goal of the Pipex project is to implement the piping mechanism in C, working with low-level system calls such as `fork()`, `execve()`, `pipe()`, and `dup2()`. It should support reading from files and using multiple commands with pipes to pass data between them.

## Features

- Simulates shell pipes (`|`) by creating processes.
- Allows reading from files, executing commands, and writing to a new file.
- Handles standard error and exit codes appropriately.
- Works with multiple pipes and commands.

## How to Compile

To compile the project, run the following command:

```bash
make
```

This will create the executable file `pipex`.

## Usage

The program accepts the following syntax:

```bash
./pipex infile cmd1 cmd2 ... outfile
```

Where:
- `infile` is the file to read from.
- `cmd1, cmd2, ...` are the commands to be executed in sequence.
- `outfile` is the file to write the final output to.

### Example:

```bash
./pipex file1 "cat" "grep hello" file2
```

This command will:
1. Open `file1` for reading.
2. Run `cat` on the content of `file1`.
3. Pass the result to `grep hello`, which filters lines containing "hello".
4. Write the output to `file2`.

## Testing

To test the program, you can use the following example commands:

```bash
make bonus
./pipex input.txt "cat" "sort" output.txt
```

## Requirements

- The project must be written in C and follow the standard C library.
- You must use `fork()`, `execve()`, `pipe()`, and `dup2()` to implement the logic.
- Handle errors gracefully and use appropriate system calls.

## Score

- **Final Score**: 115/125

## Authors

- **Tahalla Mohammed** - Developer at 1337Med

## License

This project is licensed under the MIT License.
