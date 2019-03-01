/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:44:30 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 15:43:56 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last;
	char	*str;

	str = (char *)s;
	last = ft_strlen(str) + 1;
	while (last--)
	{
		if (str[last] == (char)c)
			return (&str[last]);
	}
	return (NULL);
}
