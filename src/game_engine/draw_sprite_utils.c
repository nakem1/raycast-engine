/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:45:38 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/06 03:18:30 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		calculate_width_sprite(t_cub3d *cub)
{
	cub->sprite.w_spr = abs((int)(cub->window.res_height / \
			cub->sprite.transpons_matrix_y));
	cub->sprite.top_spr_x = ((cub->sprite.w_spr * -1) / 2 + \
			cub->sprite.spr_scrx);
	if (cub->sprite.top_spr_x < 0)
		cub->sprite.top_spr_x = 0;
	cub->sprite.bottom_spr_x = cub->sprite.w_spr / 2 + cub->sprite.spr_scrx;
	if (cub->sprite.bottom_spr_x >= cub->window.res_width)
		cub->sprite.bottom_spr_x = cub->window.res_width - 1;
}

void		draw_spr(t_cub3d *cub, int x)
{
	int				y;
	int				d;
	unsigned int	color;


	d = 0;
	y = cub->sprite.top_spr_y;
	if (cub->sprite.transpons_matrix_y > 0 && x > 0 && x < cub->window.res_width \
			&& cub->sprite.transpons_matrix_y < cub->sprite.zbuf[x])
	{
		while (y < cub->sprite.bottom_spr_y)	
		{
			d = (y) * 256 - cub->window.res_height * 128 + cub->sprite.height_spr * 128;
			cub->sprite.rad_y = ((d * cub->texture.sprite.height) / cub->sprite.height_spr) / 256;
			color = get_pix_color(&(cub->texture.sprite), cub->sprite.rad_x, cub->sprite.rad_y);	
			if (color != 0 && color != 16777215)
				draw_pix(cub, x, y, color);
			y++;
		}
	}			
}

void		draw_sprite_vertical(t_cub3d *cub)
{
	int x;

	x = cub->sprite.top_spr_x;
	while (x < cub->sprite.bottom_spr_x)
	{
		cub->sprite.rad_x = (int)(256 * (x - ((cub->sprite.w_spr * -1) / 2 + \
				cub->sprite.spr_scrx)) * cub->texture.sprite.width / \
				cub->sprite.w_spr) / 256;
		draw_spr(cub, x);
		x++;
	}
}

void		spr_cpy(t_spr_location *src, t_spr_location *dest)
{
	dest->spr_x = src->spr_x;
	dest->spr_y = src->spr_y;
	dest->dist = src->dist;
}