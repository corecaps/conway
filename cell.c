/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:38:07 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/21 23:30:11 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conway.h"
#include <stdlib.h>

int	d2tod1(int x, int y, int size_x, int size_y)
{
	if (x > size_x)
		x = 0;
	else if (x < 0)
		x = size_x - 1;
	if (y > size_y)
		y = 0;
	else if (y < 0)
		y = size_y - 1;
	return (x + (y * size_x));
}

int	*init_cellmap(int *cell_map,int size_x, int size_y)
{
	int	i;

	if (!cell_map)
		cell_map = malloc(sizeof(int) * ((size_x + 1)  * (size_y + 1)) );
	if (!cell_map)
		return (NULL);
	i = 0;
	while (i < (size_x * size_y))
	{
		cell_map[i] = 0;
		i ++;
	}
	return (cell_map);
}

void	rnd_fill_cellmap(int *cell_map, int size_x, int size_y)
{
	int		x;
	int		y;
	int		pos;
	int		val;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			pos = d2tod1(x, y,  size_x, size_y);
			val = rand() % 2;
			cell_map[pos] = val;
			x ++;
		}
		y ++;
	}
}

t_cell	*prep_buffer(int *cell_map, t_cell *buffer,int size_x, int size_y)
{
	int		x;
	int		y;
	int		pos;

	if (!buffer)
		buffer = malloc(sizeof(t_cell) * ((size_x + 1) * (size_y + 1) ));
	pos = 0;
	while (pos < size_x * size_y)
	{
		buffer[pos].neighbour = 0;
		buffer[pos].alive = 0;
		pos ++;
	}
	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			pos = d2tod1(x, y, size_x, size_y);
			buffer[pos].alive = cell_map[pos];
			if (cell_map[pos] == 1)
			{
				pos = d2tod1(x - 1, y, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x + 1, y, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x - 1, y - 1, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x, y - 1, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x + 1, y - 1, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x - 1, y + 1, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x, y + 1, size_x, size_y);
				buffer[pos].neighbour += 1;
				pos = d2tod1(x + 1, y + 1, size_x, size_y);
				buffer[pos].neighbour += 1;
			}
			x ++;
		}
		y ++;
	}
	return (buffer);
}

void	next_gen(int *cell_map,t_cell *buffer,int size_x,int size_y)
{
	int x;
	int y;
	int pos;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			pos = d2tod1(x, y, size_x, size_y);
			if (buffer[pos].alive == 1 && buffer[pos].neighbour == 2)
				cell_map[pos] = 1;
			else if (buffer[pos].neighbour == 3)
				cell_map[pos] = 1;
			else
				cell_map[pos] = 0;
			x ++;
		}
		y ++;
	}
}