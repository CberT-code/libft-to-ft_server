
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# define CHECKER 255;

/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| R | C | F | S | EA| WE| SO| NO|
** 0 -> 4 = char **check
** 5 = int *F
** 6 = int *C
*/

typedef struct			s_info
{
	short				check_bit;
	char				**check;
	int					R[3];
	int					F[3];
	int					C[3];
}						t_info;

# endif