/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces_comma.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:14:06 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/10 03:41:47 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int		ft_skip_spaces_comma(t_cub3d *cub, char *str, int *i)
{
	ft_skip_spaces(str, i);
	if (str[*i] == ',')
	{
		*i += 1;
		ft_skip_spaces(str, i);
		if (str[*i] == ',')
		{
			stop_cub(cub, RGB_FAIL);
		}
		return (0);
	}
	stop_cub(cub, RGB_FAIL);
	return (1);
}
