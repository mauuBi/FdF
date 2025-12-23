/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:00:32 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:51:35 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_climit	get_limits(t_point p1, t_point p2, t_point p3, t_point p4)
{
	t_climit	res;

	res = (t_climit){0};
	res.x_min = get_min_coord_x(p1, p2, p3, p4);
	res.x_max = get_max_coord_x(p1, p2, p3, p4);
	res.y_min = get_min_coord_y(p1, p2, p3, p4);
	res.y_max = get_max_coord_y(p1, p2, p3, p4);
	return (res);
}

void	get_aspect_ratio(t_fdf *fdf)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_climit	l;

	p1 = (t_point){0, 0, min_heigth(fdf), 0};
	p2 = (t_point){fdf->width, 0, max_heigth(fdf), 0};
	p3 = (t_point){0, fdf->height, max_heigth(fdf), 0};
	p4 = (t_point){fdf->width, fdf->height, min_heigth(fdf), 0};
	transform_point(fdf, &p1);
	transform_point(fdf, &p2);
	transform_point(fdf, &p3);
	transform_point(fdf, &p4);
	l = get_limits(p1, p2, p3, p4);
	fdf->aspect_ratio = min((WIN_WIDTH - 20) / (l.x_max - l.x_min),
			(WIN_HEIGHT - 20) / (l.y_max - l.y_min));
	if (!fdf->aspect_ratio)
		fdf->aspect_ratio = 1;
}

void	get_decal(t_fdf *fdf)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_climit	l;

	p1 = (t_point){0 * fdf->aspect_ratio, 0 * fdf->aspect_ratio,
		min_heigth(fdf) * fdf->aspect_ratio, 0};
	p2 = (t_point){fdf->width * fdf->aspect_ratio, 0 * fdf->aspect_ratio,
		max_heigth(fdf) * fdf->aspect_ratio, 0};
	p3 = (t_point){0 * fdf->aspect_ratio, fdf->height * fdf->aspect_ratio,
		max_heigth(fdf) * fdf->aspect_ratio, 0};
	p4 = (t_point){fdf->width * fdf->aspect_ratio,
		fdf->height * fdf->aspect_ratio,
		min_heigth(fdf) * fdf->aspect_ratio, 0};
	transform_point(fdf, &p1);
	transform_point(fdf, &p2);
	transform_point(fdf, &p3);
	transform_point(fdf, &p4);
	l = get_limits(p1, p2, p3, p4);
	fdf->dx = WIN_WIDTH / 2 - ((l.x_max + l.x_min) / 2);
	fdf->dy = WIN_HEIGHT / 2 - ((l.y_max + l.y_min) / 2);
}

void	set_default_params(t_fdf *fdf)
{
	get_aspect_ratio(fdf);
	get_decal(fdf);
	fdf->center.x = ((fdf->width - 1) * fdf->aspect_ratio) / 2.0;
	fdf->center.y = ((fdf->height - 1) * fdf->aspect_ratio) / 2.0;
	fdf->center.z = (fdf->max_z + fdf->min_z) / 2.0;
}

void	init_render(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		render_exit(fdf, 1);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!fdf->mlx_win)
		render_exit(fdf, 1);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		render_exit(fdf, 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_len, &fdf->endian);
	if (!fdf->addr)
		render_exit(fdf, 1);
	set_default_params(fdf);
	render_map(fdf);
}
