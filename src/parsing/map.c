/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:28:59 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:36 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_z_limits(t_parsing *p)
{
	int	i;
	int	z_max;
	int	z_min;

	i = 0;
	z_max = -2147483648;
	z_min = 2147483647;
	while (i < p->length * p->width)
	{
		if (p->map[i] > z_max)
			z_max = p->map[i];
		if (p->map[i] < z_min)
			z_min = p->map[i];
		i++;
	}
	p->z_max = z_max;
	p->z_min = z_min;
}

static void	handle_color(t_parsing *p, char **v, int *res, int i)
{
	char	**s_l;
	t_satoi	value;

	s_l = ft_split(v[i], ',');
	if (!s_l)
		return (free(res), free_split(v), exit_parsing(p));
	if (tab_len(s_l) < 2)
		return (free(res), free_split(s_l), free_split(v), exit_parsing(p));
	value = ps_atoi(s_l[0]);
	if (value.err_code == -1)
		return (free(res), free_split(s_l), free_split(v), exit_parsing(p));
	free_split(s_l);
	res[i] = (int) value.val;
}

void	fill_map_array(t_parsing *parser, char **values, int *res, int i)
{
	t_satoi	value;

	while (i < parser->width * parser->length)
	{
		if (ft_strchr(values[i], ','))
		{
			handle_color(parser, values, res, i);
			i++;
			continue ;
		}
		value = ps_atoi(values[i]);
		if (value.err_code == -1)
			return (free(res), free_split(values), exit_parsing(parser));
		res[i] = (int) value.val;
		i++;
	}
	free_split(values);
	parser->map = res;
}

void	create_map_array(t_parsing *parser)
{
	int		*res;
	char	**values;

	res = ft_calloc((parser->width * parser->length), sizeof(int));
	if (!res)
		exit_parsing(parser);
	values = ft_split(parser->file_lines, ' ');
	if (!values)
		return (free(res), exit_parsing(parser));
	fill_map_array(parser, values, res, 0);
	get_z_limits(parser);
}
