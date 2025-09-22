/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:49:56 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:18:12 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_str(char *str)
{
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

static char	*read_and_join(int fd, char *buffer, char *str, int *read_bytes)
{
	char	*temp;

	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes == -1)
	{
		free(buffer);
		free(str);
		return (NULL);
	}
	buffer[*read_bytes] = '\0';
	temp = str;
	str = ft_strjoin(str, buffer);
	free(temp);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	return (str);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	str = init_str(str);
	if (!str)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		str = read_and_join(fd, buffer, str, &read_bytes);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = read_line(fd, str);
	if (!str || str[0] == '\0')
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	line = ft_copy_to_newline(str);
	str = ft_copy_left_from_buffer(str);
	return (line);
}
