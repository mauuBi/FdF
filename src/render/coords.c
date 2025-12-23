/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:59:27 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:00 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_min_coord_x(t_point p1, t_point p2, t_point p3, t_point p4)
{
	if (p1.x < p2.x && p1.x < p3.x && p1.x < p4.x)
		return (p1.x);
	if (p2.x < p1.x && p2.x < p3.x && p2.x < p4.x)
		return (p2.x);
	if (p3.x < p1.x && p3.x < p2.x && p3.x < p4.x)
		return (p3.x);
	if (p4.x < p1.x && p4.x < p2.x && p4.x < p3.x)
		return (p4.x);
	return (0);
}

int	get_max_coord_x(t_point p1, t_point p2, t_point p3, t_point p4)
{
	if (p1.x > p2.x && p1.x > p3.x && p1.x > p4.x)
		return (p1.x);
	if (p2.x > p1.x && p2.x > p3.x && p2.x > p4.x)
		return (p2.x);
	if (p3.x > p1.x && p3.x > p2.x && p3.x > p4.x)
		return (p3.x);
	if (p4.x > p1.x && p4.x > p2.x && p4.x > p3.x)
		return (p4.x);
	return (0);
}

int	get_min_coord_y(t_point p1, t_point p2, t_point p3, t_point p4)
{
	if (p1.y < p2.y && p1.y < p3.y && p1.y < p4.y)
		return (p1.y);
	if (p2.y < p1.y && p2.y < p3.y && p2.y < p4.y)
		return (p2.y);
	if (p3.y < p1.y && p3.y < p2.y && p3.y < p4.y)
		return (p3.y);
	if (p4.y < p1.y && p4.y < p2.y && p4.y < p3.y)
		return (p4.y);
	return (0);
}

int	get_max_coord_y(t_point p1, t_point p2, t_point p3, t_point p4)
{
	if (p1.y > p2.y && p1.y > p3.y && p1.y > p4.y)
		return (p1.y);
	if (p2.y > p1.y && p2.y > p3.y && p2.y > p4.y)
		return (p2.y);
	if (p3.y > p1.y && p3.y > p2.y && p3.y > p4.y)
		return (p3.y);
	if (p4.y > p1.y && p4.y > p2.y && p4.y > p3.y)
		return (p4.y);
	return (0);
}
