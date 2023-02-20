# so_long

<details><summary> 

### 1. Errors management

</summary> 

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
 
</details>

---

<details><summary> 

### 2. MiniLibX

</summary> 

MiniLibX provides simple window creation, a drawing tool, image and basic events management.
mlx.h should be included for a correct use of the MiniLibX API.

All other MiniLibX functions are described in the following man pages:

       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

       mlx_new_image       : manipulate images

       mlx_loop            : handle keyboard or mouse events 

</details>

---

<details><summary>

### 3. MiniLibX installation

</summary> 

<details><summary> 

#### 3.1. Link your Makefile to the Makefile of mlx and add the frameworks

</summary>

---
```c
libft/libft.a:
        ${MAKE} -C ../libft

mlx/libmlx.a:
        ${MAKE} -C mlx/

${NAME}:    ${OBJS} mlx/libmlx.a libft/libft.a
        ${CC} ${CFLAGS} -framework OpenGL -framework AppKit -lz -o ${NAME} ${OBJS} ../libft/libft.a mlx/libmlx.a
```
</details>


<details><summary>

#### 3.2. Initialize the connection between your software and the  display.

</summary>

---
Once  this  connection  is established, you'll be able to use other MiniLibX functions to send and receive the messages from  the  display. The mlx_init function will create this connection. No parameters are  needed, ant it will return a void * identifier, used for further calls to the library routines.

```c
       #include <mlx.h>

       void *
       mlx_init ();
```
</details>


<details><summary>

#### 3.3. Errors management of `mlx_init()`

</summary>

---

If mlx_init() fails to set up the connection to the display, it will return NULL,  otherwise a non-null pointer is returned as a connection identifier.
</details>


<details><summary>

#### 3.4. Create a window on the screen

</summary>

---
`  void     *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );`

This function creates a new window to the screen and return a `void *` identifier that can be used from othe MiniLibX calls.

- The `mlx_ptr` parameter is the connection identifier returned by `mlx_init()`
- `size_x` and `size_y` determines the size of the windows. You shoud adjust size_x and size_y to the size of your images.
- `title` is the text displayed on in the window's title bar.

For example if your map has `size_x = 14` and `size_y = 7` as shown below and all sprites are 64 pixels, and the title is "so_long" then the parameters become. I store the pointers directly in my structure.

*exemple*
```
11111111111111
10000000000001
100000C0000001
100C00P00C0001
100C00000C0001
100C00000CE001
11111111111111
```

```c
#include "mlx.h"

t_data  list;

list.mlx_ptr = init_mlx();
list.win_ptr = mlx_new_window(list.mlx_ptr, 14 * 64, 7 * 64, "so_long")
mlx_loop(list.mlx_ptr);
```

The result is a window with the size of the map considering the size of each image:

<img width="1008" alt="Screen Shot 2023-02-20 at 1 46 16 PM" src="https://user-images.githubusercontent.com/109855801/220112258-edc62dd4-c016-463d-ac12-c862e3bb794e.png">


</details>

<details><summary>

#### 3.4. Errors management of `mlx_new_window()`

</summary>

---
If `mlx_new_window()` fails to create a new window (for wathever reason), it will return NULL, otherwise  a  non-null  pointer  is  returned  as  a  window   identifier

</details>

<details><summary>

#### 3.5. Create pointers to your .xpm files

</summary>

---
In my project, I choosed to work with .xpm files. Firstly, I choosed images for my map, converted them to .xpm files. Then I set pointers to them with `mlx_xpm_file_to_image()`.

Here is how I did it:

- Choose images for your map - an image for wall, open space, player, collectible and exit.
- Reduce the pixel size and use the same size for every image. For example: 54 pixels per 54 pixels.
- Put all the .xm files in a folder (I named to folder "sprites").
- Convert your images to .xpm [Learn more about .xpm files.](https://www.fileformat.info/format/xpm/egff.htm)

In this structure, I have stored all the necessary variables for the completion of this project.
Five of these variables correspond to each element of the map:

```c
typedef struct  s_data
{
    ...
    void        *wall;
    void        *open_sp;
    void        *collect;
    void        *player;
    void        *exit;
    ...
}               t_data;
```

The function `void    *mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );` creates a new image in memory and fill it using the specified xpm_data.

- The function returns a `void  *` identifier needed to manipulate this image later.
- The function stores the width and the height of the image in, respectively, `int *width` and `int *height`. As in my project, all the images has the same size (64 pixels per 64 pixels) I use only two int where I store the same data - `int h` and `int w`.

Here is how my function looks (all my images are in the folder called `sprites/`). I called this function while initializing my structure.

```c
void    init_list_image(t_data *list)
{
    int h;
    int w;

    list->wall = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/wall.xpm", &w, &h);
    list->open_sp = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/open_sp.xpm", &w, &h);
    list->collect = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/collect.xpm", &w, &h);
    list->player = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/player.xpm", &w, &h);
    list->exit = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/exit.xpm", &w, &h);
}
```

</details>

#### 3.6. Errors management of `mlx_xpm_file_to_image()`

</summary>

---
`mlx_xpm_file_to_image()` will return NULL if an error occurs. Otherwise they return a non-null pointer as an image identifier

</details>

<details><summary>

#### 3.7. Put images to your windows

</summary>

---
I used `mlx_put_image_to_window()` to dump the images inside to the window.

`int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );`

where:
- `void *mlx_ptr` specifies the connection to the display. This is the pointer returned by `init_mlx()`.
- `void *win_ptr` specifies the window where you dump the images. This the pointer returned by `mlx_new_window()`.
- `void *img_ptr` specifies the pointer to the image that you want to dump. (this is the pointer returned by `mlx_xpm_file_to_image()`
- `int x` and `int y` are the coordinates where the image should be placed times the size of the image (in my project 64 pixel per 64 pixels).

This is how my function works. For better understanding, in this example I use `char **array` but in reality this array should the stored int your structure.

```
11111111111111
10000000000001
100000C0000001
100C00P00C0001
100C00000C0001
100C00000CE001
11111111111111
```

```c
void    put_image_to_window(char **array)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (array[y] != NULL)
    {
        j = 0;
        while (array[i][j] != '\0')
        {
            mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, j * 64, i * 64);
            if (list->map[i][j] == '1')
                mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->wall, j * 64, i * 64);
            else if (list->map[i][j] == '0')
                mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, j * 64, i * 64);
            else if (list->map[i][j] == 'C')
                mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->collect, j * 64, i * 64);
            else if (list->map[i][j] == 'P')
                mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, j * 64, i * 64);
            else if (list->map[i][j] == 'E')
                mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->exit, j * 64, i * 64);
            j++;
        }
    }
}
```

</details>

<details><summary>

#### 3.7. Events

</summary>

---

The  graphical  system  is bi-directionnal. On one hand, the program sends orders to the screen to display pixels, images, and so on. On  the  other  hand,  it  can  get information from the keyboard and mouse associated to the screen. To do so, the program receives "events" from the keyboard or the mouse.
 


</details>
</details>
