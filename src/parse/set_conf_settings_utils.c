/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf_settings_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:03:56 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/17 21:17:01 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		set_color_struct(t_cub3d *cub, t_count_settings *count_s, int set, \
		int rgb)
{
	if (set == e_sky)
	{
		count_s->sky += 1;
		cub->texture.ceil = rgb;
	}
	else if (set == e_floor)
	{
		count_s->floor += 1;
		cub->texture.flor = rgb;
	}
}

void		check_rgb(t_cub3d *cub, int rgb, char *str, int *i)
{
	*i += ft_strlen_int(rgb);
	if (rgb < 0 || rgb > 255)
	{
		free(str);
		str = NULL;
		stop_cub(cub, RGB_FAIL);
	}
}