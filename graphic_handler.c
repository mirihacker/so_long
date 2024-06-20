/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:35:43 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/19 17:52:36 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_image(t_game *game)
{
	game->texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		error_handler("Failed to allocate textures");
	game->texture->blank = mlx_load_png("./images/blank.png");
	game->texture->character = mlx_load_png("./images/character.png");
	game->texture->collectible = mlx_load_png("./images/collectible.png");
	game->texture->exit = mlx_load_png("./images/exit.png");
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!game->image)
		error_handler("Failed to allocate images");
	game->image->blank = mlx_texture_to_image(game->mlx, game->texture->blank);
	game->image->character = mlx_texture_to_image(game->mlx,
			game->texture->character);
	game->image->collectible = mlx_texture_to_image(game->mlx,
			game->texture->collectible);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	mlx_delete_texture(game->texture->blank);
	mlx_delete_texture(game->texture->character);
	mlx_delete_texture(game->texture->collectible);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->wall);
}

void	set_image(t_game *game, int w, int h)
{
	if (game->map.line[w + (h * game->map.width)] == '1')
		mlx_image_to_window(game->mlx, game->image->wall, w * 15, h * 15);
	else if (game->map.line[w + (h * game->map.width)] == 'C')
		mlx_image_to_window(game->mlx, game->image->collectible, w * 15, h
			* 15);
	else if (game->map.line[w + (h * game->map.width)] == 'E')
		mlx_image_to_window(game->mlx, game->image->exit, w * 15, h * 15);
	else if (game->map.line[w + (h * game->map.width)] == 'P')
	{
		game->path.char_x = w;
		game->path.char_y = h;
		game->path.char_xy = w + (h * game->map.width);
		mlx_image_to_window(game->mlx, game->image->character, w * 15, h * 15);
	}
	else
		mlx_image_to_window(game->mlx, game->image->blank, w * 15, h * 15);
}

void	set_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			set_image(game, width, height);
			width++;
		}
		height++;
	}
}
