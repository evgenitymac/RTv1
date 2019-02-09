/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:01:21 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 16:43:56 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*char_dst;
	const unsigned char	*char_src;
	size_t				i;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		if (char_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
