/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:58:53 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/18 21:56:50 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *data;

	if (!(data = (unsigned char *)malloc(size * sizeof(data))))
		return (NULL);
	ft_memset(data, 0, size);
	return (data);
}
