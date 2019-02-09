/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:48:44 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 17:10:08 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow_int(int x, int y)
{
	int cache;

	if (y == 0)
		return (1);
	cache = ft_pow_int(x, y / 2);
	if ((y % 2) == 0)
		return (cache * cache);
	else
	{
		if (y > 0)
			return (x * cache * cache);
		else
			return ((cache * cache) / x);
	}
	ft_putstr("error");
	return (0);
}
