/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:19 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/24 18:22:04 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct map
{
	int		move;

	int		hight_map;
	int		len_map;
	int		player;
	int		collectible;
	int		exit;
	int		wall;
	int		space;

	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		w_x;
	int		w_y;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_door;
	void	*img_player;
	void	*img_coin;
	void	*img_space;
	char	**str;

}			t_MAP;

void		freeing(char *s, char **str);
void		copy_map(char *s, char *str);
void		wall_map(char **str, int hight_map, size_t len_map);
size_t		map_hight(char *av);
size_t		map_len(char *av);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		**ft_split(const char *s);

void		info_map(char **av);
char		**map_to_str(char *av, size_t hight_map, size_t len_map);
void		other_info(char *av);
void		advance_info(char *av, t_MAP *map);
void		flood_fill(char *av, char **str, t_MAP *map);
void		ft_free_fill(char **str, int i);

void		ft_mlx(char **str, t_MAP *map);
void		move_player(int key, t_MAP *map);
void		place_element(t_MAP *map);
void		return_door(t_MAP *map, int x);
int			no_collectebel(t_MAP *map);
int			out(t_MAP *map, int y, int x, int key);
int			exit_hook(t_MAP *map);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

void		valid_len(char *av);

#endif
