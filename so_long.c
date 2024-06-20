/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:12:11 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/19 18:45:52 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_var(t_game *game)
{
	game->collectible = 0;
	game->collected = 0;
	game->exit = 0;
	game->character = 0;
	game->step = 0;
	game->path.visited = 0;
	game->path.valid_path = 0;
	game->path.char_x = 0;
	game->path.char_y = 0;
	game->path.char_xy = 0;
	game->path.collected = 0;
}

int	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * 15, game->map.height * 15, "so_long",
			false);
	if (!(game->mlx))
		return (1);
	start_image(game);
	set_map(game);
	mlx_key_hook(game->mlx, key_handler, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->map.line);
	free(game->texture);
	free(game->image);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc == 2)
	{
		start_var(game);
		get_map(argv[1], game);
		check_dim(game);
		check_components(game);
		path_checker(game);
		start_game(game);
	}
	else
		error_handler("Please specify a map");
	return (0);
}
