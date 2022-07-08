/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:43:41 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/30 01:43:50 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conway.h"
#include "minilibx-linux/mlx.h"

int	win_close(int keycode, t_data *data)
{
	(void) keycode;
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

void	my_mlx_pixel_put(t_buffer *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_cell(t_data *data, int x, int y)
{
	x = x * DEFAULT_CELL;
	int x_org = x;
	y = y * DEFAULT_CELL;
	int max_x = x + DEFAULT_CELL;
	int max_y = y + DEFAULT_CELL;
	while (y < max_y)
	{
		x = x_org;
		while (x < max_x)
		{
			my_mlx_pixel_put(data->dbl_buffer, x, y, CELL_COLOR);
			x++;
		}
		y++;
	}
}
void clear_img(t_data *data)
{
	int x;
	int y = 0;
	while (y < (data->size_y * data->size_cell))
	{
		x = 0;
		while (x < (data->size_x * data->size_cell))
		{
			my_mlx_pixel_put(data->dbl_buffer,x,y,0);
			x ++;
		}
		y ++;
	}
}
int render(t_data *data)
{
	int 		x;
	int			y;
	int			pos;
	static int	frame_count=0;

	if (frame_count == MAX_FRAME)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dbl_buffer->img, 0 ,0);
		frame_count = 0;
	}
	else if (frame_count == 0)
	{
		clear_img(data);
		frame_count ++;
	}
	else if (frame_count == MAX_FRAME / 2)
	{
		data->buffer = prep_buffer(data->cell_map, data->buffer,
								   data->size_x, data->size_y);
		next_gen(data->cell_map, data->buffer, data->size_x, data->size_y);
		y = 0;
		while (y < data->size_y)
		{
			x = 0;
			while (x < data->size_x)
			{
				pos = d2tod1(x, y, data->size_x, data->size_y);
				if (data->cell_map[pos] >= 1)
					draw_cell(data, x, y);
				x++;
			}
			y++;
		}
		frame_count ++;
	}
	else
	{
		frame_count ++;
	}
	return (0);
}