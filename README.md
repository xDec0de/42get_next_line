# 42 - get_next_line - Grade: 125/125

This is a very simple yet useful project that we will use later on the
common core of 42. The goal of this project is to create a
`char *get_next_line(int fd)` function that must read and return one line
from the specified file descriptor (fd).

One important note is that this project is coded, compiled and tested on
Linux and WSL, Ubuntu on both. While the code itself uses standard functions
and pure C, the project hasn't been tested and may not work on other platforms.
This is expected and is not planned to be solved.

<div align=center>
<a href="https://www.codefactor.io/repository/github/xdec0de/42get_next_line"><img src="https://www.codefactor.io/repository/github/xdec0de/42get_next_line/badge" alt="CodeFactor"/></a>
<a href="https://app.codacy.com/gh/xDec0de/42get_next_line"><img src="https://app.codacy.com/project/badge/Grade/10f45c9430f540c2aca9ec4f0df218ff" alt="Codacy"/></a>
</div>

## Project instructions

First, let's see the general instructions that apply to get_next_line:
-   The function must never crash nor have undefined behavior.
-   The only functions allowed to use are `read`, `malloc` and `free`.
-   The code must be written following
[norminette](https://github.com/42School/norminette) requirements.
-   Memory leaks are an issue, so no leaks are allowed.

Now, the specific instructions for get_next_line:
-   We can only create the following files: get_next_line.(c/h) and
get_next_line_utils.c
-   Under normal circumstances, get_next_line must return the next
line written on the file corresponding to the
-   `NULL` must be returned if get_next_line fails or reaches the
end of a file.
-   Global variables are forbidden.
-   The use of [libft](https://github.com/xDec0de/42libft) is forbidden.
This limits the amount of utility functions we can use, as we are asked
to provide only two .c files and
[norminette](https://github.com/42School/norminette) only allows 5 functions
per file with a maximum of 25 lines of code for each function.

# About malloc_ver

As explained bellow on "about the macros", a malloc buffer version is
included to avoid redefining the BUFFER_SIZE macro. This has its pros and
cons, that's the reason why the two versions are kept. As you can tell, I
prefer the macro redefinition approach. This is because, while the malloc
buffer allows to have a bigger buffer, malloc may in some very specific
situations fail, plus you have to free the buffer. Macro redefinition on
the other hand doesn't respect what the end user wants, which is to use
a huge buffer. Instead, it tricks the user and uses a smaller one. I don't
think this is a real issue though, because, who uses a buffer higher than
8MB to read a file? Is this feature really needed? At that point, relying
on malloc, to me, offers little real advantage over possible real problems.
At the end of the day, the program that grades get_next_line won't check if
you redefine the BUFFER_SIZE macro, so it's really a matter of choice.

## What I learned

The most obvious thing everyone learns by doing this project is the purpose of
the `static` keyword as well as the concept of file descriptors and how to
read files in C.

## About the macros

After some research I found out that there is a limit on how many files a
process can open. This is specified on `stdio.h` with the `FOPEN_MAX` macro,
`FD_MAX` is limited and defaults to that value. `BUFFER_SIZE` defaults to
`BUFSIZ`, also provided by `stdio.h`. The get_next_line version found at the
malloc_ver folder doesn't contain limits for this macro, while the one at the
root of the project does, this second limit is **required** in order to avoid
stack overflows, because the maximum stack size is 8MB, so actually 8388608
bytes.
