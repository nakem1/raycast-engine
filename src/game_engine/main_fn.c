/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:33:21 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/02 13:03:33 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			draw_sprite(t_cub3d *cub)
{
	cub->sprite.spr = (t_spr_location *)malloc(sizeof(t_spr_location) * 2);
	cub->sprite.spr[0].spr_x = 3.5;
	cub->sprite.spr[0].spr_y = 2.5;
	cub->sprite.spr[1].spr_x = 5.5;
	cub->sprite.spr[1].spr_y = 2.5;
	cub->sprite.count_sprite = 2;

	sort_sprites(cub);
	calculate_sprite(cub);
}

/*
** 		Function:			void		calculate()
**
** 		Arguments:			main struct and i
**
** 		return:				void
**
** 		Description:		calculate functions
*/

void			calculate(t_cub3d *cub)
{
	int i;
	
	i = 0;
	while (i < cub->window.res_width)
	{
		calculate_cam(cub, &i);
		cub->field.field_x = cub->player.x_pos;
		cub->field.field_y = cub->player.y_pos;
		calculate_ray_dir(cub);
		calculate_step(cub);
		calculate_wall(cub);
		calculate_height(cub);
		draw(cub, i);
		i++;
	}
	draw_sprite(cub);
}


/*
** 		Function:			void		init_frame()
**
** 		Arguments:			
**
** 		return:				
**
** 		Description:		
*/

t_image			*init_frame(t_cub3d *cub)
{
	t_image *frame;

	if (!(frame = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(frame->pointer = mlx_new_image(cub->window.mlx_ptr, cub->window.res_width \
			,cub->window.res_height)))
	{
		free(frame);
		return (NULL);
	}
	frame->width = cub->window.res_width;
	frame->height = cub->window.res_height;
	if (!(frame->content = mlx_get_data_addr(frame->pointer,
		&(frame->btp), &(frame->line_size), &(frame->end))))
	{
		mlx_destroy_image(cub->window.mlx_ptr, frame->pointer);
		free(frame);
		return (NULL);
	}
	return (frame);
}

/*
** 		Function:			void		main_fn()
**
** 		Arguments:			main struct
**
** 		return:				
**
** 		Description:		
*/

int				main_fn(t_cub3d *cub)
{
	if (!(cub->tmp_image1 = init_frame(cub)))
		stop_cub(cub, "malloc fail (((((");
	event_handler(cub);
	calculate(cub);
	mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr, \
			cub->tmp_image1->pointer, 0, 0);
	mlx_destroy_image(cub->window.mlx_ptr, cub->tmp_image1->pointer);
	return (0);
}
