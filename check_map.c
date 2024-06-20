/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:26:41 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/20 15:10:21 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ------------TO DOS---------------------
// 1. check file extension -DONE
// ------------READ MAP--------------------
// 2. get width and height for checks -DONE
// 3. get full map as string -DONE
// ------------CHECKS----------------------
// 1. check if it is rectangular -DONE
// 2. if its walled -DONE
// 3. must have 1 exit, at least one collectible, 1 starting position -DONE
// 4. check valid path in the map -- tbd in path.c --DONE
// ----------------------------------------
// 6. able to parse any kind of map -- tbd

void	check_file_ext(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
			- 2] != 'e' || filename[len - 1] != 'r')
		error_handler("Invalid file");
}

// 1. Get map dimensions (width + height)
//  1.1 Width = ft_strlen
//  1.2 Height = each line
// 2. Get map in a string to check the collectibles, players etc ruling

void	get_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	check_file_ext(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_handler("Error opening file");
	line = get_next_line(fd);
	if (!line)
		error_handler("Empty file");
	game->map.width = ft_strlen(line) - 1;
	game->map.height = 0;
	game->map.line = sl_strdup(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		if (line)
			game->map.line = sl_strjoin(game->map.line, line);
	}
	close(fd);
}

// cheking rectangular and walled map (Check 1 & 2)
void	check_dim(t_game *game)
{
	int	i;
	int	width;
	int	height;
	int	len;
	int	len_check;

	i = 0;
	width = game->map.width;
	height = game->map.height;
	len = ft_strlen(game->map.line);
	len_check = width * height;
	if (len != len_check)
		error_handler("Map is not rectangular");
	while (i < len)
	{
		if (i < width || i % width == 0 || i % width == width - 1 || i >= (len
				- width))
		{
			if (game->map.line[i] != '1')
				error_handler("Map is not walled");
		}
		i++;
	}
}
// components:
// 0 - Empty space
// 1 - wall
// C - collectible
// E - exit
// P - player initial position

void	check_components(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			game->character++;
		else if (game->map.line[i] == 'C')
			game->collectible++;
		else if (game->map.line[i] == 'E')
			game->exit++;
		else if (game->map.line[i] != 'E' && game->map.line[i] != 'C'
			&& game->map.line[i] != 'P' && game->map.line[i] != '0'
			&& game->map.line[i] != '1')
			error_handler("Invalid components");
		i++;
	}
	if (game->exit != 1 || game->character != 1 || game->collectible == 0)
		error_handler("Invalid components numbers");
}

// int get_grid(t_map map)
// {
//     int i;
//     int width;
//     char **grid;
//     char *fline;

//     i = 0;
//     width = map.width;
//     fline = map.line;
//     grid = (char **)malloc(sizeof(char *)*(map.height));
//     if (!grid)
//         return(0);
//     while (i < map.height)
//     {
//         grid[i] = (char *)malloc((sizeof(char))*width);
//         if (!grid[i])
//         {
//             free_array(grid, i);
//             return(0);
//         }
//         ft_strncpy(grid[i], fline + i * (width), width);
//         i++;
//     }
//     grid[i] = NULL;
//     return(1);
// }

// int main(int argc, char **argv)
// {
//     t_game *game;
//     int i = 0;
//     game = malloc(sizeof(t_game));
//     game->character = 0;
//     game->collectible = 0;
//     game->exit = 0;
//     if (argc == 2)
//     {
//         get_map(argv[1], game);
//         // printf("%s", game.map.line);
//         check_dim(game);

//         check_components(game);
//         get_grid(game->map);
//         while (game->map.grid[i] != NULL)
//         {
//             printf("%s", game->map.grid[i]);
//             i++;
//         }
//         free(game->map.line);
//     }
//     return(0);
// }