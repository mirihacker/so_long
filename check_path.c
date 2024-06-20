/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:17:56 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/19 17:52:18 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(int x, int y, t_game *game)
{
	int			new_x;
	int			new_y;
	int			i;
	const int	step_x[4] = {1, 0, 0, -1};
	const int	step_y[4] = {0, 1, -1, 0};

	game->path.visited[x + (y * game->map.width)] = '1';
	if (game->map.line[x + (y * game->map.width)] == 'C')
		game->path.collected--;
	if (game->map.line[x + (y * game->map.width)] == 'E')
	{
		game->path.valid_path = 1;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		new_x = x + step_x[i];
		new_y = y + step_y[i];
		if (game->map.line[new_x + (new_y * game->map.width)] != '1'
			&& game->path.visited[new_x + (new_y * game->map.width)] != '1'
			&& new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height)
			valid_path(new_x, new_y, game);
	}
}

void	find_character(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			if (game->map.line[width + (height * game->map.width)] == 'P')
			{
				game->path.char_x = width;
				game->path.char_y = height;
				game->path.char_xy = width + (height * game->map.width);
			}
			width++;
		}
		height++;
	}
}

void	path_checker(t_game *game)
{
	int	len;

	len = ft_strlen(game->map.line);
	game->path.visited = (char *)malloc(len);
	if (!game->path.visited)
		error_handler("Allocation failed");
	ft_memset(game->path.visited, '0', sizeof(char) * len);
	game->path.collected = game->collectible;
	find_character(game);
	valid_path(game->path.char_x, game->path.char_y, game);
	free(game->path.visited);
	if (game->path.valid_path != 1 || game->path.collected != 0)
		error_handler("Path not valid");
}
