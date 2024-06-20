/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:25:08 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/20 15:10:42 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check where errors should be displayed

void	error_handler(char *str)
{
	write(1, "Error\n", 6);
	ft_printf("%s\n", str);
	exit(1);
}

int	exit_game(t_game *game)
{
	if (game->image->blank)
		mlx_delete_image(game->mlx, game->image->blank);
	if (game->image->character)
		mlx_delete_image(game->mlx, game->image->character);
	if (game->image->collectible)
		mlx_delete_image(game->mlx, game->image->collectible);
	if (game->image->exit)
		mlx_delete_image(game->mlx, game->image->exit);
	if (game->image->wall)
		mlx_delete_image(game->mlx, game->image->wall);
	if (game->map.line)
		free(game->map.line);
	mlx_close_window(game->mlx);
	exit(0);
}

void	finish_game(t_game *game)
{
	game->step++;
	mlx_close_window(game->mlx);
	ft_printf("---WINNER---\n");
	ft_printf("You took %d steps", game->step);
	exit(0);
}
