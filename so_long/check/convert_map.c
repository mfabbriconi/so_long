/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:40:07 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/13 17:24:16 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_row(char *file, t_game *game)
{
	char	*line;
	
	int fd;
	game->map.row = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->map.row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	read_map(char	*file, t_game	*game)
{
	int		fd;
	char	*line;
	int		c;
	
	c = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	game->map.col = ft_strlen(line);
	count_row(file, game);
	game->map.map = malloc(sizeof(char *) * (game->map.row + 1));
	while (line)
	{
		game->map.map[c] = ft_strdup(line);
		if (game->map.map[c][ft_strlen(game->map.map[c]) - 1] == '\n')
			game->map.map[c][ft_strlen(game->map.map[c]) - 1] = '\0';
		c++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map.map[c] = 0;
	close(fd);
}