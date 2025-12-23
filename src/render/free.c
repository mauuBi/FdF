/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:30:17 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:21 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_close(t_fdf *fdf)
{
	render_exit(fdf, 0);
	return (0);
}

void	render_exit(t_fdf *fdf, int exitcode)
{
	free(fdf->colors);
	free(fdf->map);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->mlx_win)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(exitcode);
}
