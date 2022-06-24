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
	data->mlx = malloc(sizeof(void *));
	data->mlx_win = malloc(sizeof(void *));
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
	i = 0;
//    while (i < 30)
//	{
//		data->buffer = prep_buffer(data->cell_map, data->buffer,
//			data->size_x, data->size_y);
//		next_gen(data->cell_map, data->buffer, data->size_x, data->size_y);
//		y = 0;
//		while (y < data->size_y)
//		{
//			x = 0;
//			while (x < data->size_x)
//			{
//				pos =d2tod1(x, y, data->size_x, data->size_y);
//				printf("%d",(int)data->cell_map[pos]);
//				x ++;
//			}
//			printf("\n");
//			y ++;
//		}
//		printf("\n\n=========================================\n\n");
//		i ++;
//	}
//    mlx_loop(data->mlx);
    free(data->mlx);
    free(data->mlx_win);
    free(data->cell_map);
    free(data->buffer);
    free(data);
	return (0);
}