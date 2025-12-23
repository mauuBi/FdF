/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:55:46 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:56 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "parsing.h"
# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <mlx_int.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define SHOW_HELP "Press [h] to open help menu"
# define HIDE_HELP "Press [h] to close help menu"
# define HELP_ROT "[NUMPAD +] [NUMPAD -] [NUMPAD Arrows] -> Rotation"
# define HELP_TRANS "[w] [a] [s] [d] [Arrows] -> Translation"
# define HELP_PROJ "[p] -> Change projection type"
# define HELP_ZOOM "[Mouse scroll] -> Zoom"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_decal
{
	int	dx;
	int	dy;
}	t_decal;

typedef struct s_climit
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_climit;

typedef struct s_color
{
	int	cp1;
	int	cp2;
	int	cp3;
	int	cp4;
	int	cp5;
}	t_color;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		*map;
	int		*colors;
	int		aspect_ratio;
	int		offset_x;
	int		offset_y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		dx;
	int		dy;
	int		min_z;
	int		max_z;
	double	cam_x;
	double	cam_y;
	double	cam_z;
	int		projection;
	int		show_help;
	double	z_ratio;
	t_point	center;
}	t_fdf;

void	init_parsing(t_fdf *fdf, char *filepath);
void	init_render(t_fdf *fdf);
void	render_exit(t_fdf *fdf, int exitcode);
int		mlx_close(t_fdf *fdf);
int		event_dispatcher(int keycode, t_fdf *fdf);
int		mouse_event_dispatcher(int keycode, int x, int y, t_fdf *fdf);
void	draw_pixel(t_fdf *fdf, int x, int y, int color);
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
void	project(t_point *p);
void	project_parallel(t_point *p);
void	project_perspective(t_point *p, double d);
void	render_map(t_fdf *fdf);
int		min_heigth(t_fdf *fdf);
int		max_heigth(t_fdf *fdf);
int		get_min_coord_x(t_point p1, t_point p2, t_point p3, t_point p4);
int		get_max_coord_x(t_point p1, t_point p2, t_point p3, t_point p4);
int		get_min_coord_y(t_point p1, t_point p2, t_point p3, t_point p4);
int		get_max_coord_y(t_point p1, t_point p2, t_point p3, t_point p4);
void	get_decal(t_fdf *fdf);
int		min(int i1, int i2);
void	set_default_params(t_fdf *fdf);
void	transform_point(t_fdf *fdf, t_point *p);
int		get_color(t_fdf *fdf, t_point p1, t_point p2, int *vars);

#endif