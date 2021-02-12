/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:29:40 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/12 03:20:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int				escape_event(t_cub3d *cub)
{
	stop_cub(cub, NULL);
	return (0);
}

/*
** 		Function:			void		event_handler()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		handle all events
*/

void			event_handler(t_cub3d *cub)
{
	cub->player.step_speed = 0.14;
	if (cub->event.left_turn)
		step_turn_event(cub, e_turn_left, 1.57, 0.08);
	if (cub->event.right_turn)
		step_turn_event(cub, e_turn_right, 1.57, 0.08);
	if (cub->event.w)
		step_turn_event(cub, e_forward, 1.57, 0.08);
	if (cub->event.a)
		step_turn_event(cub, e_left, 1.57, 0.08);
	if (cub->event.d)
		step_turn_event(cub, e_right, 1.57, 0.08);
	if (cub->event.s)
		step_turn_event(cub, e_back, 1.57, 0.08);
	if (cub->event.escape)
		escape_event(cub);
}
