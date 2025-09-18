#include "cub_3d.h"

void	free_map(t_map *map)
{
	if (!map)
		return;
	if (map->texture_no != NULL)
		free(map->texture_no);
	if (map->texture_so != NULL)
		free(map->texture_so);
	if (map->texture_we != NULL)
		free(map->texture_we);
	if (map->texture_ea != NULL)
		free(map->texture_ea);
	if (map->all_map != NULL)
	 	free(map->all_map);
	if (map->read_line != NULL)
		free(map->read_line);
	if (map->map_2d != NULL)
		free_2d_array(map->map_2d);
	if (map->num != NULL)
		free_2d_array(map->num);
	if (map->target != NULL)
		free(map->target);
	get_next_line(-1);
}
void    ft_free(char *s , t_map *map)
{
    (void)map;
    free(s);
}
void free_2d_array(char **num)
{
    int i;

    i =0;
    while (num[i] != NULL)
    {
        free(num[i]);
        i++;
    }
    free(num);

}