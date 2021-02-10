/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:08:38 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/10 05:02:28 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		res_fd_check(char *conf, t_cub3d *cub)
{
	char ch;

	if (((cub->fd = open(conf, O_RDONLY)) >= 0) && (ft_strlen(conf) > 4) \
			&& (!(ft_strncmp(".cub", &conf[ft_strlen(conf) - 4], 4))) && \
			read(cub->fd, &ch, 0) >= 0)
	{
		return ;
	}
	else
	{
		stop_cub(cub, CONF_FAIL);
	}
}

void		check_fd_gnl(t_cub3d *cub, int log, char *str)
{
	if (log == -1)
	{
		free(str);
		stop_cub(cub, FD_FAIL);
	}
}

int			check_count_settings(t_count_settings *count_s)
{
	if (count_s->east != 1)
		return (1);
	else if (count_s->floor != 1)
		return (1);
	else if (count_s->north != 1)
		return (1);
	else if (count_s->res != 1)
		return (1);
	else if (count_s->sky != 1)
		return (1);
	else if (count_s->south != 1)
		return (1);
	else if (count_s->sprite != 1)
		return (1);
	else if (count_s->west != 1)
		return (1);
	return (0);
}
