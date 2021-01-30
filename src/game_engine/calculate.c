/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:44:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/29 20:29:58 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
** 		Function:			void		calculate_ray_dir()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		calculate deltadist for dda algorithm
*/

void			calculate_ray_dir(t_cub3d *cub)
{
	if (cub->ray.dir_ray_y == 0)
		cub->ray.x_deltadist = 0;
	else
	{
		if (cub->ray.dir_ray_x == 0)
			cub->ray.x_deltadist = 1;
		else
			cub->ray.x_deltadist = fabs(1 / cub->ray.dir_ray_x);
	}
	if (cub->ray.dir_ray_x == 0)
		cub->ray.y_deltadist = 0;
	else
	{
		if (cub->ray.dir_ray_y == 0)
			cub->ray.y_deltadist = 1;
		else
			cub->ray.y_deltadist = fabs(1 / cub->ray.dir_ray_y);
	}
}


/*
** 		Function:			void		calculate_step()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		calculate ray_step. If the ray direction 
**		has a negative x-component, stepX is -1, if the ray direciton has a 
**		positive x-component it's +1. If the x-component is 0, it doesn't
**		matter what value stepX has since it'll then be unused.
*/

void			calculate_step(t_cub3d *cub)
{
	if (cub->ray.dir_ray_x < 0)
	{
		cub->ray.x_ray_step = -1;
		cub->ray.x_sidedist = (cub->player.x_pos - (double)(cub->field.field_x))
				* cub->ray.x_deltadist;
	}
	else
	{
		cub->ray.x_ray_step = 1;
		cub->ray.x_sidedist = (((double)(cub->field.field_x) + 1.0 - \
				cub->player.x_pos) * cub->ray.x_deltadist);
	}
	if (cub->ray.dir_ray_y < 0)
	{
		cub->ray.y_ray_step = -1;
		cub->ray.y_sidedist = (cub->player.y_pos - (double)(cub->field.field_y))
				* cub->ray.y_deltadist;
	}
	else
	{
		cub->ray.y_ray_step = 1;
		cub->ray.y_sidedist = ((double)(cub->field.field_y) + 1.0 - \
				cub->player.y_pos) * cub->ray.y_deltadist;
	}
}


/*
** 		Function:			void		calculate_wall()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		 It's a loop that increments the ray with 1 square
**		every time, until a wall is hit.
*/

void			calculate_wall(t_cub3d *cub)
{
	int		is_wall;

	is_wall = 0;
	cub->window.side = 0;
	while (is_wall == 0)
	{
		if (cub->ray.x_sidedist < cub->ray.y_sidedist)
		{
			cub->ray.x_sidedist += cub->ray.x_deltadist;
			cub->field.field_x += cub->ray.x_ray_step;
			cub->window.side = 0;
		}
		else
		{
			cub->ray.y_sidedist += cub->ray.y_deltadist;
			cub->field.field_y += cub->ray.y_ray_step;
			cub->window.side = 1;
		}
		if (cub->field.map[cub->field.field_y][cub->field.field_x] != '0')
			is_wall = 1;
	} 
	calculate_distto_wall(cub);
}

/*
** 		Function:			void		calculate_distto_wall()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		calculate the distance of the ray to the wall,
**		so that we can calculate how high the wall has to be drawn after this.
*/

void			calculate_distto_wall(t_cub3d *cub)
{
	if (cub->window.side == 0) 
	{
		cub->ray.wall_dist = ((double)(cub->field.field_x) - cub->player.x_pos +
				(1 - cub->ray.x_ray_step) / 2) / cub->ray.dir_ray_x;
	}
	else
	{
		cub->ray.wall_dist = ((double)(cub->field.field_y) - cub->player.y_pos +
				(1 - cub->ray.y_ray_step) / 2) / cub->ray.dir_ray_y;
	}
}


/*
** 		Function:			void		calculate_cam()
**
** 		Arguments:			main struct
**
** 		return:				void
**
** 		Description:		calculate x_camera
*/

void			calculate_cam(t_cub3d *cub, int *i)
{
	cub->camera.x_camera = 2 * *i / (double)(cub->window.res_width) - 1; 
	cub->ray.dir_ray_x = cub->player.x_dir + cub->camera.x_plane * \
			cub->camera.x_camera;
	cub->ray.dir_ray_y = cub->player.y_dir + cub->camera.y_plane * \
			cub->camera.x_camera;
}
