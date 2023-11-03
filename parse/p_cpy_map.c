#include "../includes/cub3D.h"

static size_t	find_biggest_len(t_imap *map, int i)
{
	size_t	biggest_len;

	biggest_len = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > biggest_len)
			biggest_len = ft_strlen(map->file[i]);
		i++;
	}
	return (biggest_len);
}

static void	change_space_into_wall(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j] == ' ' || parse->map[i][j] == '\t'
		|| parse->map[i][j] == '\r'
		|| parse->map[i][j] == '\v' || parse->map[i][j] == '\f')
			j++;
		while (parse->map[i][++j])
		{
			if (parse->map[i][j] == ' '
				&& j < (int)ft_strlen(parse->map[i]))
				parse->map[i][j] = '1';
		}
		i++;
	}
}

static int	count_map_lines(t_parse *parse, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1' && file[i][j] != '0')
			break ;
		i++;
	}
	parse->imap.end_idx = i;
	return (i - index_value);
}

static int	fill_map_tab(t_imap *mapinfo, char **map_tab, int index)
{
	int		i;
	int		j;

	mapinfo->width = find_biggest_len(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_tab[i] = ft_calloc(sizeof(char), (mapinfo->width + 1));
		if (!map_tab[i])
			return (print_err(NULL, "Could not allocate memory", FAILURE));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_tab[i][j] = mapinfo->file[index][j];
			j++;
		}
		i++;
		index++;
	}
	return (SUCCESS);
}

int	create_map(t_parse *parse, char **file, int i)
{
	parse->imap.height = count_map_lines(parse, file, i);
	if (parse->imap.height == 0)
		return (print_err(NULL, "NO_MAP_FOUND", FAILURE));
	parse->map = ft_calloc(sizeof(char *), (parse->imap.height + 1));
	if (!parse->map)
		return (print_err(NULL, "Could not allocate memory", FAILURE));
	if (fill_map_tab(&parse->imap, parse->map, i) == FAILURE)
		return (FAILURE);
	if (check_wall_elements(parse, -1, -1, 0) == FAILURE)
		return (FAILURE);
	if (check_wall_elements_2(parse, -1, -1, 0) == FAILURE)
		return (FAILURE);
	change_space_into_wall(parse);
	return (SUCCESS);
}
