/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:17:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 17:13:55 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		write_bmp(t_cub3d *cub, t_bmp_head *head, t_bmp_inf *inf, \
		char *data)
{
	int		fd;

	fd = open("cub.bmp", O_RDWR | O_CREAT, 0755);
	if (fd < 0)
		stop_cub(cub, FD_FAIL);
	write(fd, &(head->b), 1);
	write(fd, &(head->m), 1);
	write(fd, &(head->size), 4);
	write(fd, &(head->reserv), 4);
	write(fd, &(head->offset), 4);
	write(fd, &(inf->size), 4);
	write(fd, &(inf->w), 4);
	write(fd, &(inf->h), 4);
	write(fd, &(inf->planes), 2);
	write(fd, &(inf->bpp), 2);
	write(fd, &(inf->compress), 4);
	write(fd, &(inf->size_image), 4);
	write(fd, &(inf->x_ppm), 4);
	write(fd, &(inf->y_ppm), 4);
	write(fd, &(inf->colors), 4);
	write(fd, &(inf->colors_size), 4);
	write(fd, data, inf->size_image * inf->bpp / 8);
	close(fd);
}

void		screen_shot(t_cub3d *cub, t_image *tmp)
{
	t_bmp_head		head;
	t_bmp_inf		inf;

	head.b = 'B';
	head.m = 'M';
	head.reserv = 0;
	head.size = 40 + 14 + tmp->btp / 8 * tmp->width * tmp->height;
	head.offset = 40 + 14;
	inf.size = 40;
	inf.w = tmp->width;
	inf.h = -tmp->height;
	inf.planes = 1;
	inf.bpp = (short)tmp->btp;
	inf.compress = 0;
	inf.size_image = tmp->width * tmp->height;
	inf.x_ppm = 1000;
	inf.y_ppm = 1000;
	inf.colors = 0;
	inf.colors_size = 0;
	write_bmp(cub, &head, &inf, tmp->content);
	stop_cub(cub, NULL);
}
