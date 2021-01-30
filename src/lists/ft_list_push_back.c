/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:19:23 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/18 13:00:24 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_list_push_back(t_list **begin_list, void *content)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp1 = ft_create_elem(content);
		tmp->next = tmp1;
	}
	else
		*begin_list = ft_create_elem(content);
}
