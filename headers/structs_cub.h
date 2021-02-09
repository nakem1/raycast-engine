/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_cub.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 04:28:45 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/09 21:43:04 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_CUB_H
# define STRUCTS_CUB_H

typedef struct	s_image
{
	void		*pointer;
	void		*content;
	int			line_size;
	int			btp;
	int			width;
	int			height;
	int			end;
}				t_image;

typedef struct	s_tex
{
	t_image		north;
	t_image		east;
	t_image		west;
	t_image		south;
	t_image		sprite;
	int			ceil;
	int			flor;
	int			x_tex;
	int			y_tex;
	double		pos_tex;
	double		step_tex;
	double		x_wall;
}				t_tex;

typedef struct	s_field
{
	int			field_x;
	int			field_y;
	int			max_x;
	int			max_y;
	char		**map;
}				t_field;

typedef struct	s_window
{
	int			side;
	int			res_width;
	int			res_height;
	int			height_ln;
	int			top_wall;
	int			bottom_wall;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

/*
** 		Description:		x_pos and y_pos represent the
**							position vector of the player
**
**							dirX and dirY represent the
**							direction of the player
*/

typedef struct	s_player
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			step_speed;
}				t_player;

/*
** 		Description:		x_plane and y_plane represent the camera
**							plane of the player.
*/

typedef struct	s_camera
{
	double		x_camera;
	double		x_plane;
	double		y_plane;
}				t_camera;

typedef struct	s_spr_location
{
	double			spr_x;
	double			spr_y;
	double			dist;
}				t_spr_location;

typedef struct	s_sprite
{
	t_spr_location	*spr;
	t_list			*list_spr;
	double			*zbuf;
	double			x_spr;
	double			y_spr;
	double			transpons_matrix_x;
	double			transpons_matrix_y;
	int				spr_scrx;
	int				count_sprite;
	int				height_spr;
	int				top_spr_x;
	int				bottom_spr_x;
	int				top_spr_y;
	int				bottom_spr_y;
	int				w_spr;
	int				rad_x;
	int				rad_y;
}				t_sprite;

typedef struct	s_ray
{
	int				x_ray_step;
	int				y_ray_step;
	double			x_sidedist;
	double			y_sidedist;
	double			x_deltadist;
	double			y_deltadist;
	double			dir_ray_x;
	double			dir_ray_y;
	double			wall_dist;
}				t_ray;

typedef struct	s_event
{
	int			right_turn;
	int			left_turn;
	int			escape;
	int			w;
	int			a;
	int			s;
	int			d;
}				t_event;

typedef struct	s_cub3d
{
	t_field		field;
	t_camera	camera;
	t_tex		texture;
	t_window	window;
	t_player	player;
	t_ray		ray;
	t_event		event;
	t_sprite	sprite;
	t_image		*tmp_image1;
	int			save_flag;
	int			fd;
}				t_cub3d;

typedef struct	s_bmp_head
{
	char		b;
	char		m;
	int			size;
	int			reserv;
	int			offset;
}				t_bmp_head;

typedef struct	s_bmp_inf
{
	int			size;
	int			w;
	int			h;
	short		planes;
	short		bpp;
	int			compress;
	int			size_image;
	int			x_ppm;
	int			y_ppm;
	int			colors;
	int			colors_size;
}				t_bmp_inf;

#endif
