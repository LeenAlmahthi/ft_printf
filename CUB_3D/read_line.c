#include "cub_3d.h"
void read_map(t_map *map ,int fd)
{
    char *tmp;

    tmp = NULL;
    map->all_map = ft_strdup("");
    if (!map->all_map)
       return;
    while (map->read_line != NULL && is_ones(map->read_line)) 
    {
        if(search_for_skip(map->read_line))
        {
            free(map->read_line);
            free(map->all_map);
            ft_error("Error\nthe map contains a new line\n",1);
            break;
        }
        tmp = ft_strjoin(map->all_map,map->read_line);
        if (!tmp)
            return;
        free(map->all_map);
        map->all_map = tmp;
        free(map->read_line);
        map->read_line = get_next_line(fd);  
    }
    printf("%s",map->all_map);
}

int read_file(char *s ,t_map *map)
{
    int     fd;
    char    *target;

    fd = open(s ,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncan't open file\n",1);
    map->read_line = get_next_line(fd);
    while (map->read_line != NULL && is_ones(map->read_line)) 
    {
        if(search_for_skip(map->read_line))
        {
            free(map->read_line);
            map->read_line = get_next_line(fd);
            continue;
        }
        if (map->count_element == 6)
            break;
        target =  find_target(map->read_line);
        if (target)
        {
            fill_data_without_map(target,map->read_line,map);
            free(target);
        }
        free(map->read_line);
        map->read_line = get_next_line(fd);  
    }
    //// here is the start of map 
    if (!map->read_line || map->count_element != 6)
          ft_error("Error\n",1);
    read_map(map,fd);
    print_map(map);
    free(map->read_line);
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