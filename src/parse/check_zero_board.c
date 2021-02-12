/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:22:06 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/12 03:21:46 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int			check_zero_board(t_field *field)
{
	int i;
	int j;

	i = 0;
	while (field->map[i])
	{
		j = 0;
		while (field->map[i][j])
		{
			if (field->map[i][j] == '0' || field->map[i][j] == '2')
			{
				if (!flood_fill(field, j, i))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
