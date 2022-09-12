/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:02:24 by dwuthric          #+#    #+#             */
/*   Updated: 2022/09/12 17:13:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Color is ARGB

#include <stdio.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	px_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
	for (int dx = 0; dx < width; dx++)
	{
		for(int dy = 0; dy < height; dy++)
		{
			px_put(data, x + dx, y + dy, color);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 900, "Cub3d");
	img.img = mlx_new_image(mlx, 1200, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_rectangle(&img, 100, 100, 100, 100, 0x00ff0000);
	mlx_loop(mlx);
}
