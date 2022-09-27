/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:55:39 by ilya              #+#    #+#             */
/*   Updated: 2022/09/26 13:58:53 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define RED	"\033[0;31m"
# define GREEN  "\033[0;32m"
# define BLUE   "\033[0;34m"
# define YELW   "\033[1;33m"
# define WTH	"\033[0;37m"

# define BAD_ARGS 		"Use: ./cub3d MAP_NAME.cub\n"
# define BAD_EXTS 		"Extension must be .cub\n"
# define BAD_FILE 		"Cannot open the file\n"
# define BAD_SPR		"Cannot get texture addres\n"
# define BAD_SPR_NAME	"Wrong name of texture\n"
# define BAD_XPM		"wrong xpm file\n"
# define BAD_LOAD_NSWE	"NWES didn't load\n"
# define BAD_LOAD_FC	"FC didn't load\n"
# define EMPTY_MAP		"Empty map\n"

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_M				46
# define KEY_SPACE			49
# define KEY_ENTER			36
# define KEY_ESC 			53
# define KEY_W 				13
# define KEY_A 				0
# define KEY_S 				1
# define KEY_D 				2
# define KEY_WIN_CROSS 		17
# define WIN_WIDTH  		800
# define WIN_HEIGHT			400
# define T_WIDTH 			64
# define T_HEIGHT			64
# define COEF_ROT			0.2
# define COEF_STEP			0.25

enum	e_pos
{
	NO,
	SO,
	WE,
	EA
};

//	Image of mlx win //
typedef struct s_data
{
	void	*img;
	void	*img_t[5];
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_img;

//	View of actual map //
typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		height;
	char	*north_sprite;
	char	*south_sprite;
	char	*west_sprite;
	char	*east_sprite;
	int		floor;
	int		ceiling;
	int		x_pl;
	int		y_pl;
}	t_map;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_pl
{
	t_point	pos;
	t_point	dir;
}	t_pl;

typedef struct s_ray
{
	t_point	plane;
	t_point	ray_dir;
	t_point	dd;
	t_point	sd;
	double	camera_x;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		start;
	int		end;
}	t_ray;

typedef struct s_texture
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_texture;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_pl			pl;
	t_ray			ray;
	t_texture		wall;
	t_data_img		img;
	t_map			map;
}	t_game;

//  fts_errors //
int		ft_mistake(char *arg);

//  parcer //
void	free_map(char **arr);
void	draw_floor_ceiling(t_game *game);
void	ft_parcer(t_game *game, int file_descriptor);

char	*del_n(char *line);
void	ft_pars_walls(char *line, t_game *game);
void	ft_pars_floor_ceiling(char *line, t_game *game);
void	ft_pars_map(char *line, int i, t_game *game);

//	ft_parce_check //
void	ft_checker(t_game *game);
void	ft_check_close_map(t_game *game);

//  cub_3D //
void	ft_cub3d(t_game *game, char **argv);

//  inits.c //
void	ft_init_data(t_game *game);
void	ft_init_win(t_game *game);
void	ft_init_hooks(t_game *game);

//  img_draw //
void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void	draw_floor_ceiling(t_game *game);
int		render_next_frame(t_game *game);
void	draw_surroundings(t_game *game);
void	rays_cast(t_game *game, int x);
void	textures(t_game *game, int x);

//	hook_keys //
int		exit_hook(t_game *game);
int		key_hook(int key, t_game *game);
void	hook_w(t_game *game);
void	hook_a(t_game *game);
void	hook_s(t_game *game);
void	hook_d(t_game *game);
void	hook_left_rotation(t_game *game);
void	hook_right_rotation(t_game *game);

#endif