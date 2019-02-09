/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:51:07 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 16:56:08 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_count;
	size_t src_count;
	size_t i;

	dst_count = ft_strlen(dst);
	src_count = ft_strlen(src);
	i = 0;
	if (size <= dst_count)
		return (size + src_count);
	while (src[i] != '\0' && (i < size - dst_count - 1))
	{
		dst[i + dst_count] = src[i];
		i++;
	}
	dst[i + dst_count] = '\0';
	return (dst_count + src_count);
}
