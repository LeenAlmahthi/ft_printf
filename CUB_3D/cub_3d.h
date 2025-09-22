/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:58:32 by lalmahth          #+#    #+#             */
/*   Updated: 2025/09/22 12:59:13 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	char	*read_line;
	char	*target;
	char	**map_2d;
	char	**num;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we; //Path
	char	*texture_ea;
	char	*all_map;
	char	player_dir;
	int		flag;
	int		floor_color[3];
	int		ceiling_color[3]; // background color
	int		map_width;
	int		map_height;
	int		count_element;
	int		player_pos[2];
}			t_map;
int			valid_comma(char *s);
int			find_hight_map(char **s);
int			is_ones(char *s, int in_map);
int			allow_char_in_map(char c);
int			search_for_skip(char *s);
int			fill_ceiling(char *read_line, t_map *map);
int			fill_floor(char *read_line, t_map *map);
int			have_cahr_after_map(t_map *map, int fd);
int			read_file(char *s, t_map *map);
int			flood_fill(char **map, int x, int y, int height);
void		parse_fill_map(char *s, t_map *map);
void		check_textures(t_map *map);
void		fill_2dmap(t_map *map);
void		check_file_name(char *s);
void		ft_error(char *s, int exit, t_map *map);
void		fill_dir(char *target, char *read_line, t_map *map);
void		fill_data_without_map(char *target, char *read_line, t_map *map);
void		free_map(t_map *map);
void		read_all_map(t_map *map, int fd);
void		print_map(t_map *map);
void		init_struct(t_map *map);
void		free_2d_array(char **num);
char		*get_address(char *target, char *s, t_map *map);
char		*find_target(char *s);
#endif
