/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:23:07 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:43 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_file(t_parsing *parser)
{
	int	fd;

	fd = open(parser->filepath, O_RDONLY);
	if (fd < 0)
		exit_parsing(parser);
	parser->fd = fd;
}

void	read_file(t_parsing *parser)
{
	int		i;
	int		bytes_read;
	char	buf[1];
	char	*res;

	i = 0;
	bytes_read = 1;
	res = malloc((parser->nb_chars + 1) * sizeof(char *));
	if (!res)
		return (close(parser->fd), exit_parsing(parser));
	while (bytes_read > 0)
	{
		bytes_read = read(parser->fd, buf, 1);
		if (bytes_read < 0)
			return (close(parser->fd), exit_parsing(parser));
		if (bytes_read == 0)
			break ;
		res[i] = buf[0];
		i++;
	}
	res[i] = '\0';
	close(parser->fd);
	parser->file_lines = res;
}

void	parse_lines(t_parsing *parser)
{
	char	**lines;
	int		i;

	i = 0;
	lines = ft_split(parser->file_lines, '\n');
	if (!lines)
		return (free_split(lines), exit_parsing(parser));
	parser->width = tab_len(lines);
	parser->length = get_line_len(lines);
	if (!parser->length)
		return (free_split(lines), exit_parsing(parser));
	free(parser->file_lines);
	parser->file_lines = ft_strdup("");
	if (!parser->file_lines)
		return (free_split(lines), exit_parsing(parser));
	while (lines[i])
	{
		parser->file_lines = ps_strjoin(parser->file_lines, lines[i]);
		parser->file_lines = ps_strjoin(parser->file_lines, " ");
		i++;
	}
	free_split(lines);
	if (!parser->file_lines)
		exit_parsing(parser);
}

void	init_parsing(t_fdf *fdf, char *filepath)
{
	t_parsing	parser;

	parser = (t_parsing){0};
	parser.filepath = filepath;
	load_file(&parser);
	count_chars(&parser);
	read_file(&parser);
	parse_lines(&parser);
	create_map_array(&parser);
	create_color_array(&parser);
	fdf->colors = parser.color;
	fdf->map = parser.map;
	fdf->width = parser.length;
	fdf->height = parser.width;
	fdf->max_z = parser.z_max;
	fdf->min_z = parser.z_min;
}
