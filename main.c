/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:22:37 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/04 21:51:33 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conway.h"
#include "minilibx-linux/mlx.h"

int	main(void)
{
	t_data	*data;

	srand(time(NULL));
	data = malloc(sizeof(t_data));
	data->dbl_buffer = malloc(sizeof (t_buffer));
	data->mlx = mlx_init();
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	data->size_cell = DEFAULT_CELL;
    data->cell_map = NULL;
	data->mlx_win = mlx_new_window(data->mlx, data->size_x * data->size_cell,
		data->size_y * data->size_cell, "Conway Game Of Life");
	data->dbl_buffer->img = mlx_new_image(data->mlx,
										 (data->size_x + 1) * data->size_cell,
										 (data->size_y + 1) * data->size_cell);
	data->dbl_buffer->addr = mlx_get_data_addr(data->dbl_buffer->img,
											  &data->dbl_buffer->bit_per_pixel,
											  &data->dbl_buffer->line_length,
											  &data->dbl_buffer->endian);
//todo getopt https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
	data->cell_map = init_cellmap(data->cell_map, data->size_x, data->size_y);
	rnd_fill_cellmap(data->cell_map, data->size_x, data->size_y);
	data->buffer = NULL;
	mlx_hook(data->mlx_win, 2, 1L<<0, win_close, data);
	mlx_loop_hook(data->mlx, render, data);
    mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx,data->dbl_buffer->img);
	free(data->dbl_buffer);
	free(data->mlx);
    free(data->cell_map);
    free(data->buffer);
    free(data);
	return (0);
}