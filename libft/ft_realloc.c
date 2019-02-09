/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:57:44 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/24 16:43:20 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*new;

	if (!src)
		return (ft_memalloc(size));
	if (!size)
	{
		free(src);
		return (NULL);
	}
	if (!(new = (void *)ft_memalloc(size)))
		return (NULL);
	new = ft_memcpy(new, src, size);
	free(src);
	return (new);
}
