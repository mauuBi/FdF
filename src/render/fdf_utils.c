/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:57:46 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:16 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_heigth(t_fdf *fdf)
{
	int	i;
	int	res;

	res = 2147483647;
	i = 0;
	while (i < fdf->height * fdf->width)
	{
		if (fdf->map[i] < res)
			res = fdf->map[i];
		i++;
	}
	return (res);
}

int	max_heigth(t_fdf *fdf)
{
	int	i;
	int	res;

	res = -2147483648;
	i = 0;
	while (i < fdf->height * fdf->width)
	{
		if (fdf->map[i] > res)
			res = fdf->map[i];
		i++;
	}
	return (res);
}

int	min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}
