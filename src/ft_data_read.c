/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data_read.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:03:40 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 14:16:18 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reader_init(t_reader *reader)
{
	reader->end = 0;
	reader->id = 0;
	reader->line = NULL;
	reader->linenr = 0;
	reader->map = 0;
}

void	ft_free_line_and_exit(t_data *data, char *line,
		char *errstr, int linenr)
{
	free(line);
	exit(ft_error(data, errstr, linenr));
}

void	ft_data_errorcheck(t_data *data, int linenr, char *line)
{
	if (data->reader.id == INVALID)
		ft_free_line_and_exit(data, line, ERR_STR_ID, linenr);
	if (data->reader.id == MAP)
		data->reader.map = ON;
	if (data->reader.id == EMPTY && data->reader.map == ON)
		data->reader.end = ON;
	if (data->reader.end == ON && data->reader.id == MAP)
		ft_free_line_and_exit(data, line, ERR_STR_OBSTRUCT, linenr);
	if (data->reader.map == ON)
	{
		if (data->reader.id == MAP || data->reader.id == EMPTY)
			return ;
		else
			ft_free_line_and_exit(data, line, ERR_STR_ORDER, linenr);
	}
}

void	ft_data_identifier(t_data *data, char *line, int linenr)
{
	t_initf			funct;
	int				i;

	i = 0;
	if (line[0] == '\0')
		data->reader.id = EMPTY;
	else
		data->reader.id = ft_identifier_get(line, &i);
	ft_data_errorcheck(data, linenr, line);
	if (data->reader.id == EMPTY)
		return ;
	funct = ft_init_funct(data->reader.id);
	if (funct == NULL)
	{
		free(line);
		exit(ft_error(data, ERR_STR_ID, linenr));
	}
	funct(data, line, i, linenr);
}

void	ft_data_read(t_data *data, int fd)
{
	int		ret;
	char	*line;
	int		linenr;

	linenr = 0;
	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		ft_data_identifier(data, line, linenr);
		free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		linenr++;
	}
}
