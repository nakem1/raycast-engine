/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 09:43:33 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/27 13:20:25 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<math.h>
# include	"../minilibx/mlx.h" 
# include	"../src/libft/libft.h"
# include	"structs_cub.h"
# include	"init_cub3d.h"
# include	"parse_cub.h"
# include	"errors.h"
# include	"game_cub.h"
# include	<math.h>
# include	<time.h>

void		init_cub3d(t_cub3d *cub);
void		cub(char *conf);
void		parse_conf(t_cub3d *cub, char *conf);
void		stop_cub(t_cub3d *cub, char *fail);
void		ft_quit_message(char *fail);

#endif