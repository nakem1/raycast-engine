/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 00:25:36 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/16 18:56:07 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	*begin_list = NULL;
}
