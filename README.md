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

So before you even start your project you should create a function that will verify if your map doesn't have error. As the `.ber`file contains a text, each line is actually ending with a `/n`. So we can you `get_next_line()`function to tranfer each line in a string and verify if each condition of the project is ok and if there are no errors.

