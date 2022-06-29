/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:22:37 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/21 23:26:53 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conway.h"
#include "minilibx-linux/mlx.h"

int	main(void)
{
	int x,y;
	int pos;
    int i;
	t_data	*data;

	srand(time(NULL));
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	data->size_cell = DEFAULT_CELL;
    data->cell_map = NULL;
    data->cell_map = init_cellmap(data->cell_map, data->size_x, data->size_y);
	data->mlx_win = mlx_new_window(data->mlx, data->size_x * data->size_cell,
		data->size_y * data->size_cell, "Conway Game Of Life");
	rnd_fill_cellmap(data->cell_map, data->size_x, data->size_y);
	data->buffer = NULL;
	mlx_hook(data->mlx_win, 2, 1L<<0, win_close, data);
	mlx_loop_hook(data->mlx, render, data);
    mlx_loop(data->mlx);
	free(data->mlx);
    free(data->cell_map);
    free(data->buffer);
    free(data);
	return (0);
}