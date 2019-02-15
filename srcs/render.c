/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:15:48 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 15:30:33 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"


void	start_render(t_render *render)
{
	int 			i;
	int				t;
	double			z;
	t_intersection	bct;
	
	ray_cast(render);
	i = -1;
	while (++i < render->win_height * render->win_width)
	{
		t = -1;
		z = 1. / 0.;
		while (++t < render->plane_nb)
		{
			bct = plane_intersection(render->rays[i], render->plane[t]);
			if (bct.z > 0 && bct.z < z)
			{
				z = bct.z;
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, z));
				t_vector N = cross_product(vector_sub(render->plane[t].b, render->plane[t].a), vector_sub(render->plane[t].c, render->plane[t].a));
				N = vector_normalize(N);
				if (dot_product(render->rays[i].direction, N) > 0)
					N = vector_scalar_multiply(N, -1);
				dli_pixel(render, compute_lightning(render, P, N, (t_vector){0, 0, 0, 0}), i, render->plane[t].color);
			}
		}
		t = -1;
		while (++t < render->sphere_nb)
		{
			double closest_t = sphere_intersection(render->rays[i], render->sphere[t]);
			if (closest_t > 0. && closest_t < z)
			{
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, closest_t));
				t_vector N = vector_sub(P, render->sphere[t].center);
				N = vector_normalize(N);
				t_vector V = vector_scalar_multiply(render->rays[i].direction, -1);
				dli_pixel(render, compute_lightning(render, P, N, V), i, render->sphere[t].color);
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}
