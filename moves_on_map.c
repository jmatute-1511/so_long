/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:12:48 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/04 19:27:31 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int Find_Ipoint(char **matrix,char cordinate)
{
	int c_x;
	int c_y;

	c_y = 0;
	c_x = 0;
	while (matrix[c_y])
	{
		while (matrix[c_y][c_x])
		{
			if(matrix[c_y][c_x] == 'P')
			{
				if (cordinate == 'x')
					return(c_x);
				else if(cordinate == 'y')
					return(c_y);
			}
			c_x++;
		}
		c_x = 0;
		c_y++;
	}
	return (0);
}
int Crash(int key, t_data *data)
{
	if (key == RIGHT && data->matrix_map[data->y][data->x + 1] == '1')
		return (1);
	if (key == LEFT && data->matrix_map[data->y][data->x - 1] == '1')
		return (1);
	if (key == DOWN && data->matrix_map[data->y + 1][data->x] == '1')
		return (1);
	if (key == UP && data->matrix_map[data->y - 1][data->x] == '1')
		return (1);
	return (0);
}
int Collect_Items(int key, t_data *data)
{
	if (key == RIGHT && data->matrix_map[data->y][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == LEFT && data->matrix_map[data->y][data->x - 1] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == DOWN && data->matrix_map[data->y + 1][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == UP && data->matrix_map[data->y - 1][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	return (0);
}
int up(int key, t_data *data)
{
	int aux;

	if (Crash(key,data))
		return(0);
	else
	{
		aux = data->y;
		data->y = data->y - 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->Floor, data->x * 32, aux * 32);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->Up,data->x * 32,data->y * 32);
		if(Collect_Items(key, data))
			return(1);
	}
	return (0);
}

int Select_Action(int key, t_data *data)
{
	if (key == UP)
		up(key,data);
	/*else if (key == DOWN)
	else if (key == RIGHT)
	else if (key == LEFT)
	else if (key == CLOSE)*/
	return (key);
}