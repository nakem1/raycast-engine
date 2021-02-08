/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 05:12:07 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:53:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_image		*get_ptr(t_cub3d *cub, t_count_settings *count_s, int set)
{
	if (set == e_north)
	{
		count_s->north += 1;
		return (&(cub->texture.north));
	}
	else if (set == e_south)
	{
		count_s->south += 1;
		return (&(cub->texture.south));
	}
	else if (set == e_west)
	{
		count_s->west += 1;
		return (&(cub->texture.west));
	}
	else if (set == e_sprite)
	{
		count_s->sprite += 1;
		return (&(cub->texture.sprite));
	}
	else
	{
		count_s->east += 1;
		return (&(cub->texture.east));
	}
}

void		set_value_texture(t_cub3d *cub, char *str, \
		t_count_settings *count_s, int set)
{
	int		i;
	t_image	*set_conf;

	i = 2;
	ft_skip_spaces(str, &i);
	set_conf = get_ptr(cub, count_s, set);
	if (!str[i] || (7 > ft_strlen(str)) \
			|| !(ft_strnstr(".xpm", &(str[ft_strlen(str) - 4]), 4)))
	{
		free(str);
		stop_cub(cub, TEXTURE_FAIL);
	}
	if (!(set_conf->pointer = mlx_xpm_file_to_image(cub->window.mlx_ptr, \
			&(str[i]), &(set_conf->width), &(set_conf->height))) \
			|| (!(set_conf->content = mlx_get_data_addr(set_conf->pointer, \
			&(set_conf->btp), &(set_conf->line_size), &(set_conf->end)))))
	{
		free(str);
		stop_cub(cub, TEXTURE_FAIL);
	}
}

void		set_value_res(t_cub3d *cub, char *str, \
		t_count_settings *count_s)
{
	int i;
	int count;

	i = 2;
	count = 0;
	count_s->res += 1;
	ft_skip_spaces(str, &i);
	if (!only_digits_ln(str) || \
			(cub->window.res_width = ft_atoi(&(str[i]))) < 1)
	{
		free(str);
		str = NULL;
		stop_cub(cub, RES_FAIL);
	}
	i += ft_strlen_int(cub->window.res_width);
	ft_skip_spaces(str, &i);
	if (((cub->window.res_height = ft_atoi(&(str[i]))) < 1))
	{
		free(str);
		str = NULL;
		stop_cub(cub, RES_FAIL);
	}
	if (cub->window.res_width > 2560 || cub->window.res_height > 2048)
		set_r_size(cub);
}

void		check_zero_norme(t_cub3d *cub, char *str, int i)
{
	if (str[i] != '\0')
	{
		free(str);
		str = NULL;
		stop_cub(cub, TRASH_END_LINE);
	}
}

void		set_value_color(t_cub3d *cub, char *str, \
		t_count_settings *count_s, int set)
{
	int i;
	int color1;
	int color2;
	int color3;
	int	rgb;

	rgb = 0;
	i = 2;
	ft_skip_spaces(str, &i);
	if (!only_digits_comma(str))
		stop_cub(cub, RGB_FAIL);
	color1 = ft_atoi(&str[i]);
	check_rgb(cub, color1, str, &i);
	ft_skip_spaces_comma(str, &i);
	color2 = ft_atoi(&str[i]);
	check_rgb(cub, color2, str, &i);
	ft_skip_spaces_comma(str, &i);
	color3 = ft_atoi(&str[i]);
	check_rgb(cub, color3, str, &i);
	ft_skip_spaces(str, &i);
	check_zero_norme(cub, str, i);
	rgb = (color3 << 0) | (color2 << 8) | (color1 << 16);
	set_color_struct(cub, count_s, set, rgb);
}
