/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:36:03 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:49:54 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max_color(t_fdf *fdf, int z)
{
	int	gap;

	gap = (fdf->max_z + fdf->min_z) / 4;
	if (z > 3 * gap)
		return (0xFFFFFF);
	if (z > 2 * gap)
		return (0x8B4513);
	if (z > gap)
		return (0xFFD700);
	if (z > 0)
		return (0x228B22);
	return (0x1E90FF);
}

int	get_color_component(int start, int end, int percent)
{
	return (start + (end - start) * percent / 100);
}

int	get_color(t_fdf *fdf, t_point p1, t_point p2, int *vars)
{
	int	start_color;
	int	end_color;
	int	percent;

	percent = 0;
	if (vars[10])
		percent = vars[9] * 100 / vars[10];
	start_color = p1.color;
	end_color = p2.color;
	if (!start_color)
		start_color = get_max_color(fdf, p1.z);
	if (!end_color)
		end_color = get_max_color(fdf, p2.z);
	return ((get_color_component((start_color >> 16) & 0xFF,
				(end_color >> 16) & 0xFF, percent) << 16)
		| (get_color_component((start_color >> 8) & 0xFF,
				(end_color >> 8) & 0xFF, percent) << 8)
		| get_color_component(start_color & 0xFF, end_color & 0xFF, percent));
}
