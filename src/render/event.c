/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:09:27 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:11 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_special(int keycode, t_fdf *fdf)
{
	static int	current_proj = 0;

	if (keycode == XK_p)
	{
		current_proj++;
		fdf->projection = current_proj % 3;
	}
	if (keycode == XK_h)
		fdf->show_help = !fdf->show_help;
}

int	event_dispatcher(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
		render_exit(fdf, 0);
	if (keycode == XK_d || keycode == XK_Right)
		fdf->dx += 30;
	if (keycode == XK_a || keycode == XK_Left)
		fdf->dx -= 30;
	if (keycode == XK_w || keycode == XK_Up)
		fdf->dy -= 30;
	if (keycode == XK_s || keycode == XK_Down)
		fdf->dy += 30;
	if (keycode == XK_KP_Up)
		fdf->cam_y += 0.1;
	if (keycode == XK_KP_Down)
		fdf->cam_y -= 0.1;
	if (keycode == XK_KP_Left)
		fdf->cam_x -= 0.1;
	if (keycode == XK_KP_Right)
		fdf->cam_x += 0.1;
	if (keycode == XK_KP_Subtract)
		fdf->cam_z += 0.1;
	if (keycode == XK_KP_Add)
		fdf->cam_z -= 0.1;
	handle_special(keycode, fdf);
	return (render_map(fdf), 0);
}

int	mouse_event_dispatcher(int keycode, int x, int y, t_fdf *fdf)
{
	printf("%p Mouse event : %d %d %d\n", fdf, keycode, x, y);
	if (keycode == 4)
		fdf->aspect_ratio += 1;
	if (keycode == 5)
	{
		if (fdf->aspect_ratio != 1)
		fdf->aspect_ratio -= 1;
	}
	render_map(fdf);
	return (0);
}
