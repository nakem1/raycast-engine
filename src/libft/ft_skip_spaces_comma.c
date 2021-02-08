/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces_comma.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:14:06 by lmurray           #+#    #+#             */
/*   Updated: 2021/02/08 22:36:00 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skip_spaces_comma(char *str, int *i)
{
	ft_skip_spaces(str, i);
	if (str[*i] == ',')
	{
		*i += 1;
		ft_skip_spaces(str, i);
		if (str[*i] == ',')
		{
			return (1);
		}
		return (0);
	}
	else
	{
		return (1);
	}
	return (1);
}
