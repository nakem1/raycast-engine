/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:07:03 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/31 22:08:28 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		sort_sprites(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 2)
	{
		cub->sprite.order[i] = ((cub->player.x_pos - cub->sprite.spr[i].spr_x) \
				* (cub->player.x_pos - cub->sprite.spr[i].spr_x) + \
				(cub->player.y_pos - cub->sprite.spr[i].spr_y) * \
				(cub->player.y_pos - cub->sprite.spr[i].spr_y));
		i++;
	}
}