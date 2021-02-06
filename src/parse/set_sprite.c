/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:08:11 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/06 21:37:54 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_list		*ft_create_spr(double x, double y)
{
	t_list			*tmp;
	t_spr_location	*tmp1;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp1 = (t_spr_location *)malloc(sizeof(t_spr_location));
		tmp1->spr_x = x;
		tmp1->spr_y = y;
		tmp->content = (void *)(tmp1);
		tmp->next = NULL;
	}
	return (tmp);
}

void		ft_list_sprite_push_back(t_list **begin_list, double x, double y)
{
	t_list *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_create_spr(x, y);
	}
	else
		*begin_list = ft_create_spr(x, y);
}
