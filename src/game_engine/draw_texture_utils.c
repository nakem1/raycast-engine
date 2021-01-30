/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:58:34 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/31 00:18:10 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void				draw_texture_vertical(t_cub3d *cub, t_image *tex, int x)
{
	unsigned int	color;
	int				y;

	color = 0;
	cub->texture.step_tex = 1.0 * tex->height / cub->window.height_ln;
	cub->texture.pos_tex = (cub->window.top_wall - cub->window.res_height / 2 +\
			cub->window.height_ln / 2) * cub->texture.step_tex;
	y = cub->window.top_wall;	
	while (y < cub->window.bottom_wall)
	{
		cub->texture.y_tex = (int)(cub->texture.pos_tex) & (tex->height - 1);
		cub->texture.pos_tex += cub->texture.step_tex;
		color = get_pix_color(tex, cub->texture.x_tex, \
				cub->texture.y_tex);
		draw_pix(cub, x, y, color);
		y++;
	}
}

/*
** 		Function:			unsigned int		get_pix_color()
**
** 		Arguments:			
**
** 		return:				
**
** 		Description:		
*/

unsigned int		get_pix_color(t_image *texture, int x, int y)
{
	unsigned int	color;

	color = 0;
	x = abs(x);
	y = abs(y);
	color = (*(int *)(texture->content + ((x + (y * texture->width)) * \
			(texture->btp / 8))));
	return (color);
}
