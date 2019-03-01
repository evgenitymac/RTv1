/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_for_int_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:33:24 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 16:22:36 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_need_for_int_to_str(int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
