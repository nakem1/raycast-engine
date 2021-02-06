/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:38:38 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/06 17:56:07 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CUB_H
# define GAME_CUB_H

# define W_EVENT 13
# define A_EVENT 0
# define S_EVENT 1
# define D_EVENT 2
# define LEFT_EVENT 123
# define RIGHT_EVENT 124
# define ESCAPE_EVENT 53
# define SKY 1
# define FLOOR 2

enum			e_events
{
	e_forward,
	e_left,
	e_right,
	e_back,
	e_turn_left,
	e_turn_right,
};

void			draw(t_cub3d *cub, int x);
void			draw_frame(t_cub3d *cub, int x);
void			draw_texture_vertical(t_cub3d *cub, t_image *tex, int x);
unsigned int	get_pix_color(t_image *texture, int x, int y);
void			draw_pix(t_cub3d *cub, int x, int y, unsigned int color);
int				game_cub(t_cub3d *cub);
int				main_fn(t_cub3d *cub);

void			calculate_width_sprite(t_cub3d *cub);
void			draw_sprite_vertical(t_cub3d *cub);
void			sort_sprites(t_cub3d *cub);
void			calculate_sprite(t_cub3d *cub);
void			spr_cpy(t_spr_location *src, t_spr_location *dest);

int				set_event_press(int event_code, t_cub3d *cub);
int				set_event_release(int event_code, t_cub3d *cub);
int				set_event_escape(t_cub3d *cub);

void			event_handler(t_cub3d *cub);
void			step_turn_event(t_cub3d *cub, int event);
int				escape_event(t_cub3d *cub);
void			turn_left(t_cub3d *cub);
void			turn_right(t_cub3d *cub);

void			calculate_ray_dir(t_cub3d *cub);
void			calculate_step(t_cub3d *cub);
void			calculate_wall(t_cub3d *cub);
void			calculate_distto_wall(t_cub3d *cub);
void			calculate_cam(t_cub3d *cub, int *i);
void			calculate_height(t_cub3d *cub);

#endif
