# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 12:55:51 by cbinet            #+#    #+#              #
#    Updated: 2017/12/14 13:15:52 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
MLX= mlx
CPPFLAGS = -iquote $(MLX) -iquote includes -iquote $(LIB_PATH)$(INC)
#ifdef __unix__
MLX=minilibx
CFLAGS = -IGL -IGLUT -lXext -lX11 -lm
#else
MLX=mlx
CFLAGS = -framework OpenGL -framework AppKit -lmlx #-lXext -lX11
#endif

SRC_PATH = srcs/
SRC_NAME = fdf.c move.c events.c parse.c project.c draw.c rotation.c \
		   movepoint.c autorotation.c color.c camera.c drawaccessor.c getcolor.c

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
	SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
	OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
	INC = includes/
	LIB_PATH := libft/
	LIB := $(LIB_PATH)libftprintf.a  $(MLX)/libmlx.a
	LIB_INCLUDE := $(LIB_PATH)$(INC)libft.h			\
		$(LIB_PATH)$(INC)get_next_line.h\
		$(LIB_PATH)$(INC)ft_printf.h \
		$(MLX)/mlx.h
	HEADER := $(LIB_INCLUDE)						\
		includes/fdf.h

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(CPPFLAGS) $(LIB) $(CFLAGS)  -o $(NAME)
	@echo "\033[32m$(NAME) udpated\033[0m"

.PHONY:lib
lib:
	@make -C libft
	@make -C $(MLX)

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(LIB)
	$(CC) $(DEBUG) $(CPPFLAGS) -c $< -o $@

.PHONY:clean
clean:
	@make clean -C libft
	@make clean -C $(MLX)
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files removed.\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[31mBinary names removed.\033[0m"

re: fclean
	make
