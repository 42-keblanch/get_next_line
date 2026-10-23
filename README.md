*This project has been created as part of the 42 curriculum by keblanch*

# Get Next Line

## Description

The goal of this project is to create a function (`get_next_line`) that reads a line from a file descriptor and returns it, using static variables.

## Instructions

### Basic usage

- Use the function `get_next_line` to read from a file descriptor.
  - The function prototype is the following: `char *get_next_line(int fd);`
  - Do not forget to include `get_next_line.h` in the files using the function.
  - Do not forget to include `get_next_line.c` and `get_next_line_utils.c` when compiling your program.
    - See [Exemple code](#exemple-code) to see the use-case

### Testing

If this project was downloaded from github, you should also be able to create a testing program.

- To run tests, run `make -C tests`
  - The resulting `test_gnl` program should display the file provided as argument.

## Ressources

[My previous attempt at 42](https://github.com/42-kblanche/get_next_line)

I used Claude to review my previous version and find ways to improve upon it

## Technical choices

The algorithm goes as follow :

- read from the file until a newline is found
- store the resulting string
- split the string after the newline to get the return string and store the leftovers in a static variable
- if there is a newline in the leftover variable when the function is called again, repeat the previous step instead of reading from file

## Exemple code

#### gnl_test.c

```C
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char    *line;
    int     fd;
    if (argc > 1)
        fd = open(argv[1], O_RDONLY);
    else
        fd = 0;
    if (fd < 0)
        return (fd);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        if (line[0] == '!' && line[1] == 'q'
            && (line[2] == '\n' || line[2] == '\0'))
        {
            free(line);
            line = NULL;
            get_next_line(-1);
        }
    }
    close(fd);
    return (0);
}
```

#### Compiling

`cc -Wall -Werror -Wextra [-D BUFFER_SIZE=1] gnl_test.c get_next_line.c get_next_line_utils.c -o gnl_test`
