/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:05:47 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/05 17:55:38 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_right(t_game *game)
{
	if (game->map.map[game->vector->y][game->vector->x + 1] == 'C'
			|| game->map.map[game->vector->y][game->vector->x + 1] == '0')
	{
		if (game->map.map[game->vector->y][game->vector->x + 1] == 'C')
			game->cointaken++;
		game->map.map[game->vector->y][game->vector->x + 1] = 'P';
		game->map.map[game->vector->y][game->vector->x] = '0';
		game->counter++;
	}
	else if (game->map.map[game->vector->y][game->vector->x + 1] == 'E')
	{
		if (game->cointaken == game->object->collects)
		{
			game->map.map[game->vector->y][game->vector->x + 1] = 'P';
			game->map.map[game->vector->y][game->vector->x] = '0';
		}
	}
	else if (game->map.map[game->vector->y][game->vector->x + 1] == 'N' )
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	game->p_pov = 1;
}

void	ft_move_left(t_game *game)
{
	if (game->map.map[game->vector->y][game->vector->x - 1] == 'C'
			|| game->map.map[game->vector->y][game->vector->x - 1] == '0')
	{
		if (game->map.map[game->vector->y][game->vector->x - 1] == 'C')
			game->cointaken++;
		game->map.map[game->vector->y][game->vector->x - 1] = 'P';
		game->map.map[game->vector->y][game->vector->x] = '0';
		game->counter++;
	}
	else if (game->map.map[game->vector->y][game->vector->x - 1] == 'E')
	{
		if (game->cointaken == game->object->collects)
		{
			game->map.map[game->vector->y][game->vector->x - 1] = 'P';
			game->map.map[game->vector->y][game->vector->x] = '0';
		}
	}
	else if (game->map.map[game->vector->y][game->vector->x - 1] == 'N' )
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	game->p_pov = 2;
}

void	ft_move_up(t_game *game)
{
	if (game->map.map[game->vector->y + 1][game->vector->x] == 'C'
			|| game->map.map[game->vector->y + 1][game->vector->x] == '0')
	{
		if (game->map.map[game->vector->y + 1][game->vector->x] == 'C')
			game->cointaken++;
		game->map.map[game->vector->y + 1][game->vector->x] = 'P';
		game->map.map[game->vector->y][game->vector->x] = '0';
		game->counter++;
	}
	else if (game->map.map[game->vector->y + 1][game->vector->x] == 'E')
	{
		if (game->cointaken == game->object->collects)
		{
			game->map.map[game->vector->y + 1][game->vector->x] = 'P';
			game->map.map[game->vector->y][game->vector->x] = '0';
		}
	}
	else if (game->map.map[game->vector->y + 1][game->vector->x] == 'N' )
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	game->p_pov = 3;
}

void	ft_move_down(t_game *game)
{
	if (game->map.map[game->vector->y - 1][game->vector->x] == 'C'
			|| game->map.map[game->vector->y - 1][game->vector->x] == '0')
	{
		if (game->map.map[game->vector->y - 1][game->vector->x] == 'C')
			game->cointaken++;
		game->map.map[game->vector->y - 1][game->vector->x] = 'P';
		game->map.map[game->vector->y][game->vector->x] = '0';
		game->counter++;
	}
	else if (game->map.map[game->vector->y - 1][game->vector->x] == 'E')
	{
		if (game->cointaken == game->object->collects)
		{
			game->map.map[game->vector->y][game->vector->x] = 'P';
			game->map.map[game->vector->y - 1][game->vector->x] = '0';
			game->counter++;
		}
	}
	else if (game->map.map[game->vector->y - 1][game->vector->x] == 'N')
	{
		game->counter++;
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	game->p_pov = 0;
}

int	ft_key(int kc, t_game *game)
{
	int	x;
	int	y;
	
	x = game->vector->x;
	y = game->vector->y;
	if (kc == 53 || kc == 124 || kc == 123 || kc == 125 || kc == 126)
	{
		if (kc == 53)
			ft_close(game);
		else if (kc == 124)
			ft_move_right(game);
		else if (kc == 123)
			ft_move_left(game);
		else if (kc == 125)
			ft_move_up(game);
		else if (kc == 126)
			ft_move_down(game);
		ft_reload(game);
	}
	ft_win(game);
	return (0);
}
