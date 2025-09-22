/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:34:43 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 11:34:56 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	valid_comma(char *s)
{
	int	i;
	int	first_num;
	int	num_comma;

	i = 0;
	first_num = -1;
	num_comma = 0;
	while (s[i] != '\0')
	{
		if (first_num == -1 && ft_isdigit(s[i]))
			first_num = i;
		if (s[i] == ',')
			num_comma++;
		i++;
	}
	if (num_comma == 2)
		return (first_num);
	return (-1);
}

int	is_ones(char *s, int in_mpe)
{
	int	i;

	i = 0;
	(void)in_mpe;
	while ((s[i] != '\n' || s[i] != '\0') && (s[i] == '\t' || s[i] == ' '))
		i++;
	while ((s[i] != '\n' || s[i] != '\0') && allow_char_in_map(s[i]))
		i++;
	if ((s[i] == '\n' || s[i] == '\0') && i > 0 && allow_char_in_map(s[i - 1]))
	{
		if (in_mpe == 1)
			return (1);
		else
			return (0);
	}
	if (in_mpe == 1)
		return (0);
	else
		return (1);
}

int	allow_char_in_map(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'D' || c == 'E'
		|| c == 'W' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	search_for_skip(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	find_hight_map(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}
