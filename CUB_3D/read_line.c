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

void check_num_of_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    map->flag = 0;
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
                map->flag++;
            }
            j++;
        }
        i++;
    }
    if (map->flag > 1)
        ft_error("Error\nThere are multiple players in map\n",1,map);
    if (map->flag  == 0)
        ft_error("Error\nThere are No players in map\n",1,map);
}
int flood_fill(char **map, int x, int y, int height)
{
    if (x < 0 || x >= height || y < 0)
        return (0);

    int current_width = ft_strlen(map[x]);
    if (y >= current_width)
        return (0);
    if ((x == 0 || x == height - 1 || y == 0 || y == current_width - 1) &&
        map[x][y] != '1')
        return (0); 
    if (map[x][y] == '1' || map[x][y] == 'X')
        return (1);
    if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' ||
        map[x][y] == 'E' || map[x][y] == 'W' )
    map[x][y] = 'X';
    else
    return (0);
    if (!flood_fill(map, x + 1, y, height) ||
        !flood_fill(map, x - 1, y, height) ||
        !flood_fill(map, x, y + 1, height) ||
        !flood_fill(map, x, y - 1, height))
        return (0);
    return (1);
}

int find_hight_map(char **s)
{
    int     i;

    i = 0;
    while (s[i] != NULL)
        i++;
    return (i);
}
char **ft_copy_map(t_map *map)
{
    char **map_copy;
    int i;

    map_copy = malloc(sizeof(char *) * (map->map_height + 1));
    if (!map_copy)
        return (NULL);
    
    i = 0;
    while (i < map->map_height)
    {
        map_copy[i] = ft_strdup(map->map_2d[i]);
        if (!map_copy[i])
        {
            while (i >= 0)
            {
                free(map_copy[i]);
                i--;
            }
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}
void fill_2dmap(t_map *map)
{
    char    **copy_map;

    map->map_2d = ft_split(map->all_map,'\n');
    if (!map->map_2d)
        ft_error("Error\nmslloc failed\n",1,map);
    map->map_height = find_hight_map(map->map_2d);
    check_num_of_map(map);
    copy_map = ft_copy_map(map);
    if (!copy_map)
        ft_error("Error\n", 1, map);
    if (!flood_fill(copy_map, map->player_pos[0], map->player_pos[1], map->map_height))
    {
        free_2d_array(copy_map);
        ft_error("Error\nMap must be surrounded with wall\n", 1, map);
    }
    free_2d_array(copy_map);
}
void        check_textures(t_map *map)
{
    int fd = open(map->texture_ea, O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1,map);
    close(fd);
    fd = open(map->texture_no,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1,map);
    close(fd);
    fd = open(map->texture_so,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1,map);
    close(fd);
       fd = open(map->texture_we,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1,map);
    close(fd);
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
          ft_error("Error\n",1,map);
    read_all_map(map,fd);
    check_textures(map);
    fill_2dmap(map);
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
