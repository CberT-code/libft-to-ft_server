# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/01/20 18:49:28 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= parsing.c parsing_elem.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= libft

NAME_LIBFT	= libft.a

NAME		= cub3d.a

RM			= rm -f

CC			= gcc

CFLAGS		= -I includes -Wall -Wextra -Werror

all:		${NAME}

${NAME}:    ${OBJS}
			@make -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
clean:      
			@make -C $(LIBFT) clean
			${RM} ${OBJS}

fclean:		clean
			cd ${LIBFT} && ${RM} ${NAME_LIBFT}
			${RM} ${NAME}

re:			fclean all
.PHONY:		all clean fclean re
