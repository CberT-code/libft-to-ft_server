#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int main(void)
{
    data_t        D;

    if ((D.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((D.mlx_win = mlx_new_window(D.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(D.mlx_ptr);
    return (EXIT_SUCCESS);
}
