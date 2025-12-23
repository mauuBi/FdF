/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:29:42 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:43 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_point(t_fdf *fdf, t_point *p)
{
	p->x = p->x * fdf->aspect_ratio;
	p->y = p->y * fdf->aspect_ratio;
	p->z = p->z * fdf->aspect_ratio;
	transform_point(fdf, p);
	p->x += fdf->dx;
	p->y += fdf->dy;
}

void	link_points(t_fdf *fdf, int i)
{
	t_point	p;
	t_point	p1;
	t_point	p2;

	p = (t_point){i % fdf->width, i / fdf->width, fdf->map[i], fdf->colors[i]};
	setup_point(fdf, &p);
	if (i + fdf->width < fdf->width * fdf->height)
	{
		p1 = (t_point){i % fdf->width, (i + fdf->width) / fdf->width,
			fdf->map[i + fdf->width], fdf->colors[i + fdf->width]};
		setup_point(fdf, &p1);
		draw_line(fdf, p, p1);
	}
	if ((i % fdf->width) != (fdf->width - 1))
	{
		p2 = (t_point){(i + 1) % fdf->width, i
			/ fdf->width, fdf->map[i + 1], fdf->colors[i + 1]};
		setup_point(fdf, &p2);
		draw_line(fdf, p, p2);
	}
}

void	render_map(t_fdf *fdf)
{
	int		i;

	i = 0;
	ft_bzero(fdf->addr, WIN_HEIGHT * fdf->line_len
		+ WIN_WIDTH * (fdf->bpp / 8));
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	while (i < fdf->height * fdf->width)
	{
		link_points(fdf, i);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	if (!fdf->show_help)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 20, 0xE626FC, SHOW_HELP);
	else
	{
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 20, 0xE626FC, HIDE_HELP);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 40, 0xE626FC, HELP_PROJ);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 60, 0xE626FC, HELP_TRANS);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 80, 0xE626FC, HELP_ROT);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 15, 100, 0xE626FC, HELP_ZOOM);
	}
}
