/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:17:29 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:17:55 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_copy_to_newline(char *str);
char	*ft_copy_left_from_buffer(char *str);
char	*get_next_line(int fd);

#endif