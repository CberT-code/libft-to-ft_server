# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/01/27 15:08:46 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= main_test.c parsing.c parsing_elem.c error_free.c full_map.c

LIBFT		= libft/libft.a

NAME		= cub3d

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	$(LIBFT)
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) test.cub

libft:
		make re -C libft
		make clean -C libft

clean:      
		make clean -C libft
		rm -f $(NAME)

fclean:
			make fclean -C libft
			rm -f ${NAME}

git:		fclean
			git add *
			git commit -m "$(LOGFILE) $(MSG)"
			git push

all:		${NAME}

re:			clean all

.PHONY:		all clean fclean re libft
