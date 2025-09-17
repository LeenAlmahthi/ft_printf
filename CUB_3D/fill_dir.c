#include "cub_3d.h"

int  fill_ceiling(char *read_line , t_map *map)
{
    int i;
    int num_index;
    char   **num;

    i =0;
    num_index = valid_comma(read_line);
    if (num_index != -1)
    {
        num = ft_split(read_line+num_index , ',');
        if (!num)
            exit (1);
        while ( num[i] !=  NULL)
        {
            if (ft_atoi (num[i]) <= 255 && ft_atoi(num[i]) > 0)
                map->ceiling_color[i] = ft_atoi(num[i]);
            else 
            {
                ft_error("Wrong color in ceiling\n",1);
                ft_free(read_line,NULL);
            }
            i++;            
        }
        map->count_element++;
        free_2d_array(num);
    }
    return (0);
}
int  fill_floor(char *read_line , t_map *map)
{
    int i;
    int num_index;
    char   **num;

    i = 0;
    num_index = valid_comma(read_line);
    if (num_index != -1)
    {
        num = ft_split(read_line+num_index , ',');
        if (!num)
            exit (1);
        while (num[i] !=  NULL)
        {
            if (ft_atoi (num[i]) <= 255 && ft_atoi(num[i]) > 0)
                map->floor_color[i] = ft_atoi (num[i]);
            else 
            {
                ft_error("Wrong color in Floor\n",1);
                ft_free(read_line,NULL);
            }
            i++;            
        }
        map->count_element++;
        free_2d_array(num);
    }
    return (0);
}
char     *get_address(char *target, char *s,t_map *map)
{
    int i;
    int start;
    char *result;

    i = 0;
    while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
        i++;
    start = i;
    while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
        i++;
    result = ft_substr(s , start , i - start);
    if (ft_strncmp(result,target,ft_strlen(target)) == 0)
    {
        while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
            i++;
        start = i;
        while (s[i] != '\0' && s[i] != '\n')
            i++;
        free(result);
        result = ft_substr(s , start , i - start);
        map->count_element++;
        return (result);
    }
    free (result);
    return (NULL);
}
void    fill_dir(char *target,char *read_line, t_map *map)
{
    char *address = get_address(target,read_line ,map);
    if (!address)
        ft_error("Error\n",1);
    if (ft_strncmp(target, "EA",ft_strlen(target)) == 0)
    {
        map->texture_ea = address;
        return;
    }    
    if (ft_strncmp(target, "SO",ft_strlen(target)) == 0)
    {
        map->texture_so = address;
        return;
    }   
    if (ft_strncmp(target, "WE",ft_strlen(target)) == 0)
    {
        map->texture_we = address;
        return;
    }     
    if (ft_strncmp(target, "NO",ft_strlen(target)) == 0)
    {
        map->texture_no = address;
        return;
    }    
    free(address);
}
void    fill_data_without_map(char *target,char *read_line, t_map *map)
{
    (void)map;
    if (target[0] == 'F')
    {
        fill_floor(read_line, map);
        return;
    }
    if (target[0] == 'C')
    {
        fill_ceiling(read_line, map);
        return;
    }
    fill_dir(target,read_line,map);
}
