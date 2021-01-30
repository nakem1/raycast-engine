/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:06:18 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/31 00:23:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


/*
** 		Function:			void		draw_pix()
**
** 		Arguments:			main struct, start of draw, end of draw,
** x - coordinate
**
** 		return:				void
**
** 		Description:		fn faster than mlx_pixel_put
*/

void			draw_pix(t_cub3d *cub, int x, int y, unsigned int color)
{
	char *dest;

	dest = cub->tmp_image1->content + (y * cub->tmp_image1->line_size \
			+ x * (cub->tmp_image1->btp / 8));
	*(unsigned int*)dest = color;
}
//!переделать
void			draw_sky_floor(t_cub3d *cub, int x, int flag)
{
	int y;

	y = DRAW_START(flag);
	while (y < DRAW_END(flag))
	{
		draw_pix(cub, x, y, DRAW_COLOR(flag));
		y++;
	}
}

/*
** 		Function:			void		draw_texture()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		draw vertical "line" of wall
*/

void			draw_frame(t_cub3d *cub, int x)
{
	if (cub->window.side == 0)
	{
		if (cub->ray.x_ray_step > 0)
			draw_texture_vertical(cub, &(cub->texture.west), x);
		else
			draw_texture_vertical(cub, &(cub->texture.east), x);
	}
	else
	{
		if (cub->ray.y_ray_step > 0)
			draw_texture_vertical(cub, &(cub->texture.south), x);
		else
			draw_texture_vertical(cub, &(cub->texture.north), x);
	}
	draw_sky_floor(cub, x, SKY);
	draw_sky_floor(cub, x, FLOOR);
}

void			draw(t_cub3d *cub, int x)
{

	if (cub->window.side == 0)
	{
		cub->texture.x_wall = cub->player.y_pos + cub->ray.wall_dist * \
				cub->ray.dir_ray_y;
	}
	else
	{
		cub->texture.x_wall = cub->player.x_pos + cub->ray.wall_dist * \
				cub->ray.dir_ray_x;
	}
	cub->texture.x_wall -= floor(cub->texture.x_wall);
	cub->texture.x_tex = (int)(cub->texture.x_wall * (double) \
			(cub->texture.north.width));
	if (cub->window.side == 0 && cub->ray.dir_ray_x > 0)
		cub->texture.x_tex = cub->texture.north.width - cub->texture.x_tex - 1;
	if (cub->window.side == 1 && cub->ray.dir_ray_y < 0)
		cub->texture.x_tex = cub->texture.north.width - cub->texture.x_tex - 1;
	draw_frame(cub, x);
}

/*
** 		Function:			void		calculate_height()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		calculate the height of the line that has to be
**		drawn on screen
*/

void			calculate_height(t_cub3d *cub)
{
	cub->window.height_ln = (int)(cub->window.res_height / cub->ray.wall_dist);
	cub->window.top_wall = (cub->window.height_ln * -1) / 2 + \
			cub->window.res_height / 2;
	if (cub->window.top_wall < 0)
		cub->window.top_wall = 0;
	cub->window.bottom_wall = cub->window.height_ln / 2 + \
			cub->window.res_height / 2;
	if (cub->window.bottom_wall >= cub->window.res_height)
		cub->window.bottom_wall = cub->window.res_height - 1;
}