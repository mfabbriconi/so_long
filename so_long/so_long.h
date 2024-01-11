/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:30:30 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:45:48 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "getnextline/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <zlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_object {
	int	player;
	int	collects;
	int	escape;
}				t_object;

typedef struct s_map {
	char 	**map;
	int		col;
	int		row;
}			t_map;

typedef struct s_textures {
	void	*background;
	void	*wall;
	void	*escape;
	void	*player[4];
	void	*enemy;
	void	*collect[5];
}				t_textures;

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_game {
	void			*mlx;
	void			*win;
	void			*init;
	t_map			map;
	t_textures		*images;
	t_object		*object;
	t_vector		*vector;
	t_vector		*enemy_pos;
	t_vector		*pos_exit;
	int				widht;
	int				height;
	int				count_en;
	int				cointaken;
	struct timeval	curr_tm;
	int				p_pov;
	int				counter;
	int				color;
	int				index;
	int				pov_en;
	int				coin_frame;
}			t_game;

int 	main(int argc, char **argv);
void	read_map(char	*file, t_game	*game);
char	*ft_strdup(char *s);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	ft_preload(t_game *game);
void	ft_load_img(t_game *game, int j, int i);
int		ft_check_error(int ac, char **av);
int		check_ber_ext(char *av, size_t len);
void	ft_incrementer(t_game *game, int i, int j);
int		check_min_requires(t_game *game);
void	ft_check_square(t_game *game);
void	check_wall(char **map, int count);
void	load_sprites(t_game *game, void *mlx);
void	load_player(t_game *game);
int		ft_key(int kc, t_game *game);
void	ft_reload(t_game *game);
void	put_sprite_1_0_E(t_game *game, int i, int j);
void	put_sprite_P_C_N(t_game *game, int i, int j);
void	ft_close(t_game *game);
void	ft_win(t_game *game);
int		end_game(t_game *game);
int		ft_frame(t_game *game);
int		ft_enemy(t_game *game);
void	ft_load_enemy(t_game *game);
int		create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b);

#endif