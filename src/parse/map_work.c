/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:14:24 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:46:30 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

char		**convert_list_toarr(t_list **map_list)
{
	int		size;
	char	**arr;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *map_list;
	size = ft_list_size(*map_list);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	arr[size] = NULL;
	while (tmp != NULL)
	{
		arr[i] = (char *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_list_clear(map_list);
	return (arr);
}

int			letters_inmap(t_cub3d *cub, char *str, int *max_x, int y)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (!ft_strchr("201SEWN ", str[x]))
			return (0);
		if (str[x] == '2')
			ft_list_sprite_push_back(&(cub->sprite.list_spr), \
					(double)(x + 0.5), (double)(y + 0.5));
		x++;
	}
	if (x > *max_x)
		*max_x = x;
	return (1);
}

int			map_letters_check(t_cub3d *cub, t_field *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		if (!letters_inmap(cub, map->map[i], &(map->max_x), i))
			return (1);
		i++;
	}
	map->max_y = i;
	return (0);
}

void		set_plr(t_cub3d *cub, int plr_x, int plr_y)
{
	cub->player.x_pos = plr_x + 0.5;
	cub->player.y_pos = plr_y + 0.5;
	cub->field.map[plr_y][plr_x] = '0';
}

void		field_validate(t_cub3d *cub)
{
	int plr_x;
	int plr_y;

	plr_x = -1;
	plr_y = -1;
	if (map_letters_check(cub, &(cub->field)))
		stop_cub(cub, MAP_LETTERS_FAIL);
	else if (map_plr_check(cub, &(cub->field), &plr_x, &plr_y))
		stop_cub(cub, MAP_PLR_FAIL);
	else if (!map_border_check(&(cub->field), &plr_x, &plr_y))
		stop_cub(cub, MAP_BORDER_FAIL);
	set_plr(cub, plr_x, plr_y);
}
