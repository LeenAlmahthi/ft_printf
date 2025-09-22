/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_floor_and_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:36:10 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 13:07:01 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	fill_ceiling(char *read_line, t_map *map)
{
	int	i;
	int	num_index;

	i = 0;
	num_index = valid_comma(read_line);
	if (num_index != -1)
	{
		map->num = ft_split(read_line + num_index, ',');
		if (!map->num)
			exit(1);
		while (map->num[i] != NULL)
		{
			if (ft_atoi(map->num[i]) <= 255 && ft_atoi(map->num[i]) >= 0)
				map->ceiling_color[i] = ft_atoi(map->num[i]);
			else
				ft_error("Wrong color in ceiling\n", 1, map);
			i++;
		}
		map->count_element++;
		free_2d_array(map->num);
		map->num = NULL;
	}
	return (0);
}

int	fill_floor(char *read_line, t_map *map)
{
	int	i;
	int	num_index;

	i = 0;
	num_index = valid_comma(read_line);
	if (num_index != -1)
	{
		map->num = ft_split(read_line + num_index, ',');
		if (!map->num)
			exit(1);
		while (map->num[i] != NULL)
		{
			if (ft_atoi(map->num[i]) <= 255 && ft_atoi(map->num[i]) >= 0)
				map->floor_color[i] = ft_atoi(map->num[i]);
			else
				ft_error("Wrong color in Floor\n", 1, map);
			i++;
		}
		map->count_element++;
		free_2d_array(map->num);
		map->num = NULL;
	}
	return (0);
}

int	flood_fill(char **map, int x, int y, int height)
{
	int	current_width;

	if (x < 0 || x >= height || y < 0)
		return (0);
	current_width = ft_strlen(map[x]);
	if (y >= current_width)
		return (0);
	if ((x == 0 || x == height - 1 || y == 0 || y == current_width - 1)
		&& map[x][y] != '1')
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'X')
		return (1);
	if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' ||
		map[x][y] == 'E' || map[x][y] == 'W')
		map[x][y] = 'X';
	else
		return (0);
	if (!flood_fill(map, x + 1, y, height)
		||!flood_fill(map, x - 1, y, height)
		||!flood_fill(map, x, y + 1, height)
		||!flood_fill(map, x, y - 1, height))
		return (0);
	return (1);
}
