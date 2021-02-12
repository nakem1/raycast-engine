/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:25:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/12 00:38:51 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		set_dir_player_utils(t_cub3d *cub, int i, int j)
{
	if (cub->field.map[i][j] == 'W')
	{
		cub->player.x_dir = -1;
		cub->player.y_dir = 0;
		cub->camera.x_plane = 0;
		cub->camera.y_plane = 0.66;
	}
	else
	{
		cub->player.x_dir = 1;
		cub->player.y_dir = 0;
		cub->camera.x_plane = 0;
		cub->camera.y_plane = -0.66;
	}
}

void		set_dir_player(t_cub3d *cub, int i, int j)
{
	if (cub->field.map[i][j] == 'N')
	{
		cub->player.x_dir = 0;
		cub->player.y_dir = -1;
		cub->camera.x_plane = -0.66;
		cub->camera.y_plane = 0;
	}
	else if (cub->field.map[i][j] == 'S')
	{
		cub->player.x_dir = 0;
		cub->player.y_dir = 1;
		cub->camera.x_plane = 0.66;
		cub->camera.y_plane = 0;
	}
	else
		set_dir_player_utils(cub, i, j);
}

int			map_plr_check(t_cub3d *cub, t_field *map, int *plr_x, int *plr_y)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_strchr("WNSE", map->map[i][j]))
			{
				count++;
				if (count > 1)
					return (1);
				*plr_y = i;
				*plr_x = j;
				set_dir_player(cub, i, j);
			}
		}
	}
	if (count == 0)
		return (1);
	return (0);
}

int			flood_fill(t_field *field, int x, int y)
{
	if (field->map[y][x] == '1' || field->map[y][x] < 0)
		return (1);
	if (field->map[y][x] == ' ' || y < 1 || x < 1 \
			|| y + 1 >= field->max_y \
			|| x + 1 >= field->max_x)
		return (0);
	field->map[y][x] = -field->map[y][x];
	return (flood_fill(field, x - 1, y) && flood_fill(field, x + 1, y) \
			&& flood_fill(field, x, y - 1) && flood_fill(field, x, y + 1));
}

int			map_border_check(t_field *map, int *plr_x, int *plr_y)
{
	int i;
	int j;

	if (!flood_fill(map, *plr_x, *plr_y))
		return (0);
	if (!check_zero_board(map))
		return (0);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] < 0)
				map->map[i][j] = -map->map[i][j];
			j++;
		}
		i++;
	}
	return (1);
}
