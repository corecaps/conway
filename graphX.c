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
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, CELL_COLOR);
			x++;
		}
		y++;
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
		mlx_clear_window(data->mlx, data->mlx_win);
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
		frame_count = 0;
	}
	else
	{
		frame_count ++;
	}
	return (0);
}
