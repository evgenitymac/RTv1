/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:16:28 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 15:34:42 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*symb;

	symb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		symb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
