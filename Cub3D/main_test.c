#include "minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int		click_mouse(int key)
{
	char  i;

	i = key + '0';
	write(1,&i,1);
	return (0);
}

int	destroy()
{
	exit(0);
	return (0);
}

int main(void)
{
    data_t        data;

    if (!(data.mlx_ptr = mlx_init()))
        return (EXIT_FAILURE);
	if (!(data.mlx_win = mlx_new_window(data.mlx_ptr, 1400, 720, "CUB3D")))
       return (EXIT_FAILURE);
	mlx_mouse_hook (data.mlx_win, click_mouse, NULL);
	mlx_hook(data.mlx_win, 17, 0, destroy, NULL);
	mlx_loop(data.mlx_ptr);
}
