/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 03:19:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/07 21:16:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "headers/cub3d.h"

int     main(int argc, char **argv)
{
	if (argc == 2)
	{
		cub(argv[1]);
	}
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
		{
			screen_shot(argv[1]);
		}
		else
		{
			stop_cub(ARGUMENTS_FAIL);
		}
	}
	else
	{
		stop_cub(ARGUMENTS_FAIL);
	}
	return (0);
}

void	init_hook(t_cub3d *cub)
{
	mlx_loop_hook(cub->window.mlx_ptr, main_fn, cub);
	mlx_hook(cub->window.win_ptr, 2, 1L << 0, set_event_press, cub);
	mlx_hook(cub->window.win_ptr, 3, 1L << 1, set_event_release, cub);
	mlx_hook(cub->window.win_ptr, 17, 1L << 17, set_event_escape, cub);
	mlx_loop(cub->window.mlx_ptr);
}

void    cub(char *conf)
{
	t_cub3d *cub;

	if (!(cub = (t_cub3d *)malloc(sizeof(t_cub3d))))
		stop_cub(cub, MALLOC_FAIL);
	init_cub3d(cub);
	parse_conf(cub, conf);
	if (!(cub->window.win_ptr = mlx_new_window(cub->window.mlx_ptr, \
			cub->window.res_width, cub->window.res_height, "success pls!")))
		stop_cub(cub, MALLOC_FAIL);
	cub->sprite.zbuf = (double *)malloc(sizeof(double) * cub->window.res_width);
	if (!(cub->tmp_image1 = init_frame(cub)))
		stop_cub(cub, "malloc fail (((((");
	init_hook(cub);
}
