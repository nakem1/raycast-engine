/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:52:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/27 18:57:48 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		turn_left(t_cub3d *cub)
{
	double x_tmp_dir;
	double x_tmp_plane;

	x_tmp_dir = cub->player.x_dir;
	x_tmp_plane = cub->camera.x_plane;
	cub->player.x_dir = cub->player.x_dir * cos(cub->player.turn_speed) - \
			cub->player.y_dir * sin(cub->player.turn_speed);
	cub->player.y_dir = x_tmp_dir * sin(cub->player.turn_speed) + \
			cub->player.y_dir * cos(cub->player.turn_speed);
	cub->camera.x_plane = cub->camera.x_plane * cos(cub->player.turn_speed) - \
			cub->camera.y_plane * sin(cub->player.turn_speed);
	cub->camera.y_plane = x_tmp_plane * sin(cub->player.turn_speed) + \
			cub->camera.y_plane * cos(cub->player.turn_speed);
}

void		turn_right(t_cub3d *cub)
{
	double x_tmp_dir;
	double x_tmp_plane;

	x_tmp_dir = cub->player.x_dir;
	x_tmp_plane = cub->camera.x_plane;
	cub->player.x_dir = cub->player.x_dir * cos(-cub->player.turn_speed) - \
			cub->player.y_dir * sin(-cub->player.turn_speed);
	cub->player.y_dir = x_tmp_dir * sin(-cub->player.turn_speed) + \
			cub->player.y_dir * cos(-cub->player.turn_speed);
	cub->camera.x_plane = cub->camera.x_plane * cos(-cub->player.turn_speed) - \
			cub->camera.y_plane * sin(-cub->player.turn_speed);
	cub->camera.y_plane = x_tmp_plane * sin(-cub->player.turn_speed) + \
			cub->camera.y_plane * cos(-cub->player.turn_speed);
}