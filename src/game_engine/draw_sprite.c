/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:07:03 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/01 03:59:15 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		calculate_limits_sprite(t_cub3d *cub)
{
	cub->sprite.height_spr = abs((int)(cub->window.res_height / \
			cub->sprite.transpons_matrix_y));
	cub->sprite.top_spr = (cub->sprite.height_spr * -1) / 2 + \
			cub->window.res_height / 2;
	if (cub->sprite.top_spr < 0)
		cub->sprite.top_spr = 0;
	cub->sprite.bottom_spr = cub->sprite.height_spr / 2 + cub->window.res_height / 2;
	if (cub->sprite.bottom_spr >= cub->window.res_height)
		cub->sprite.bottom_spr = cub->window.res_height - 1;
}

void		transpons_matrix(t_cub3d *cub)
{
	double	inverse;

	cub->sprite.x_spr = cub->sprite.spr[i].spr_x;
	cub->sprite.y_spr = cub->sprite.spr[i].spr_y;
	inverse = 1.0 / (cub->camera.x_plane * cub->player.y_dir - \
			cub->player.x_dir * cub->camera.y_plane);
	cub->sprite.transpons_matrix_x = inverse * (cub->player.y_dir * cub->sprite.x_spr - \
			cub->player.x_dir * cub->sprite.y_spr);
	cub->sprite.transpons_matrix_y = inverse * ((cub->camera.y_plane * -1) * \
			cub->sprite.x_spr + cub->camera.x_plane * cub->sprite.y_spr);
	cub->sprite.spr_scrx = (int)((cub->window.res_width / 2) * (1 + cub->sprite.transpons_matrix_x / \
			cub->sprite.transpons_matrix_y));
}

void		calculate_sprite(t_cub3d *cub)
{
      int spriteHeight = abs(int(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
	int		i;

	i = 0;

	while (i < cub->sprite.count_sprite)
	{
		transpons_matrix(cub);
		calculate_limits_sprite(cub);
	} 
}

void		ft_sort(t_cub3d *cub)
{
	int i;
	int j;
	t_spr_location *tmp;

	i = 0;
	while (i < cub->sprite.count_sprite)
	{
		j = 0;
		while (j < cub->sprite.count_sprite)
		{
			if (cub->sprite.spr[j].dist > cub->sprite.spr[j + 1].dist)
			{
				tmp = &(cub->sprite.spr[j]);
				cub->sprite.spr[j] = cub->sprite.spr[j + 1]; // меняем местами
				cub->sprite.spr[j + 1] = *tmp;
			}
		}
	}
}

void		sort_sprites(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < cub->sprite.count_sprite)
	{
		cub->sprite.spr[i].dist = ((cub->player.x_pos - cub->sprite.spr[i].spr_x) \
				* (cub->player.x_pos - cub->sprite.spr[i].spr_x) + \
				(cub->player.y_pos - cub->sprite.spr[i].spr_y) * \
				(cub->player.y_pos - cub->sprite.spr[i].spr_y));
		i++;
	}
	ft_sort(cub);
}