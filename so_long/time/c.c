/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:07:54 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/17 12:33:02 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

static void	ft_1_c(t_game *game)
{
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x + 1] == '0')
	{	
		//ft_printf("%d\n", 1);
		game->map.map[game->enemy_pos->y][game->enemy_pos->x + 1] = 'N';
		game->map.map[game->enemy_pos->y][game->enemy_pos->x] = '0';
	}
	game->enemy_pos->x += 1;
	game->enemy_pos->x += 1;
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x - 1] == 'P')
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(game);
	}
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x] == '1'
		|| game->map.map[game->enemy_pos->y][game->enemy_pos->x] == 'C')
	{
		game->pov_en = -1;
		//ft_printf("%d\n", game->pov_en);
	}
}

static void	ft_2_c(t_game *game)
{
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x - 1] == '0')
	{	
		game->map.map[game->enemy_pos->y][game->enemy_pos->x - 1] = 'N';
		game->map.map[game->enemy_pos->y][game->enemy_pos->x] = '0';
	}
	game->enemy_pos->x -= 1;
	game->enemy_pos->x -= 1;
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x + 1] == 'P')
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	if (game->map.map[game->enemy_pos->y][game->enemy_pos->x] == '1'
		|| game->map.map[game->enemy_pos->y][game->enemy_pos->x] == 'C')
	{
		game->pov_en = 1;
	}
}

static void	move_enemy(t_game *game)
{
	if(game->pov_en == 1)
		ft_1_c(game);
	if(game->pov_en == -1)
		ft_2_c(game);
}

int	ft_enemy(t_game *game)
{
	int	en_x;
	int	en_y;

	en_y = game->enemy_pos->y;
	en_x = game->enemy_pos->x;
	if (game->map.map[en_y][en_x] == 'P')
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	if (game->map.map[en_y][en_x + game->pov_en] != '1'
			&& game->map.map[en_y][en_x + game->pov_en] != 'C' )
		
		move_enemy(game);
	return (0);
}
