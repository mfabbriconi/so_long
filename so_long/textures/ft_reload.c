/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:14:38 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:46:13 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_reload(t_game *game)
{
	int		i;
	int		j;
	char 	*string;
	
	i = 0;
	string = ft_itoa(game->counter);
	while(i < game->map.row)
	{
		j = 0;
		while(j < game->map.col)
		{
			if (game->map.map[i][j] == '1' || game->map.map[i][j] == '0')
				put_sprite_1_0_E(game, i, j);
			else if (game->map.map[i][j] == 'P' || game->map.map[i][j] == 'E' ||
			
				game->map.map[i][j] == 'C' || game->map.map[i][j] == 'N')
				put_sprite_P_C_N(game, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(game->mlx, game->win, 20, 20, game->color, string);
	free(string);
}