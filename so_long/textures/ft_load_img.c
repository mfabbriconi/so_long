/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:49:40 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:50:32 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_player(t_game *game)
{
	game->images->player[0] = mlx_xpm_file_to_image(game->mlx,
		"sprite/kn_U.xpm", &game->widht, &game->height);
	game->images->player[1] = mlx_xpm_file_to_image(game->mlx,
		"sprite/kn_R.xpm", &game->widht, &game->height);
	game->images->player[2] = mlx_xpm_file_to_image(game->mlx,
		"sprite/kn_L.xpm", &game->widht, &game->height);
	game->images->player[3] = mlx_xpm_file_to_image(game->mlx,
		"sprite/kn_D.xpm", &game->widht, &game->height);
}

void	load_coin(t_game *game)
{
	game->images->collect[0] = mlx_xpm_file_to_image(game->mlx,
		"sprite/Coin.xpm", &game->widht, &game->height);
	game->images->collect[1] = mlx_xpm_file_to_image(game->mlx,
		"sprite/Coin1.xpm", &game->widht, &game->height);
	game->images->collect[2] = mlx_xpm_file_to_image(game->mlx,
		"sprite/Coin2.xpm", &game->widht, &game->height);
	game->images->collect[3] = mlx_xpm_file_to_image(game->mlx,
		"sprite/Coin3.xpm", &game->widht, &game->height);
	game->images->collect[4] = mlx_xpm_file_to_image(game->mlx,
		"sprite/Coin4.xpm", &game->widht, &game->height);
}

void	load_sprites(t_game *game, void *mlx)
{
	game->images = malloc(sizeof(t_textures));
	game->widht = 64;
	game->height = 64;
	game->mlx = mlx;
	game->pov_en = 1;
	game->images->enemy = mlx_xpm_file_to_image(game->mlx,
		"sprite/en_D.xpm", &game->widht, &game->height);
	game->images->background = mlx_xpm_file_to_image(mlx,
		"sprite/Path.xpm", &game->widht, &game->height);
	game->images->wall = mlx_xpm_file_to_image(mlx,
		"sprite/Wall.xpm", &game->widht, &game->height);
	game->images->escape = mlx_xpm_file_to_image(mlx,
		"sprite/Exit.xpm", &game->widht, &game->height);
	load_player(game);
	load_coin(game);
}

void	put_sprite_1_0_E(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->images->wall, 64 * j, 64 * i);
	else if (game->map.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->images->background, 64 * j, 64 * i);
	else if (game->map.map[i][j] == 'E')
	{
		game->pos_exit->x = j;
		game->pos_exit->y = i;
		mlx_put_image_to_window(game->mlx, game->win, game->images->background, 64 * j, 64 * i);
		mlx_put_image_to_window(game->mlx, game->win, game->images->escape, 64 * j, 64 * i);
	}
}

void	put_sprite_P_C_N(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'P')
	{
		game->vector->x = j;
		game->vector->y = i;
		mlx_put_image_to_window(game->mlx, game->win, game->images->background, 64 * j, 64 * i);
		mlx_put_image_to_window(game->mlx, game->win, game->images->player[game->p_pov], 64 * j, 64 * i);
	}
	else if (game->map.map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images->background, 64 * j, 64 * i);
		mlx_put_image_to_window(game->mlx, game->win, game->images->collect[game->coin_frame], 64 * j, 64 * i);
	}
	else if (game->map.map[i][j] == 'N')
	{
		game->enemy_pos->x = j;
		game->enemy_pos->y = i;
		mlx_put_image_to_window(game->mlx, game->win, game->images->background, 64 * j, 64 * i);
		mlx_put_image_to_window(game->mlx, game->win, game->images->enemy, 64 * j, 64 * i);
	}
}

void	ft_preload(t_game *game)
{
	int		i;
	int		j;
	
	i = 0;
	while(i < game->map.row)
	{
		j = 0;
		while(j < game->map.col)
		{
			if (game->map.map[i][j] == '1' || game->map.map[i][j] == '0'
				|| game->map.map[i][j] == 'E')
				put_sprite_1_0_E(game, i, j);
			else if (game->map.map[i][j] == 'P' || game->map.map[i][j] == 'C'
				|| game->map.map[i][j] == 'N')
				put_sprite_P_C_N(game, i, j);
			j++;
		}
		i++;
	}
}
