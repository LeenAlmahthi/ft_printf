/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:01:29 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:13:53 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	ft_error(char *s, int exit_s, t_map *map)
{
	if (s)
		write(1, s, ft_strlen(s));
	if (map != NULL)
		free_map(map);
	exit(exit_s);
}

void	check_file_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (s[i] == '\0')
		ft_error("Error \nthe file must be .cub \n", 1, NULL);
	if (s[i + 1] == '\0')
		ft_error("Error \nfill a file extension \n", 1, NULL);
	if (ft_strncmp(s + i, ".cub", 4) != 0)
		ft_error("Error \nthe file must end with .cub \n", 1, NULL);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->texture_no != NULL)
		free(map->texture_no);
	if (map->texture_so != NULL)
		free(map->texture_so);
	if (map->texture_we != NULL)
		free(map->texture_we);
	if (map->texture_ea != NULL)
		free(map->texture_ea);
	if (map->all_map != NULL)
		free(map->all_map);
	if (map->read_line != NULL)
		free(map->read_line);
	if (map->map_2d != NULL)
		free_2d_array(map->map_2d);
	if (map->num != NULL)
		free_2d_array(map->num);
	if (map->target != NULL)
		free(map->target);
	get_next_line(-1);
}

void	free_2d_array(char **num)
{
	int	i;

	i = 0;
	while (num[i] != NULL)
	{
		free(num[i]);
		i++;
	}
	free(num);
}
