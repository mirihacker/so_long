/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:12:06 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/20 15:00:24 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_image
{
	mlx_image_t		*blank;
	mlx_image_t		*character;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*wall;
}					t_image;

typedef struct s_texture
{
	mlx_texture_t	*blank;
	mlx_texture_t	*character;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
}					t_texture;

typedef struct s_path
{
	char			*visited;
	int				valid_path;
	int				char_x;
	int				char_y;
	int				char_xy;
	int				collected;
}					t_path;

typedef struct s_map
{
	char			*line;
	int				width;
	int				height;
}					t_map;

typedef struct s_game
{
	int				collectible;
	int				collected;
	int				exit;
	int				character;
	int				step;
	t_path			path;
	t_image			*image;
	t_map			map;
	t_texture		*texture;
	mlx_t			*mlx;
}					t_game;

// valid map checker //
void				check_file_ext(char *filename);
void				get_map(char *filename, t_game *game);
void				check_dim(t_game *game);
void				check_components(t_game *game);

// valid path checker //
void				valid_path(int x, int y, t_game *game);
void				find_character(t_game *game);
void				path_checker(t_game *game);

// error handler and exit functions //
void				error_handler(char *str);
int					exit_game(t_game *game);
void				finish_game(t_game *game);

// set graphics //
void				start_image(t_game *game);
void				set_image(t_game *game, int w, int h);
void				set_map(t_game *game);

// movement handler //
// key handler //
void				key_handler(mlx_key_data_t keydata, void *param);
void				move_up(t_game *game);
void				move_left(t_game *game);
void				move_down(t_game *game);
void				move_right(t_game *game);

// movement functions //
void				move_handler(t_game *game, int dx, int dy, int i);
void				move(t_game *game, int dx, int dy);

// utils //
char				*sl_strdup(char *str);
char				*sl_strncpy(char *dst, const char *src, size_t len);
void				free_array(char **array, int i);
char				*sl_strjoin(char *s1, char *s2);
size_t				sl_strlcpy(char *dst, char *src, size_t dstsize);

#endif