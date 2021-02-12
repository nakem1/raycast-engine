/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:59:58 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/12 00:38:02 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CUB_H
# define PARSE_CUB_H

enum			e_settings
{
	e_resolution,
	e_north,
	e_west,
	e_south,
	e_east,
	e_sprite,
	e_sky,
	e_floor,
};

typedef struct	s_count_settings
{
	int			res;
	int			north;
	int			west;
	int			south;
	int			east;
	int			sprite;
	int			sky;
	int			floor;
}				t_count_settings;

void			ft_list_sprite_push_back(t_list **begin_list, double x, \
		double y);
t_list			*ft_create_spr(double x, double y);
void			res_fd_check(char *conf, t_cub3d *cub);
void			set_value_struct(t_cub3d *cub, char *str, \
		t_count_settings *count_s, t_list **map_list);
void			check_fd_gnl(t_cub3d *cub, int log, char *str);
int				check_count_settings(t_count_settings *count_s);
void			set_value_texture(t_cub3d *cub, char *str, \
		t_count_settings *count_s, int set);
void			set_value_color(t_cub3d *cub, char *str, \
		t_count_settings *count_s, int set);
void			set_color_struct(t_cub3d *cub, t_count_settings *count_s, \
int set, int rgb);
void			set_value_res(t_cub3d *cub, char *str, \
		t_count_settings *count_s);
void			check_rgb(t_cub3d *cub, int rgb, char *str, int *i);
char			**convert_list_toarr(t_list **map_list);
int				map_plr_check(t_cub3d *cub, t_field *map, int *plr_x, \
		int *plr_y);
int				flood_fill(t_field *field, int x, int y);
int				map_border_check(t_field *map, int *plr_x, int *plr_y);
int				check_zero_board(t_field *field);
void			field_validate(t_cub3d *cub);
void			set_r_size(t_cub3d *cub);

#endif
