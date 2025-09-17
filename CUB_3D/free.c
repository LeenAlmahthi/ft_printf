#include "cub_3d.h"

void	free_map(t_map *map)
{
	if (!map)
		return;

	free(map->texture_no);
	free(map->texture_so);
	free(map->texture_we);
	free(map->texture_ea);
	free(map->all_map);

	// if (map->map_2d)
	// {
	// 	for (i = 0; map->map_2d[i]; i++)
	// 		free(map->map_2d[i]);
	// 	free(map->map_2d);
	// }
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