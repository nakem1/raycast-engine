/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:07:03 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/07 18:09:42 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		calculate_limits_sprite(t_cub3d *cub)
{
	cub->sprite.height_spr = abs((int)(cub->window.res_height / \
			(cub->sprite.transpons_matrix_y)));
	cub->sprite.top_spr_y = (cub->sprite.height_spr * -1) / 2 + \
			cub->window.res_height / 2;
	if (cub->sprite.top_spr_y < 0)
		cub->sprite.top_spr_y = 0;
	cub->sprite.bottom_spr_y = cub->sprite.height_spr / 2 + cub->window.res_height / 2;
	if (cub->sprite.bottom_spr_y >= cub->window.res_height)
		cub->sprite.bottom_spr_y = cub->window.res_height - 1;
}

void		transpons_matrix(t_cub3d *cub, int i)
{
	double	inverse;

	cub->sprite.x_spr = cub->sprite.spr[i].spr_x - cub->player.x_pos;
	cub->sprite.y_spr = cub->sprite.spr[i].spr_y - cub->player.y_pos;
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
	int		i;

	i = 0;
	sort_sprites(cub);
	while (i < cub->sprite.count_sprite)
	{
		transpons_matrix(cub, i);
		calculate_limits_sprite(cub);
		calculate_width_sprite(cub);
		draw_sprite_vertical(cub);
		i++;
	} 
}

void		ft_sort(t_cub3d *cub)
{
	int i;
	int j;
	t_spr_location *tmp;

	tmp = (t_spr_location *)malloc(sizeof(t_spr_location));
	i = 0;
	while (i < cub->sprite.count_sprite)
	{
		j = 0;
		while (j < cub->sprite.count_sprite - 1)
		{
			if (cub->sprite.spr[j].dist < cub->sprite.spr[j + 1].dist)
			{
				spr_cpy(&(cub->sprite.spr[j]), tmp);
				spr_cpy(&(cub->sprite.spr[j + 1]), &(cub->sprite.spr[j]));
				spr_cpy(tmp, &(cub->sprite.spr[j + 1]));
			}
			j++;
		}
		i++;
	}
	free(tmp);
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