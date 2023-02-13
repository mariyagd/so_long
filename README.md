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

#### 2. MiniLibX

##### 1. MiniLibX installation

- download and unzip minilibx_mms_20200219_beta.tgz and then rename the directory to "mlx". "mlx" folder must be in your working directory.
- "mlx" contains a Makefile. When you run the command "make", a **dynamic** library is created - libmlx.dylib. 
- "mlx" also contains a header file - "mlx.h" that you will be usedd further in this project.
- link your Makefile to the Makefile of mlx in order to:

1) include the directory of the "mlx.h" header file    
2) copy the libmlx.dylib to your working file.   
3) link clean and f clean commands
        
```c
.c.o:
        ${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

all:    ${NAME}

$(NAME):    ${OBJS}
        ${MAKE} -C ../libft
        ${MAKE} -C mlx/
        cp ../libft/libft.a .
        cp mlx/libmlx.dylib .
        ${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
clean:
        ${MAKE} -C ../libft clean
        ${MAKE} -C mlx/ clean
        ${RM} ${OBJS}

fclean:     clean
        ${MAKE} -C ../libft fclean
        ${MAKE} -C mlx/ clean
        ${RM} libft.a
        ${RM} llibmlx.dylib
        ${RM} ${NAME}
```
##### 1. MiniLibX man

```
man mlx/man/man3/mlx_...
```

```
