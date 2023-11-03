#include "../includes/cub3D.h"

int	check_from_back2(char **map, int j, int end, int height)
{
	int	tmp;

	if (j == 0 && end < (int)ft_strlen(map[j + 1]))
	{
		tmp = end;
		while (map[j + 1][++tmp])
			if (map[j + 1][tmp] == '0')
				return (0);
	}
	else if (j == height - 1 && end < (int)ft_strlen(map[j - 1]))
	{
		tmp = end;
		while (map[j - 1][++tmp])
			if (map[j - 1][tmp] == '0')
				return (0);
	}
	return (1);
}

int	check_from_back(char **map, int j, int end, int height)
{
	while (end > 0 && map[j][end])
	{
		if (map[j][end] == '1')
		{
			if (check_from_back2(map, j, end, height) == 0)
				return (0);
			return (1);
		}
		else if (map[j][end] == '0')
			return (0);
		end--;
	}
	return (0);
}

int	check_wall_elements_2(t_parse *p, int j, int i, int start)
{
	(void)i;
	while (++j < p->imap.height)
	{
		// i = -1;
		start = ft_strlen(p->map[j]) - 1;
		if (check_from_back(p->map, j, start, p->imap.height) == 0)
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	}
	return (SUCCESS);
}

int	check_wall_elements(t_parse *p, int j, int i, int start)
{
	while (++j < p->imap.height)
	{
		i = -1;
		start = is_start_zero(p->map, j);
		if (p->map[j][start] == '0')
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		while (++i < p->imap.width)
		{
			if (check_walls(p, j, i))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
