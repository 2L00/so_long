# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abddahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 18:39:15 by abddahma          #+#    #+#              #
#    Updated: 2025/02/24 18:22:30 by abddahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =   advance_info.c  copy_map.c      exit_hook.c     flood_fill.c    freeing.c \
        ft_memmove.c    ft_mlx.c        ft_split.c      get_next_line.c get_next_line_utils.c \
        info_map.c      map_hight.c     map_len.c       map_to_str.c    move_player.c   so_long.c \
        no_collectebel.c        other_info.c    return_door.c   wall_map.c ft_putnbr_fd.c valid_len.c

FT_PRINTF_SRC = ft_pointer.c ft_printf.c ft_putchar.c \
                ft_putnbr.c ft_putstr.c ft_putnbr_hexa_upper.c \
                ft_putnbr_unsigned.c ft_putnbr_hexa_lower.c

OBJ = $(SRC:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(OBJ) $(FT_PRINTF_OBJ) $(MLX) -o $@

clean:
		@rm -f $(OBJ) $(FT_PRINTF_OBJ) $(*.d)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ) $(FT_PRINTF_OBJ)

.PHONY: all clean fclean re
