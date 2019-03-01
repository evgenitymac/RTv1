/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:37:25 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 17:01:41 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)(-1))
		return (NULL);
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
