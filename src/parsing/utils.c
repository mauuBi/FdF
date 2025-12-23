/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:19:12 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:49 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_len(char **lines)
{
	int		i;
	char	**current;
	int		line_len;

	i = 0;
	line_len = 0;
	while (lines[i])
	{
		current = ft_split(lines[i], ' ');
		if (!current)
			return (0);
		if (!line_len)
		{
			line_len = tab_len(current);
			free_split(current);
			continue ;
		}
		if (tab_len(current) != line_len)
			return (free_split(current), 0);
		free_split(current);
		i++;
	}
	return (line_len);
}

void	count_chars(t_parsing *parser)
{
	int		res;
	int		bytes_read;
	char	buf[1];

	res = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(parser->fd, buf, 1);
		if (bytes_read < 0)
			return (close(parser->fd), exit_parsing(parser));
		if (bytes_read == 0)
			break ;
		if (!buf[0])
			return (close(parser->fd), exit_parsing(parser));
		res++;
	}
	close(parser->fd);
	load_file(parser);
	if (!res)
		return (close(parser->fd), exit_parsing(parser));
	parser->nb_chars = res;
}

char	*ps_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (free((void *) s1), NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i--;
	while (s2[++i - s1_len])
		res[i] = s2[i - s1_len];
	res[i] = '\0';
	free((void *) s1);
	return (res);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
