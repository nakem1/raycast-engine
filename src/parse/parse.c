/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 06:12:48 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/07 18:06:20 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

void		settings_selector(t_cub3d *cub, char *str, int *flag, \
		t_count_settings *count_s)
{
	if (str[0] == 'R' && str[1] == ' ')
		set_value_res(cub, str, count_s);
	else if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		set_value_texture(cub, str, count_s, e_north);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		set_value_texture(cub, str, count_s, e_west);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		set_value_texture(cub, str, count_s, e_east);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		set_value_texture(cub, str, count_s, e_south);
	else if (str[0] == 'S' && str[1] == ' ')
		set_value_texture(cub, str, count_s, e_sprite);
	else if (str[0] == 'C' && str[1] == ' ')
		set_value_color(cub, str, count_s, e_sky);
	else if (str[0] == 'F' && str[1] == ' ')
		set_value_color(cub, str, count_s, e_floor);
	else
		*flag = 1;
}

void		set_value_struct(t_cub3d *cub, char *str, \
		t_count_settings *count_s, t_list **map_list)
{
	static int flag;
	int			i;

	i = 1;
	while (i)
	{
		i = 0;
		if (!flag)
		{
			if (*str)
				settings_selector(cub, str, &flag, count_s);
			else
				break;
		}
		if (flag == 1)
		{
			if (check_count_settings(count_s))
			{
				stop_cub(cub, SETTINGS_FAIL);
				ft_list_clear(map_list);
			}
			ft_list_push_back(map_list, ft_strdup(str));
		}
	}
	free(str);
}

void		init_count_settings(t_count_settings *count_s)
{
	count_s->east = 0;
	count_s->floor = 0;
	count_s->north = 0;
	count_s->res = 0;
	count_s->sky = 0;
	count_s->south = 0;
	count_s->sprite = 0;
	count_s->west = 0;
}

void		set_sprite_list_toarr(t_cub3d *cub)
{
	int				i;
	t_spr_location	*tmp;
	t_list			*tmp_list;

	i = 0;
	tmp_list = cub->sprite.list_spr;
	cub->sprite.count_sprite = ft_list_size(cub->sprite.list_spr);
	cub->sprite.spr = (t_spr_location *)malloc(sizeof(t_spr_location) * \
			cub->sprite.count_sprite);
	while (i < cub->sprite.count_sprite)
	{
		tmp = tmp_list->content;
		cub->sprite.spr[i] = *tmp;
		tmp_list = tmp_list->next;
		i++;
	}
	ft_list_clear(&(tmp_list));
}

void		parse_conf(t_cub3d *cub, char *conf)
{
	char				*str;
	int					log;
	t_count_settings	count_s;
	t_list				*map_list;

	log = 0;
	str = NULL;
	map_list = NULL;
	res_fd_check(conf, cub);
	init_count_settings(&count_s);
	while ((log = get_next_line(cub->fd, &str) > 0))
	{
		set_value_struct(cub, str, &count_s, &map_list);
	}
	check_fd_gnl(cub, log, str);
	set_value_struct(cub, str, &count_s, &map_list);
	cub->field.map = convert_list_toarr(&map_list);
	field_validate(cub);
	set_sprite_list_toarr(cub);
}
