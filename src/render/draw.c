/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:29:51 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:05 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_bresenham(t_fdf *fdf, t_point p1, t_point p2, int *vars)
{
	int	e2;
	int	x;
	int	y;

	x = vars[0];
	y = vars[1];
	while (1)
	{
		draw_pixel(fdf, x, y, get_color(fdf, p1, p2, vars));
		if (x == vars[2] && y == vars[3])
			break ;
		e2 = 2 * vars[8];
		if (e2 >= vars[5])
		{
			vars[8] += vars[5];
			x += vars[6];
		}
		if (e2 <= vars[4])
		{
			vars[8] += vars[4];
			y += vars[7];
		}
		vars[9]++;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int	vars[11];

	vars[0] = (int)roundf(p1.x);
	vars[1] = (int)roundf(p1.y);
	vars[2] = (int)roundf(p2.x);
	vars[3] = (int)roundf(p2.y);
	vars[4] = abs(vars[2] - vars[0]);
	vars[5] = -abs(vars[3] - vars[1]);
	vars[6] = 1 - 2 * (vars[0] >= vars[2]);
	vars[7] = 1 - 2 * (vars[1] >= vars[3]);
	vars[8] = vars[4] + vars[5];
	vars[9] = 0;
	vars[10] = fmax(abs(vars[2] - vars[0]), abs(vars[3] - vars[1]));
	draw_bresenham(fdf, p1, p2, vars);
}
