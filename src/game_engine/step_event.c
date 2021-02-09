/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:54:52 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/10 00:11:53 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			step_forward(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos - \
			cub->camera.y_plane * cub->player.step_speed)] == '0')
		cub->player.x_pos -= cub->camera.y_plane * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos + cub->camera.x_plane * \
					cub->player.step_speed)][(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos += cub->camera.x_plane * cub->player.step_speed;
}

void			step_left(t_cub3d *cub, double turn_step_speed)
{
	turn_left(cub, turn_step_speed);
	step_forward(cub);
	turn_right(cub, turn_step_speed);
}

void			step_right(t_cub3d *cub, double turn_step_speed)
{
	turn_right(cub, turn_step_speed);
	step_forward(cub);
	turn_left(cub, turn_step_speed);
}

void			step_back(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos + \
			cub->camera.y_plane * cub->player.step_speed)] == '0')
		cub->player.x_pos += cub->camera.y_plane * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos - cub->camera.x_plane * \
			cub->player.step_speed)][(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos -= cub->camera.x_plane * cub->player.step_speed;
}

/*
** 		Function:			void		step_event()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		handle wasd
*/

void			step_turn_event(t_cub3d *cub, int event, \
		double turn_speed_step, double turn_speed)
{
	if (event == e_forward)
		step_forward(cub);
	else if (event == e_left)
		step_left(cub, turn_speed_step);
	else if (event == e_right)
		step_right(cub, turn_speed_step);
	else if (event == e_back)
		step_back(cub);
	else if (event == e_turn_left)
		turn_left(cub, turn_speed);
	else if (event == e_turn_right)
		turn_right(cub, turn_speed);
}
