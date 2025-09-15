
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft.h"
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