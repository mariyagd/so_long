# so_long

###STEPS

#### 1. Errors management

Let's just start this project from the end to understand why the errors menagement is the very first step to do.

When you run your program, your argument is a map. You run it in this way:

```
make

./so_long map.ber
```

The map is `.ber` file which contains 1, 0, P, C, E. These are characters that indicate someting very specific:

- 1 indicates a wall or obstacle
- 0 indicates an open space
- C - collectible
- P - player
- E - exit.

The `.ber`file contains a text, each line is actually ending with a `/n`. So we can use `get_next_line()` function to tranfer each line in a string and verify if each condition of the project is ok and if there are no errors.

```
int   fd;
char  *s;

fd = open(map.ber, O_RDONLY);
s = get_next_line(fd);
```

Errors would occurs if:
- the are more or less than 1 argument
- the file is not a `.ber`extension
- the file could not be open
    --> `get_next_line()` returns `NULL`if there is `read` returns a negative value on zero, you need to close the `fd` --> `close(fd)`.

Map conditions:
- Only one exit
- Only one player
- rectangular shaped map
- At least one collectible
- 

