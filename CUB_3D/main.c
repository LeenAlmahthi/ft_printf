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
void open_windows(t_map *map)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    print_map(map);
    if (!mlx)
    {
        //delete_textures(data);
        ft_error("Error\nFailed to initialize mlx\n",1,map);
    }
    win = mlx_new_window(mlx, 500, 500, "Leen&&Narjes");
    mlx_loop(mlx);

    // img = mlx_new_image(mlx, CUB_WIDTH, CUB_HEIGHT);
    // if (!img)
    // {
    //     delete_textures(data);
    //     mlx_terminate(mlx);
    //     free_and_exit(data, "Error\nFailed to create image\n");
    // }

    // determine_init_angle(data); // Your logic

    // data->player.x_delta = 0;

    // mlx_image_to_window(mlx, img, 0, 0);
    // mlx_key_hook(mlx, ft_open_door, data);
    // mlx_cursor_hook(mlx, mouse_handler, data);
    // mlx_loop_hook(mlx, ft_draw_loop, data);

    // free_mlx_data(data);

    // mlx_data->mlx = mlx_init(CUB_WIDTH, CUB_HEIGHT, "game", false);
	// if (!mlx_data->mlx)
	// {
	// 	delete_textures(data);
	// 	free_and_exit(data, "Error\nFailed to initialize mlx\n");
	// }
	// mlx_data->img = mlx_new_image(mlx_data->mlx, CUB_WIDTH, CUB_HEIGHT);
	// if (!mlx_data->img)
	// {
	// 	delete_textures(data);
	// 	mlx_terminate(mlx_data->mlx);
	// 	free_and_exit(data, "Error\nFailed to create image\n");
	// }
	// determine_init_angle(data);//determining the directions (in radian)
	// data->player.x_delta = 0;
	// mlx_image_to_window(mlx_data->mlx, mlx_data->img, 0, 0);
	// mlx_key_hook(mlx_data->mlx, ft_open_door, data);
	// mlx_cursor_hook(mlx_data->mlx, mouse_handler, data);
	// mlx_loop_hook(mlx_data->mlx, ft_draw_loop, data);
	// mlx_loop(mlx_data->mlx);
	// free_mlx_data(data);
}
int check_and_fill_map(char *s)
{
    t_map   map;
    
    init_struct(&map);
    if (check_file_name(s))
        return (1);
    if (read_file(s,&map))
        return (0);
    open_windows(&map);
    free_map(&map);
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