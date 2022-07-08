/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conway.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:24:32 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/04 21:52:11 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONWAY_H
# define CONWAY_H
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# define DEFAULT_X 400
# define DEFAULT_Y 200
# define DEFAULT_CELL 4
# define CELL_COLOR 0xFF0000
# define MAX_FRAME 1000
typedef struct s_cell
{
	int		alive;
	int		neighbour;
} t_cell;
typedef struct s_buffer
{
	void	*img;
	char 	*addr;
	int 	bit_per_pixel;
	int 	line_length;
	int 	endian;
} t_buffer;
typedef struct	s_data
{
	int			*cell_map;
	t_cell		*buffer;
	int			size_x;
	int			size_y;
	int			size_cell;
	void		*mlx;
	void		*mlx_win;
	t_buffer	*dbl_buffer;
} t_data;

int	win_close(int keycode, t_data *data);
int render(t_data *data);
int	d2tod1(int x, int y, int size_x,int size_y);
void	rnd_fill_cellmap(int *cell_map, int size_x, int size_y);
int		*init_cellmap(int *cell_map,int size_x, int size_y);
t_cell	*prep_buffer(int *cell_map, t_cell *buffer, int size_x, int size_y);
void	next_gen(int *cell_map,t_cell *buffer,int size_x,int size_y);

#endif