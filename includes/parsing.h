/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:16:56 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:51:02 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_satoi
{
	long	val;
	int		err_code;
}	t_satoi;

typedef struct s_parsing
{
	char	*filepath;
	int		fd;
	int		length;
	int		width;
	int		nb_chars;
	char	*file_lines;
	int		*map;
	int		*color;
	int		z_max;
	int		z_min;
}	t_parsing;

int		count_positions(int fd);
void	exit_parsing(t_parsing *parser);
void	parse_lines(t_parsing *parser);
void	read_file(t_parsing *parser);
void	print_lines(t_parsing *parser);
void	load_file(t_parsing *parser);
void	free_split(char **tab);
int		tab_len(char **tab);
char	*ps_strjoin(char const *s1, char const *s2);
int		get_line_len(char **lines);
void	count_chars(t_parsing *parser);
t_satoi	ps_atoi(char *str);
t_satoi	ps_atoi_base(char *str, char *base);
void	create_map_array(t_parsing *parser);
void	create_color_array(t_parsing *parser);
char	*str_tolower(char *str);

#endif