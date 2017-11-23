# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 12:55:51 by cbinet            #+#    #+#              #
#    Updated: 2017/11/23 15:21:28 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -framework OpenGL -framework AppKit -lmlx # -lXext -lX11 -IGL -IGLUT 
LFLAGS = -IGL -IGLUT -lXext -lX11 -lmlx -lXext
DEBUG = -flto -ofast -o2 -Wall -Wextra -Werror
DEBUG2 = -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
CPPFLAGS = -iquote mlx -iquote includes -iquote $(LIB_PATH)$(INC)

SRC_PATH = srcs/
SRC_NAME = fdf.c move.c events.c parse.c project.c draw.c rotation.c movepoint.c autorotation.c color.c

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = includes/
LIB_PATH := libft/
LIB := $(LIB_PATH)libftprintf.a  mlx/libmlx.a
LIB_INCLUDE := $(LIB_PATH)$(INC)libft.h			\
				$(LIB_PATH)$(INC)get_next_line.h\
				$(LIB_PATH)$(INC)ft_printf.h \
				mlx/mlx.h
HEADER := $(LIB_INCLUDE)						\
		 includes/fdf.h

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(CPPFLAGS) $(LIB) $(CFLAGS)  -o $(NAME)
	@echo "\033[32m$(NAME) udpated\033[0m"

.PHONY:lib
lib:
	@make -C libft
	@make -C mlx
	
$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(LIB)
	$(CC) $(DEBUG) $(CPPFLAGS) -c $< -o $@

.PHONY:clean
clean:
	@make clean -C libft
	@make clean -C mlx
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files removed.\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[31mBinary names removed.\033[0m"

re: fclean
	make
