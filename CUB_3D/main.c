#include "cub_3d.h"
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
    return (NULL);
}
void    ft_free(char *s , t_map *map)
{
    (void)map;
    free(s);
}
int valid_comma(char *s)
{
    int i;
    int first_num;
    int num_comma;
    
    i = 0;
    first_num = -1;
    num_comma = 0;
     while (s[i] !=  '\0')
    {
            if (first_num == -1 && ft_isdigit(s[i]))
                first_num = i;
            if (s[i] == ',')
                num_comma++;
            i++;
    }
    if (num_comma == 2)
        return (first_num);
    return (-1);
}
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
    }
    return (0);
}
int  fill_floor(char *read_line , t_map *map)
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
                map->floor_color[i] = ft_atoi (num[i]);
            else 
            {
                ft_error("Wrong color in Floor\n",1);
                ft_free(read_line,NULL);
            }
            i++;            
        }
        map->count_element++;
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
    return (NULL);
}
void    fill_so_dir(char *target,char *read_line, t_map *map)
{
    char *address = get_address(target,read_line ,map);
    if (!address)
        ft_error("ffffffffffff",1);
    if (ft_strncmp(target, "EA",ft_strlen(target)) == 0)
        map->texture_ea = address;
    if (ft_strncmp(target, "SO",ft_strlen(target)) == 0)
       map->texture_so = address;
    if (ft_strncmp(target, "WE",ft_strlen(target)) == 0)
         map->texture_we = address;
    if (ft_strncmp(target, "NO",ft_strlen(target)) == 0)
      map->texture_no = address;
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
    fill_so_dir(target,read_line,map);
    //check_valid_input(target,read_line,map);
}
void print_map(t_map *map)
{
    // printf("read_file: %s\n", map->read_file);

    // printf("map_2d:\n");
    // for (int i = 0; i < map->map_height; i++)
    // {
    //     printf("  %s\n", map->map_2d[i]);
    // }

    printf("texture_no: %s\n", map->texture_no);
    printf("texture_so: %s\n", map->texture_so);
    printf("texture_we: %s\n", map->texture_we);
    printf("texture_ea: %s\n", map->texture_ea);

    printf("floor_color: R=%d, G=%d, B=%d\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
    printf("ceiling_color: R=%d, G=%d, B=%d\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);

    // printf("map_width: %d\n", map->map_width);
    // printf("map_height: %d\n", map->map_height);
    printf("count_element: %d\n", map->count_element);
    printf("player_pos: x=%d, y=%d\n", map->player_pos[0], map->player_pos[1]);
    printf("player_dir: x=%d, y=%d\n", map->player_dir[0], map->player_dir[1]);
}
int search_for_skip(char *s)
{
    int i = 0;
    while (s[i] != '\0' && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' ))
        i++;
    if (s[i] == '\0')
        return (1);
    return (0);
}
int is_ones(char *s)
{
    int i = 0;
    while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' ' ))
        i++;
    while (s[i] != '\0' && s[i] == '1' )
        i++;
    if (s[i] == '\n' && (s[i-1] == '0' ||  s[i-1] == '1' ))
        return (0);
    return (1);
}
int read_file(char *s ,t_map *map)
{
    int     fd;
    char      *read_line;
    char    *target;

    fd = open(s ,O_RDONLY);
    if (fd < 0)
        ft_error("Error\ncant open file\n",1);
    read_line = get_next_line(fd);
    while (read_line != NULL && is_ones(read_line)) 
    {
        if (is_ones(read_line) == 0)
            break;
        if(search_for_skip(read_line))
        {
            read_line = get_next_line(fd);
            continue;
        }
        target =  find_target(read_line);
        if (target)
            fill_data_without_map(target,read_line,map);
        read_line = get_next_line(fd);  
    }
    //// here is the start of map 
    if (!read_line || map->count_element != 6)
          ft_error("Error\n",1);     
        printf("line : %s",read_line);
    print_map(map);
    return (0);
}
void    init_struct(t_map *map)
{
    map->read_file = NULL;
    map->map_2d = NULL;
    map->texture_ea = NULL;
    map->texture_no = NULL;
    map->texture_so = NULL;
    map->texture_we = NULL;
    map->ceiling_color[0] = -1;
    map->ceiling_color[1] = -1;
    map->ceiling_color[2] = -1;
    map->floor_color[0] = -1;
    map->floor_color[1] = -1;
    map->floor_color[2] = -1;
    map->count_element = 0;
    map->map_height = -1;
    map->map_width = -1;
    map->player_dir[0] = -1;
    map->player_dir[1] = -1;
    map->player_pos[0] = -1;
    map->player_pos[1] = -1;
}
int check_and_fill_map(char *s)
{
    t_map   map;
    
    init_struct(&map);
    if (check_file_name(s))
        return (1);
    if (read_file(s,&map))
        return (0);
    return (0);
}  
int main (int arc, char **argv)
{
    (void)argv;
    if (arc != 2 )
       ft_error("Error in number of argement\n",1);
    if (check_and_fill_map(argv[1]))
            return (1);
}