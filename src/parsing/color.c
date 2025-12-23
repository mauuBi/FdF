/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:04:44 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:20 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_color(t_parsing *p, char **v, int *res, int i)
{
	char	**s_l;
	t_satoi	value;

	s_l = ft_split(v[i], ',');
	if (!s_l)
		return (free(res), free_split(v), exit_parsing(p));
	if (tab_len(s_l) < 2)
		return (free(res), free_split(s_l), free_split(v), exit_parsing(p));
	value = ps_atoi_base(s_l[1] + 2, "0123456789abcdef");
	if (value.err_code == -1)
		return (free(res), free_split(s_l), free_split(v), exit_parsing(p));
	free_split(s_l);
	res[i] = (int) value.val;
}

void	fill_color_array(t_parsing *parser, char **values, int *res, int i)
{
	while (i < parser->width * parser->length)
	{
		if (ft_strchr(values[i], ','))
		{
			handle_color(parser, values, res, i);
			i++;
			continue ;
		}
		res[i] = 0;
		i++;
	}
	free(parser->file_lines);
	free_split(values);
	parser->color = res;
}

void	create_color_array(t_parsing *parser)
{
	int		*res;
	char	**values;

	res = ft_calloc((parser->width * parser->length), sizeof(int));
	if (!res)
		exit_parsing(parser);
	values = ft_split(parser->file_lines, ' ');
	if (!values)
		return (free(res), exit_parsing(parser));
	fill_color_array(parser, values, res, 0);
}
