/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:20:58 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/09 22:45:42 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv.h"
#include <stdio.h>

double			compute_lightning(t_render *render, t_vector P, t_vector N)
{
	t_vector		L;
	double 		i = 0.0;
	int			j = 0;
	double		n_dot_l;

	while (j < render->light_nb)
	{
		L = vector_sub(render->light[j].position, P);
		n_dot_l = dot_product(N, L);
		if (n_dot_l > 0)
			i += render->light[j].intensity * n_dot_l / (vector_length(N) * vector_length(L));
		j++;
	}
	return (i);
}
