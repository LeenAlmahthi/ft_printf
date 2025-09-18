#include "cub_3d.h"
int have_cahr_after_map(t_map *map ,int fd)
{
    while (map->read_line != NULL &&  search_for_skip(map->read_line)) 
    {
        free(map->read_line);
        map->read_line = get_next_line(fd);  
    }
    if (!map->read_line)
        return (1);
    return (0);
}
void read_all_map(t_map *map ,int fd)
{
    char *tmp;

    tmp = NULL;
    map->all_map = ft_strdup("");
    if (!map->all_map)
       return;
    while (map->read_line != NULL) 
    {
        if(search_for_skip(map->read_line))
                break;
        if (!is_ones(map->read_line,1))
        {
            printf("%s",map->read_line);
            ft_error("Error\nMap contains a wrongs char\n",1,map);
        }
        tmp = ft_strjoin(map->all_map,map->read_line);
        if (!tmp)
            return;
        free(map->all_map);
        map->all_map = tmp;
        free(map->read_line);
        map->read_line = get_next_line(fd);  
    }
    if (!have_cahr_after_map(map,fd))
        ft_error("Error\nMap contains a new line\n",1,map);
}