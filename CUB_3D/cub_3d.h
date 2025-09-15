#ifndef CUB_3D_H
# define CUB_3D_H

// # include "../libft/libft.h"
// # include "../get_next_line/get_next_line.h"
// # include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef	struct s_map
{
	char	*read_file;
	char	**map_2d;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int	floor_color[3];
	int	ceiling_color[3];  // background color
	int	map_width;
	int	map_height; 
	int	count_element;
	int	player_pos[2];
	int	player_dir[2];
	
} t_map;
int check_file_name(char *s);
void ft_error(char *s,int exit);
#endif

