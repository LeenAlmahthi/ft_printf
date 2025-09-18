#include "cub_3d.h"

void print_map(t_map *map)
{
    // printf("read_file: %s\n", map->read_file);
    int     i;

    i = 0;
    printf("map_2d:\n");
    while (map->map_2d[i] != NULL)
    {
        printf("  %s\n", map->map_2d[i]);
        i++;
    }
    printf("readline %s\n", map->read_line);
    printf("target %s\n", map->target);

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
    printf("player_dir:%c\n", map->player_dir);
}

void    init_struct(t_map *map)
{
    map->read_line = NULL;
    map->all_map = NULL;
    map->map_2d = NULL;
    map->num = NULL;
    map->texture_ea = NULL;
    map->texture_no = NULL;
    map->texture_so = NULL;
    map->texture_we = NULL;
    map->target = NULL;
    map->ceiling_color[0] = -1;
    map->ceiling_color[1] = -1;
    map->ceiling_color[2] = -1;
    map->floor_color[0] = -1;
    map->floor_color[1] = -1;
    map->floor_color[2] = -1;
    map->count_element = 0;
    map->map_height = -1;
    map->map_width = -1;
    // map->player_dir[0] = -1;
    // map->player_dir[1] = -1;
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
       ft_error("Error in number of argement\n",1,NULL);
    if (check_and_fill_map(argv[1]))
            return (1);
}