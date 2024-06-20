/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:00 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/20 15:11:12 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_handler(t_game *game, int dx, int dy, int i)
{
	int	new_pos;

	while (i < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
		{
			new_pos = i + dx + (dy * game->map.width);
			if (game->map.line[new_pos] == 'C')
				game->collected++;
			if (game->map.line[new_pos] == 'E'
				&& game->collected == game->collectible)
				finish_game(game);
			else if (game->map.line[new_pos] != '1'
				&& game->map.line[new_pos] != 'E')
			{
				game->map.line[i] = '0';
				game->map.line[new_pos] = 'P';
				game->step++;
				ft_printf("%d\n", game->step);
				set_map(game);
			}
			break ;
		}
		i++;
	}
}

void	move(t_game *game, int dx, int dy)
{
	move_handler(game, dx, dy, 0);
}
