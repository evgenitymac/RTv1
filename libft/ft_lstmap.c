/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:49:42 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/13 19:23:19 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_freelist(t_list *lst)
{
	t_list		*object;

	while (lst)
	{
		object = lst->next;
		free(lst->content);
		free(lst);
		lst = object;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*object;
	t_list		*tmp;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	object = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_freelist(object);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (object);
}
