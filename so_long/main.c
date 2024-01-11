/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:30:12 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/17 13:58:15 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    inizia(t_game *game)
{
    game->object = malloc(sizeof(t_object));
    game->vector = malloc(sizeof(t_vector));
    game->pos_exit = malloc(sizeof(t_vector));
    game->enemy_pos = malloc(sizeof(t_vector));
    game->color = create_trgb(0, 0, 0, 0);
    gettimeofday(&(game->curr_tm), NULL);
    game->object->player = 0;
    game->object->collects = 0;
    game->object->escape = 0;
    game->map.col = 0;
    game->map.row = 0;
    game->counter = 0;
    game->widht = 64;
	game->height = 64;
    game->p_pov = 0;
    game->cointaken = 0;
    game->coin_frame = 0;
}

int main(int argc, char **argv)
{
    t_game	*game;
    void	*mlx;
    
    game = malloc(sizeof(t_game));
    inizia(game);
    mlx = mlx_init();
    ft_check_error(argc, argv);
    read_map(argv[1], game);
    if (check_min_requires(game) == 0)
	{
		ft_printf("Error\nSomething is missing on the map !\n");
		exit(0);
	}
    ft_check_square(game);
    check_wall(game->map.map, game->map.row);
    load_sprites(game, mlx);
    game->win = mlx_new_window(mlx, ft_strlen(game->map.map[0]) * 64,
			game->map.row * 64, "Porco Gesú");
    mlx_loop_hook(game->mlx, ft_frame, game);
    ft_preload(game);
    mlx_hook(game->win, 17, 0, end_game, game);
    mlx_hook(game->win, 2, 0, ft_key, game);
    mlx_loop(mlx);
}
