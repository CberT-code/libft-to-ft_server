# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/04/24 20:38:47 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= nasm
CFLAGS	= -fmacho64
DFLAGS	= -MD $(DEP_DIR)/$*.d

# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libasm.a
SRCS	= ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s ft_strdup.s
DEP		:= $(SRCS:%.s=$(DEP_DIR)/%.d)
OBJ 	:= $(SRCS:%.s=$(OBJ_DIR)/%.o)
DEPB	:= $(SRCB:%.s=$(DEP_DIR)/%.d)
OBJB 	:= $(SRCB:%.s=$(OBJ_DIR)/%.o)
$(NAME): $(OBJ)
	ar -rcs $@ $^
	ranlib $@
	gcc  main.c $@ | ./a.out

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.s | $(DIR)
	$(CC) $(CFLAGS) $< -o $@ $(DFLAGS)

-include $(DEP)

.PHONY: all clean fclean re
