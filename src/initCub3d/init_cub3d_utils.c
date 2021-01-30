/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 05:24:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/13 04:51:28 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		init_image(t_image *ptr)
{
	ptr->pointer = NULL;
	ptr->btp = -1;
	ptr->content = NULL;
	ptr->end = -1;
	ptr->height = -1;
	ptr->line_size = -1;
	ptr->width = -1;
}

void		init_camera_field(t_field *field, t_camera *camera)
{
	field->max_x = -1;
	field->max_y = -1;
	field->map = NULL;
	field->field_x = 0;
	field->field_y = 0;
	camera->x_plane = 0;
	camera->y_plane = 0.66;
}

void		init_tex(t_tex *texture)
{
	init_image(&(texture->north));
	init_image(&(texture->east));
	init_image(&(texture->west));
	init_image(&(texture->south));
	init_image(&(texture->sprite));
	texture->ceil = 0;
	texture->flor = 0;
}

void		init_window_ray(t_window *window, t_ray *ray)
{
	window->bottom_wall = 0;
	window->top_wall = 0;
	window->height_ln = 0;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->res_width = -1;
	window->res_height = -1;
	ray->dir_ray_x = 0;
	ray->dir_ray_y = 0;
	ray->x_deltadist = 0;
	ray->y_deltadist = 0;
	ray->x_sidedist = 0;
	ray->y_sidedist = 0;
	ray->x_ray_step = 0;
	ray->y_ray_step = 0;
}
