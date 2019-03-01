/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:02:30 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/03 19:03:00 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		i;

	count = ft_need_for_int_to_str(n);
	i = 0;
	if (!(str = ft_strnew(count)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n *= -1;
		count--;
	}
	while (count)
	{
		count--;
		str[i] = '0' + n / ft_pow_int(10, count);
		n = n % ft_pow_int(10, count);
		i++;
	}
	return (str);
}
