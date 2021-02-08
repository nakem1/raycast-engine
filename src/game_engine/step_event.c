/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:54:52 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:32:40 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			step_forward(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos + \
			cub->player.x_dir * cub->player.step_speed)] == '0')
		cub->player.x_pos += cub->player.x_dir * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos + cub->player.y_dir * \
			cub->player.step_speed)][(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos += cub->player.y_dir * cub->player.step_speed;
}

void			step_left(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos - \
			cub->player.y_dir * cub->player.step_speed)] == '0')
		cub->player.x_pos -= cub->player.y_dir * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos + cub->player.x_dir * \
					cub->player.step_speed)][(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos += cub->player.x_dir * cub->player.step_speed;
}

void			step_right(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos + \
			cub->player.y_dir * cub->player.step_speed)] == '0')
		cub->player.x_pos += cub->player.y_dir * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos - cub->player.x_dir * \
			cub->player.step_speed)][(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos -= cub->player.x_dir * cub->player.step_speed;
}

void			step_back(t_cub3d *cub)
{
	if (cub->field.map[(int)(cub->player.y_pos)][(int)(cub->player.x_pos - \
			cub->player.x_dir * cub->player.step_speed)] == '0')
		cub->player.x_pos -= cub->player.x_dir * cub->player.step_speed;
	if (cub->field.map[(int)(cub->player.y_pos - \
			cub->player.x_dir * cub->player.step_speed)][\
			(int)(cub->player.x_pos)] == '0')
		cub->player.y_pos -= cub->player.y_dir * cub->player.step_speed;
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

void			step_turn_event(t_cub3d *cub, int event)
{
	if (event == e_forward)
		step_forward(cub);
	else if (event == e_left)
		step_left(cub);
	else if (event == e_right)
		step_right(cub);
	else if (event == e_back)
		step_back(cub);
	else if (event == e_turn_left)
		turn_left(cub);
	else if (event == e_turn_right)
		turn_right(cub);
}
