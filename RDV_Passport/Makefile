# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/02/18 23:42:05 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= alarm_rdv.c

LIBFT		= libft/libft.a

NAME		= rdv_passport

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	
			make re -C libft
			make clean -C libft
			gcc $(CLFAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) 04/03 12\03

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
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

all:		${NAME}

re:			clean
			gcc $(CLFAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) 04/03 12\03

.PHONY:		all clean fclean re re2 re3 libft
