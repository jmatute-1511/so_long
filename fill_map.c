/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:24:04 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/05 19:20:28 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *Fill_Array_Map(char **argv)
{
	int		fd;
	int		bolean;
	char	*map;
	char	*aux_map;
	char	*line;

	fd = open(argv[1],O_RDONLY);
	bolean = 1;
	map = NULL;
	while (bolean != 0)
	{
		bolean = get_next_line(fd, &line);
		if (map)
		{
			aux_map = ft_strnjoin(3,map,"\n",line);
			free(map);
			map = ft_strdup(aux_map);
			free(aux_map);
		}
		else
			map = ft_strdup(line);
		free(line);
	}
	close(fd);
	return(map);
}

void Create_Images(t_data *data, void *mlx)
{
	data->width = 32;
	data->high = 32;
	data->Floor = mlx_xpm_file_to_image(mlx, "./images/floor.xpm",\
	&data->width, &data->high);
	data->Wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",\
	&data->width, &data->high);
	data->Exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm",\
	&data->width, &data->high);
	data->Items = mlx_xpm_file_to_image(mlx, "./images/colectable.xpm",\
	&data->width, &data->high);
	data->Sprite = mlx_xpm_file_to_image(mlx, "./images/sprites.xpm",\
	&data->width,&data->high);
	data->Up = mlx_xpm_file_to_image(mlx, "./images/up.xpm",\
	&data->width, &data->high);
	data->Down = mlx_xpm_file_to_image(mlx, "./images/down.xpm",\
	&data->width,&data->high);
	data->Left = mlx_xpm_file_to_image(mlx,"./images/left.xpm",\
	&data->width, &data->high);
	data->Right = mlx_xpm_file_to_image(mlx,"./images/right.xpm",\
	&data->width,&data->high);
}
void Select_images(t_data *data,char c, void *mlx, void *win)
{
	mlx_put_image_to_window(mlx,win, data->Floor, data->f_x, data->f_y);
	if (c == '1')
		mlx_put_image_to_window(mlx,win, data->Wall, data->f_x, data->f_y);
	if (c == 'C')
		mlx_put_image_to_window(mlx,win, data->Items, data->f_x, data->f_y);
	if (c == 'E')
		mlx_put_image_to_window(mlx,win, data->Exit, data->f_x, data->f_y);
	if (c == 'P')
		mlx_put_image_to_window(mlx,win, data->Right, data->f_x, data->f_y);
}
void Fill_Window(t_data *data, void *mlx, void *win, char **map)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	data->f_x = 0;
	data->f_y = 0;
	while (map[count])
	{
		while (map[count][count2])
		{
			Select_images(data,map[count][count2],mlx,win);
			data->f_x += 32;
			count2++;
		}
		data->f_x = 0;
		data->f_y += 32;
		count2 = 0;
		count++;
	}
}