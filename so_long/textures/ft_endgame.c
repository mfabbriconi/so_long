/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:34:19 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/17 14:05:06 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->player[0]);
	mlx_destroy_image(game->mlx, game->images->player[1]);
	mlx_destroy_image(game->mlx, game->images->player[2]);
	mlx_destroy_image(game->mlx, game->images->player[3]);
	mlx_destroy_image(game->mlx, game->images->enemy);
	mlx_destroy_image(game->mlx, game->images->collect[0]);
	mlx_destroy_image(game->mlx, game->images->collect[1]);
	mlx_destroy_image(game->mlx, game->images->collect[2]);
	mlx_destroy_image(game->mlx, game->images->collect[3]);
	mlx_destroy_image(game->mlx, game->images->collect[4]);
	mlx_destroy_image(game->mlx, game->images->background);
	mlx_destroy_image(game->mlx, game->images->escape);
	mlx_destroy_image(game->mlx, game->images->wall);
}

void	ft_close(t_game *game)
{
	int	i;

	i = -1;
	free(game->object);
	destroy_image(game);
	free(game->images);
	while(game->map.map[++i])
		free(game->map.map[i]);
	free(game->map.map);
	free(game->vector);
	free(game->enemy_pos);
	free(game->pos_exit);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(0);
}

void	ft_win(t_game *game)
{
	if ((game->cointaken == game->object->collects)
		&& game->vector->x == game->pos_exit->x
		&& game->vector->y == game->pos_exit->y)
	{
		ft_printf("Map Completed\nStart a new game with a different map!\n");
		ft_close(game);
	}
}

int	end_game(t_game *game)
{
	ft_close(game);
	return (0);
}