/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:55:08 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 16:57:31 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (needle == haystack)
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i] == haystack[i] && needle[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		i = 0;
	}
	return (NULL);
}
