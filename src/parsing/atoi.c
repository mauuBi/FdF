/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:20:37 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:08 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_index_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

t_satoi	ps_atoi(char *str)
{
	t_satoi	res;
	int		i;
	long	sign;

	res = (t_satoi){0};
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!str[i])
		return (res.err_code = -1, res);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (res.err_code = -1, res);
		res.val *= 10;
		res.val += str[i] - '0';
		i++;
	}
	if (res.val * sign > 2147483647 || res.val * sign < -2147483648)
		return (res.err_code = -1, res);
	return (res.val *= sign, res);
}

t_satoi	ps_atoi_base(char *str, char *base)
{
	t_satoi	res;
	int		i;
	int		base_len;

	res = (t_satoi){0};
	i = 0;
	base_len = ft_strlen(base);
	if (!str)
		return (res.err_code = -1, res);
	str = str_tolower(str);
	if (!str[i])
		return (res.err_code = -1, res);
	while (str[i])
	{
		if (!is_in_base(base, str[i]))
			return (res.err_code = -1, res);
		res.val *= base_len;
		res.val += get_index_base(base, str[i]);
		i++;
	}
	if (res.val > 2147483647 || res.val < 0)
		return (res.err_code = -1, res);
	return (res);
}
