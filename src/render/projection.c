/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:27:38 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:38 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project(t_point *p)
{
	double	tmp;

	tmp = p->x;
	p->x = (tmp - p->y) * cos(0.523599);
	p->y = (tmp + p->y) * sin(0.523599) - p->z;
}

void	project_parallel(t_point *p)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = p->x;
	tmp_y = p->y;
	p->x = tmp_x + 0.5 * p->z * cos(0.785398);
	p->y = tmp_y + 0.5 * p->z * sin(0.785398);
}

void	project_perspective(t_point *p, double d)
{
	double	denom;

	denom = d + p->z;
	if (denom == 0)
		denom = 1e-6;
	p->x = (d * p->x) / denom;
	p->y = (d * p->y) / denom;
}
