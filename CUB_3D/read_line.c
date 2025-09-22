/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:34:20 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:57:06 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	check_textures(t_map *map)
{
	int	fd;

	fd = open(map->texture_ea, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nc1an't open file\n", 1, map);
	close(fd);
	fd = open(map->texture_no, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nca2n't open file\n", 1, map);
	close(fd);
	fd = open(map->texture_so, O_RDONLY);
	if (fd == -1)
		ft_error("Er2ror\ncan't open file\n", 1, map);
	close(fd);
	fd = open(map->texture_we, O_RDONLY);
	if (fd == -1)
		ft_error("Err5or\ncan't open file\n", 1, map);
	close(fd);
}

char	*find_target(char *s)
{
	int		i;
	int		start;
	char	*target;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
		i++;
	start = i;
	while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
		i++;
	target = ft_substr(s, start, i - start);
	if (ft_strncmp(target, "F", ft_strlen(target)) == 0)
		return (target);
	if (ft_strncmp(target, "C", ft_strlen(target)) == 0)
		return (target);
	if (ft_strncmp(target, "EA", ft_strlen(target)) == 0)
		return (target);
	if (ft_strncmp(target, "SO", ft_strlen(target)) == 0)
		return (target);
	if (ft_strncmp(target, "WE", ft_strlen(target)) == 0)
		return (target);
	if (ft_strncmp(target, "NO", ft_strlen(target)) == 0)
		return (target);
	free(target);
	return (NULL);
}

int	ft_read_line(t_map *map, int fd)
{
	if (search_for_skip(map->read_line))
	{
		free(map->read_line);
		map->read_line = get_next_line(fd);
		return (1);
	}
	if (!is_ones(map->read_line, 0))
		return (0);
	map->target = find_target(map->read_line);
	if (!map->target)
		ft_error("Error\n", 1, map);
	if (map->target)
	{
		fill_data_without_map(map->target, map->read_line, map);
		free(map->target);
		map->target = NULL;
	}
	free(map->read_line);
	map->read_line = get_next_line(fd);
	return (1);
}

int	read_file(char *s, t_map *map)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_error("Error\ncan't open file\n", 1, NULL);
	map->read_line = get_next_line(fd);
	while (map->read_line != NULL)
	{
		if (!ft_read_line(map, fd))
			break ;
	}
	if (!map->read_line || map->count_element != 6)
		ft_error("Error\n", 1, map);
	return (fd);
}
