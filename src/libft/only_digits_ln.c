/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_digits_ln.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:27:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/17 15:24:22 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			only_digits_ln(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && !str[i])
			return (0);
		i++;
	}
	return (1);
}