/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:52:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/09 22:14:04 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		turn_left(t_cub3d *cub, double turn_speed)
{
	double x_tmp_dir;
	double x_tmp_plane;

	x_tmp_dir = cub->player.x_dir;
	x_tmp_plane = cub->camera.x_plane;
	cub->player.x_dir = cub->player.x_dir * cos(turn_speed) - \
			cub->player.y_dir * sin(turn_speed);
	cub->player.y_dir = x_tmp_dir * sin(turn_speed) + \
			cub->player.y_dir * cos(turn_speed);
	cub->camera.x_plane = cub->camera.x_plane * cos(turn_speed) - \
			cub->camera.y_plane * sin(turn_speed);
	cub->camera.y_plane = x_tmp_plane * sin(turn_speed) + \
			cub->camera.y_plane * cos(turn_speed);
}

void		turn_right(t_cub3d *cub, double turn_speed)
{
	double x_tmp_dir;
	double x_tmp_plane;

	x_tmp_dir = cub->player.x_dir;
	x_tmp_plane = cub->camera.x_plane;
	cub->player.x_dir = cub->player.x_dir * cos(-turn_speed) - \
			cub->player.y_dir * sin(-turn_speed);
	cub->player.y_dir = x_tmp_dir * sin(-turn_speed) + \
			cub->player.y_dir * cos(-turn_speed);
	cub->camera.x_plane = cub->camera.x_plane * cos(-turn_speed) - \
			cub->camera.y_plane * sin(-turn_speed);
	cub->camera.y_plane = x_tmp_plane * sin(-turn_speed) + \
			cub->camera.y_plane * cos(-turn_speed);
}
