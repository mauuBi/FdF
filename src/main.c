/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:11:40 by mnassere          #+#    #+#             */
/*   Updated: 2025/06/03 02:50:50 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (filename[len - 1] == 'f' && filename[len - 2] == 'd'
		&& filename[len - 3] == 'f' && filename[len - 4] == '.');
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if (!is_valid_extension(argv[1]))
			return (write(2, "Invalid file\n", 13), 1);
		fdf = (t_fdf){0};
		init_parsing(&fdf, argv[1]);
		init_render(&fdf);
		mlx_hook(fdf.mlx_win, 17, 1L << 17, mlx_close, &fdf);
		mlx_hook(fdf.mlx_win, 2, 1L << 0, event_dispatcher, &fdf);
		mlx_mouse_hook(fdf.mlx_win, mouse_event_dispatcher, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		return (write(2, "Invalid arguments\n", 18), 1);
	return (0);
}
