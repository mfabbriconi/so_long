/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:29 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:19:25 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_min_requires(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < ft_strlen(game->map.map[i]))
		{
			ft_incrementer(game, i, j);
			j++;
		}
		i++;
	}
	if (game->object->player == 1 && game->object->collects >= 1
		&& game->object->escape >= 1)
		return (1);
	return (0);
}

void	ft_incrementer(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'P')
		game->object->player++;
	else if (game->map.map[i][j] == 'C')
		game->object->collects++;
	else if (game->map.map[i][j] == 'E')
		game->object->escape++;
	else if (game->map.map[i][j] == 'N')
		game->count_en++;
	else if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0')
		exit(0);
}