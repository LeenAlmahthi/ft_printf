#include "cub_3d.h"

int    ft_read_line(t_map *map ,int fd)
{
    if(search_for_skip(map->read_line))
    {
        free(map->read_line);
        map->read_line = get_next_line(fd);
        return (1);
    }
    if (!is_ones(map->read_line,0))
        return (0);
    map->target =  find_target(map->read_line);
    if (!map->target)
          ft_error("Error\n",1,map);
    if (map->target)
    {
        fill_data_without_map(map->target,map->read_line,map);
        free(map->target);
        map->target = NULL;
    }
    free(map->read_line);
    map->read_line = get_next_line(fd);
    return (1);  
}
void check_wall_in_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    f = 0;
    if (!top_wall(map))
        ft_error("Error\nthe top of map was not surrounded with wall\n");
    if (!do_wall(map))
        ft_error("Error\nthe top of map was not surrounded with wall\n");
    while (map->map_2d[i] != NULL)
    {
        j = 0;
        while (map->map_2d[i][j] != '\0')
        {
            if (map->map_2d[i][j] != '1' &&  map->map_2d[i][j] != '0' && map->map_2d[i][j] != ' ' && map->map_2d[i][j] != '\t')
            {
                map->player_dir= map->map_2d[i][j];
                map->player_pos[0] = i;
                map->player_pos[1] = j; 
                f++;
            }
            j++;
        }
        i++;
    }
    if (f > 1)
        ft_error("Error\nThere are multiple players in map\n",1,map)
}
void check_num_of_map(t_map *map)
{
    int i;
    int j;
    int f;

    i = 0;
    f = 0;
    while (map->map_2d[i] != NULL)
    {
        j = 0;
        while (map->map_2d[i][j] != '\0')
        {
            if (map->map_2d[i][j] != '1' &&  map->map_2d[i][j] != '0' && map->map_2d[i][j] != ' ' && map->map_2d[i][j] != '\t')
            {
                map->player_dir= map->map_2d[i][j];
                map->player_pos[0] = i;
                map->player_pos[1] = j; 
                f++;
            }
            j++;
        }
        i++;
    }
    if (f > 1)
        ft_error("Error\nThere are multiple players in map\n",1,map)
}
void fill_2dmap(t_map *map)
{
    map->map_2d = ft_split(map->all_map,'\n');
    if (!map->map_2d)
        ft_error("Error\nmslloc failed\n",1,map);
    check_num_of_map(map);
    check_wall_in_map(map);
        print_map(map);
}
int read_file(char *s ,t_map *map)
{
    int     fd;

    fd = open(s ,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1,NULL);
    map->read_line = get_next_line(fd);
    while (map->read_line != NULL) 
    {
        if (!ft_read_line(map,fd))
            break;
    }
    if (!map->read_line || map->count_element != 6)
          ft_error("Error\nin textures\n",1,map);
    read_all_map(map,fd);
    fill_2dmap(map);
    free_map(map);
    return (0);
}

char    *find_target(char *s)
{
    int i;
    int start;
    char *target;

    i = 0;
    while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
        i++;
    start = i;
    while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
        i++;
    target = ft_substr(s , start , i - start);
    if (ft_strncmp(target, "F",ft_strlen(target)) == 0)
        return (target);
    if (ft_strncmp(target, "C",ft_strlen(target)) == 0)
        return (target);
    if (ft_strncmp(target, "EA",ft_strlen(target)) == 0)
        return (target);
    if (ft_strncmp(target, "SO",ft_strlen(target)) == 0)
        return (target);
    if (ft_strncmp(target, "WE",ft_strlen(target)) == 0)
        return (target);
    if (ft_strncmp(target, "NO",ft_strlen(target)) == 0)
        return (target);
    free(target);
    return (NULL);
}
