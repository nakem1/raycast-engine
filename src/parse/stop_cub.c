/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:18:59 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:38:09 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		ft_quit_message(char *fail)
{
	if (!fail)
		exit(0);
	ft_putendl_fd("Error.", 2);
	ft_putendl_fd(fail, 2);
	exit(0);
}

void		stop_cub(t_cub3d *cub, char *fail)
{
	if (cub->fd > -1)
		close(cub->fd);
	ft_quit_message(fail);
}
