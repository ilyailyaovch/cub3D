/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:06:47 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/21 13:15:13 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&game->img, x, y, game->map.ceiling);
			else
				my_mlx_pixel_put(&game->img, x, y, game->map.floor);
		}
	}
}

int	render_next_frame(t_game *game)
{
	draw_floor_ceiling(game);
	//draw_surroundings(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	//delete later
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_t[NO], 5, 5);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_t[SO], 105, 5);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_t[WE], 205, 5);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_t[EA], 305, 5);

	return (EXIT_SUCCESS);
}