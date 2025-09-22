/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:35:07 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:54:21 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

char	**ft_copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->map_height)
	{
		map_copy[i] = ft_strdup(map->map_2d[i]);
		if (!map_copy[i])
		{
			while (i >= 0)
			{
				free(map_copy[i]);
				i--;
			}
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	check_num_of_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_2d[i] != NULL)
	{
		j = 0;
		while (map->map_2d[i][j] != '\0')
		{
			if (map->map_2d[i][j] != '1' && map->map_2d[i][j] != '0'
				&& map->map_2d[i][j] != ' ' && map->map_2d[i][j] != '\t')
			{
				map->player_dir = map->map_2d[i][j];
				map->player_pos[0] = i;
				map->player_pos[1] = j;
				map->flag++;
			}
			j++;
		}
		i++;
	}
	if (map->flag > 1)
		ft_error("Error\nThere are multiple players in map\n", 1, map);
	if (map->flag == 0)
		ft_error("Error\nThere are No players in map\n", 1, map);
}

int	have_cahr_after_map(t_map *map, int fd)
{
	while (map->read_line != NULL && search_for_skip(map->read_line))
	{
		free(map->read_line);
		map->read_line = get_next_line(fd);
	}
	if (!map->read_line)
		return (1);
	return (0);
}

void	fill_2dmap(t_map *map)
{
	char	**copy_map;

	map->map_2d = ft_split(map->all_map, '\n');
	if (!map->map_2d)
		ft_error("Error\nmslloc failed\n", 1, map);
	map->map_height = find_hight_map(map->map_2d);
	check_num_of_map(map);
	copy_map = ft_copy_map(map);
	if (!copy_map)
		ft_error("Error\n", 1, map);
	if (!flood_fill(copy_map, map->player_pos[0], map->player_pos[1],
			map->map_height))
	{
		free_2d_array(copy_map);
		ft_error("Error\nMap must be surrounded with wall\n", 1, map);
	}
	free_2d_array(copy_map);
}

void	read_all_map(t_map *map, int fd)
{
	char	*tmp;

	tmp = NULL;
	map->all_map = ft_strdup("");
	if (!map->all_map)
		return ;
	while (map->read_line != NULL)
	{
		if (search_for_skip(map->read_line))
			break ;
		if (!is_ones(map->read_line, 1))
		{
			printf("%s", map->read_line);
			ft_error("Error\nMap contains a wrongs char\n", 1, map);
		}
		tmp = ft_strjoin(map->all_map, map->read_line);
		if (!tmp)
			return ;
		free(map->all_map);
		map->all_map = tmp;
		free(map->read_line);
		map->read_line = get_next_line(fd);
	}
	if (!have_cahr_after_map(map, fd))
		ft_error("Error\nMap contains a new line\n", 1, map);
}
