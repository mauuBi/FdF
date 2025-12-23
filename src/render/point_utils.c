/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:42:48 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:32 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *p, double angle)
{
	double	y;
	double	z;

	y = p->y;
	z = p->z;
	p->y = y * cos(angle) - z * sin(angle);
	p->z = y * sin(angle) + z * cos(angle);
}

void	rotate_y(t_point *p, double angle)
{
	double	x;
	double	z;

	x = p->x;
	z = p->z;
	p->x = x * cos(angle) + z * sin(angle);
	p->z = -x * sin(angle) + z * cos(angle);
}

void	rotate_z(t_point *p, double angle)
{
	double	x;
	double	y;

	x = p->x;
	y = p->y;
	p->x = x * cos(angle) - y * sin(angle);
	p->y = x * sin(angle) + y * cos(angle);
}

void	transform_point(t_fdf *fdf, t_point *p)
{
	p->x -= fdf->center.x;
	p->y -= fdf->center.y;
	p->z -= fdf->center.z;
	rotate_x(p, fdf->cam_x);
	rotate_y(p, fdf->cam_y);
	rotate_z(p, fdf->cam_z);
	p->x += fdf->center.x;
	p->y += fdf->center.y;
	p->z += fdf->center.z;
	if (!fdf->projection)
		project(p);
	else if (fdf->projection == 1)
		project_parallel(p);
	else
		project_perspective(p, 100);
}
