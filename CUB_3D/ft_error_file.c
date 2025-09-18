#include "cub_3d.h"

void ft_error(char *s,int exit_s , t_map *map)
{
    if (s)
        write (1, s, ft_strlen(s));
    if (map != NULL)
        free_map(map);
    exit(exit_s);
}
int check_file_name(char *s)
{
    int		i;

    i = 0;
	while (s[i] != '\0' && s[i] != '.')
        i++;
    if (s[i] == '\0')
         ft_error("Error \nthe file must be .cub \n",1,NULL);  
	if (s[i+1] == '\0')
        ft_error("Error \nfill a file extension \n",1,NULL); 
    if (ft_strncmp(s+i ,".cub",4) != 0)
         ft_error("Error \nthe file must end with .cub \n",1,NULL);
    return (0);
}