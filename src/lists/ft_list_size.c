/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:17:21 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/16 18:58:14 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
