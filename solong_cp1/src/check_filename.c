#include "../include/so_long.h"

void	check_filename(t_game *game, char *filename)
{
	int	f_len;
	int	e_len;

	f_len = ft_strlen(filename);
	e_len = ft_strlen(FILE_NAME_EXTENSION);
	if (ft_strncmp(&filename[f_len - e_len], FILE_NAME_EXTENSION, e_len))
		error_exit(game, "wrong extension name\n");
}
