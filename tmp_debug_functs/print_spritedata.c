void	ft_print_spritedata(t_data *data)
{
	size_t	i;

	i = 0;
	printf("Player position is %f,%f\n", data->cam.pos.x, data->cam.pos.y);
	while ((int)i < data->mapdata.numsprites)
	{
		printf("SPRITE[%ld].dist = %f | .pos = %f.%f\n", i, data->mapdata.sprites[i].dist, data->mapdata.sprites[i].pos.x + 0.5, data->mapdata.sprites[i].pos.y + 0.5);
		i++;
	}
	i = 0;
	while ((int)i < data->mapdata.numsprites)
	{
		printf("INDEX ARRAY[%ld] = %i\n", i, data->mapdata.indices[i]);
		i++;
	}
}
