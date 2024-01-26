# 42 - get_next_line
This is a very simple yet useful project that we will use later on the common core of 42. The goal of this project is to create a `char *get_next_line(int fd)` function that must read and return one line from the specified file descriptor (fd).

One important note is that this an every single C project I made for the 42 cursus is coded, compiled and tested on macOS Catalina (The OS provided at our campus). While the code itself uses standard functions and pure C logic, the project hasn't been tested and may not work on other platforms. This is expected and is not planned to be solved.

<div align=center>
<a href="https://www.codefactor.io/repository/github/xdec0de/42get_next_line"><img src="https://www.codefactor.io/repository/github/xdec0de/42get_next_line/badge" alt="CodeFactor"/></a>
<a href="https://app.codacy.com/gh/xDec0de/42get_next_line"><img src="https://app.codacy.com/project/badge/Grade/10f45c9430f540c2aca9ec4f0df218ff" alt="Codacy"/></a>
</div>

## Project instructions
First, let's see the general instructions that apply to get_next_line:
-   The function must never crash nor have undefined behavior.
-   The only functions allowed to use are `read`, `malloc` and `free`.
-   The code must be written following [norminette](https://github.com/42School/norminette) requirements.
-   Memory leaks are an issue, so no leaks are allowed, even if the function fails.

Now, the specific instructions for get_next_line:
-   We can only create the following files: get_next_line.(c/h) and get_next_line_utils.c
-   Under normal circumstances, get_next_line must return the next line written on the file corresponding to the
-   `NULL` must be returned if get_next_line fails or reaches the end of a file.
-   Global variables are forbidden.
-   The use of [libft](https://github.com/xDec0de/42libft) is forbidden. This limits the amount of utility functions we can use, as we are asked to provide only two .c files and [norminette](https://github.com/42School/norminette) only allows 5 functions per file with a maximum of 25 lines of code for each function.

## What I learned
The most obvious thing everyone learns by doing this project is the purpose of the `static` keyword as well as the concept of file descriptors and how to read files in C.

## About the macros
After some research I found out that there is a limit on how many files a process can open. This is specified on `sys/limits.h` with the `OPEN_MAX` macro, `FD_MAX` is limited and defaults to that value. `BUFFER_SIZE` defaults to `BUFSIZ`, provided by `stdio.h`, but has a minimum value of 1 and a maximum value of 1000000.