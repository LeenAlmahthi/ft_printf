/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:33:20 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 13:18:02 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

char	*get_address(char *target, char *s, t_map *map)
{
	int		i;
	int		start;
	char	*result;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
		i++;
	start = i;
	while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
		i++;
	result = ft_substr(s, start, i - start);
	if (ft_strncmp(result, target, ft_strlen(target)) == 0)
	{
		while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ' && s[i] != '\t')
			i++;
		free(result);
		result = ft_substr(s, start, i - start);
		map->count_element++;
		return (result);
	}
	free(result);
	return (NULL);
}

int	fill_dir_we_no(t_map *map, char *target, char *address)
{
	if (ft_strncmp(target, "WE", ft_strlen(target)) == 0)
	{
		if (map->texture_we)
			free(map->texture_we);
		map->texture_we = address;
		return (1);
	}
	if (ft_strncmp(target, "NO", ft_strlen(target)) == 0)
	{
		if (map->texture_no)
			free(map->texture_no);
		map->texture_no = address;
		return (1);
	}
	return (0);
}

void	fill_dir(char *target, char *read_line, t_map *map)
{
	char	*address;

	address = get_address(target, read_line, map);
	if (!address)
		ft_error("Error\nin textures\n", 1, map);
	if (ft_strncmp(target, "EA", ft_strlen(target)) == 0)
	{
		if (map->texture_ea)
			free(map->texture_ea);
		map->texture_ea = address;
		return ;
	}
	if (ft_strncmp(target, "SO", ft_strlen(target)) == 0)
	{
		if (map->texture_so)
			free(map->texture_so);
		map->texture_so = address;
		return ;
	}
	if (fill_dir_we_no(map, target, address))
		return ;
	free(address);
}

void	fill_data_without_map(char *target, char *read_line, t_map *map)
{
	(void)map;
	if (target[0] == 'F')
	{
		fill_floor(read_line, map);
		return ;
	}
	if (target[0] == 'C')
	{
		fill_ceiling(read_line, map);
		return ;
	}
	fill_dir(target, read_line, map);
}
