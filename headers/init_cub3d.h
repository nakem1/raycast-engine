/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:00:08 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 21:00:11 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CUB3D_H
# define INIT_CUB3D_H

void		init_camera_field(t_field *field, t_camera *camera);
void		init_tex(t_tex *texture);
void		init_window_ray(t_window *window, t_ray *ray);

#endif
