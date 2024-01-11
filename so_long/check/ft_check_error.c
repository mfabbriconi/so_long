/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:13:14 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:25:29 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_error(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		return (0);
	len = ft_strlen(av[1]);
	if (!(check_ber_ext(av[1], len)))
		return (0);
	return (1);
}

int	check_ber_ext(char *av, size_t len)
{
	if (av[len - 1] == 'r' && av[len - 2] == 'e'
		&& av[len - 3] == 'b' && av[len - 4] == '.')
	{
		ft_printf("name map checked !!!\n");
		return (1);
	}
	ft_printf("name map not checked :-(\n");
	return (0);
}
void	ft_check_square(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map.row)
	{
		if (ft_strlen(game->map.map[i]) != ft_strlen(game->map.map[0]))
		{
			ft_printf("Error\nThe map that you passed is not right\n");
			exit(0);
		}
		i++;
	}
}

int	ft_check_lenline(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < count)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_wall(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	if (ft_check_lenline(map, count) == 1)
	{
		len = ft_strlen(map[0]);
		while (map[0][i] == '1' && map[count - 1][i] == '1'
			&& i < ft_strlen(map[0]))
			i++;
		if (i != ft_strlen(map[0]))
			exit(0);
		i = 0;
		while (i < count)
		{
			if (!(map[i][0] == '1' && map[i][len - 1] == '1'))
				exit(0);
			i++;
		}
		if (i != count)
			exit(0);
	}
}
