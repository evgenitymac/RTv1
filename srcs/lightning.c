/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:20:58 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/12 20:47:32 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv.h"
#include <stdio.h>

double			compute_lightning(t_render *render, t_vector P, t_vector N, t_vector V)
{
	t_vector		L;
	double 		i = 0.0;
	int			j = 0;
	double		n_dot_l;

	while (j < render->light_nb)
	{
		L = vector_normalize(vector_sub(render->light[j].position, P));
		n_dot_l = dot_product(N, L);
		if (n_dot_l > 0)
			i += render->light[j].intensity * n_dot_l / (vector_length(N) * vector_length(L));
		if (render->sphere->specular != -1)
		{
			t_vector R = vector_scalar_multiply(N, 2.0);
			R = vector_scalar_multiply(R, dot_product(N, L));
			R = vector_sub(R, L);
		//	N = vector_scalar_multiply(vector_scalar_multiply(N, 2.0), dot_product(N, L));
		//	t_vector R = vector_sub(N, L);
			double r_dot_v = dot_product(R, V);
			if (r_dot_v > 0)
				i+= render->light[j].intensity * pow((r_dot_v / (vector_length(R) * vector_length(V))), render->sphere->specular);
		}
		j++;
	}
	return (i);
}
