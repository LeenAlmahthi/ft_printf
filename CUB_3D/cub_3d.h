#ifndef CUB_3D_H
# define CUB_3D_H

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
	char	*read_line;
	char	**map_2d;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	char	*all_map;
	int	floor_color[3];
	int	ceiling_color[3];  // background color
	int	map_width;
	int	map_height; 
	int	count_element;
	int	player_pos[2];
	int	player_dir[2];
	
} t_map;
int		read_file(char *s ,t_map *map);
int		check_file_name(char *s);
int		valid_comma(char *s);
int		is_ones(char *s);
int		allow_char_in_map(char c);
int		search_for_skip(char *s);
int		fill_ceiling(char *read_line , t_map *map);
int		fill_floor(char *read_line , t_map *map);
int		check_and_fill_map(char *s);
void	ft_error(char *s,int exit);
void    fill_dir(char *target,char *read_line, t_map *map);
void    fill_data_without_map(char *target,char *read_line, t_map *map);
void	free_map(t_map *map);
void    ft_free(char *s , t_map *map);
void	print_map(t_map *map);
void    init_struct(t_map *map);
void	free_2d_array(char **num);
char     *get_address(char *target, char *s,t_map *map);
char    *find_target(char *s);
#endif

