/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:16:36 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/27 14:00:11 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

int		set_event_press(int event_code, t_cub3d *cub)
{
	if (event_code == W_EVENT)
		cub->event.w = 1;
	if (event_code == A_EVENT)
		cub->event.a = 1;
	if (event_code == S_EVENT)
		cub->event.s = 1;
	if (event_code == D_EVENT)
		cub->event.d = 1;
	if (event_code == LEFT_EVENT)
		cub->event.left_turn = 1;
	if (event_code == RIGHT_EVENT)
		cub->event.right_turn = 1;
	if (event_code == ESCAPE_EVENT)
		cub->event.escape = 1;
	return (0);
}

int		set_event_release(int event_code, t_cub3d *cub)
{
	if (event_code == W_EVENT)
		cub->event.w = 0;
	if (event_code == A_EVENT)
		cub->event.a = 0;
	if (event_code == S_EVENT)
		cub->event.s = 0;
	if (event_code == D_EVENT)
		cub->event.d = 0;
	if (event_code == LEFT_EVENT)
		cub->event.left_turn = 0;
	if (event_code == RIGHT_EVENT)
		cub->event.right_turn = 0;
	if (event_code == ESCAPE_EVENT)
		cub->event.escape = 0;
	return (0);
}

int		set_event_escape(t_cub3d *cub)
{
	stop_cub(cub, "ESCAPE");
	return (0);
}
