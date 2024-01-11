/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:00:06 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/17 12:53:59 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_coin(t_game *game)
{
	game->coin_frame++;
	if(game->coin_frame == 5)
		game->coin_frame = 0;
}

int	ft_gettimestamp(t_game *game)
{
	struct timeval	now;
	int				res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((game->curr_tm.tv_sec * 1000) + (game->curr_tm.tv_usec / 1000)));
	if (res >= 200)	
		game->curr_tm = now;
	return (res);
}

int	ft_frame(t_game *game)
{
	if (ft_gettimestamp(game) >= 200)
	{
		if (game->count_en > 0)
			ft_enemy(game);
		ft_coin(game);
		ft_reload(game);
	}
	if ((game->count_en > 0) && game->enemy_pos->x == game->vector->x
		&& game->enemy_pos->y == game->vector->y)
	{
		ft_printf("SLAYED BY SKELETON\n");
		ft_close(game);
	}
	return (0);
}