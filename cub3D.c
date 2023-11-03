#include "./includes/cub3D.h"

int is_cubfile(char *file)
{
	int i;
  
	i = ft_strlen(file); 
	if (i < 5)   
		return (0);
	if (file[i - 4] != '.' || (file[i - 3] != 'c' || (file[i - 2] != 'u') || (file[i - 1] != 'b')))
		return (0);
	return (1);
}

void free_memory(t_parse *parse, t_data *data)
{
	if (parse->no_text)
		free(parse->no_text);
	if (parse->so_text)
		free(parse->so_text);
	if (parse->we_text)
		free(parse->we_text);
	if (parse->ea_text)
		free(parse->ea_text);
	if (parse->text)
		free_double_array(&parse->text);
	if (parse->map)
		free_double_array(&parse->map);
	(void)data;
}
void print_data(const t_data *data)
{
	printf("Data Structure Contents:\n");
	printf("Player Position: (%f, %f)\n", data->player.x_pos, data->player.y_pos);
	printf("Player Angle: %f\n", data->player.angle);
	printf("FOV: %f\n", data->player.fov);
	printf("map %s", data->parse->no_text);
	// Add more print statements for other members as needed.
}


int main(int argc, char **argv)
{
	t_data data;
	t_parse parse;

	// (void)data;
	// // data.previous = 0;
	if (argc < 2 || argc > 2)
		return (printf("Wrong input. Usage (./Cub3d ./maps/map.cub)\n"), 1);
	if (!ft_parse(&parse, argv[1]))
		return (EXIT_FAILURE);
	data.parse = &parse;
	print_data(&data);
	printf ("Correct Data\n");
	free_memory(&parse, &data);
	return (0);
}
