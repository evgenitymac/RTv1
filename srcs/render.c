/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:01:57 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 21:56:00 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	start_render(t_render *render)
{
	int 			i;
	int				t;
	double			z;
	
	ray_cast(render);
	i = -1;
	while (++i < render->win_height * render->win_width)
	{
		t = -1;
		z = 1. / 0.;
		while (++t < render->plane_nb)
		{
			double	closest_p = plane_intersection(render->rays[i], render->plane[t]);
			if (closest_p > 0 && closest_p < z)
			{
				z = closest_p;
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, closest_p));
				t_vector N = cross_product(vector_sub(render->plane[t].b, render->plane[t].a), vector_sub(render->plane[t].c, render->plane[t].a));
				N = vector_normalize(N);
				if (dot_product(render->rays[i].direction, N) > 0)
					N = vector_scalar_multiply(N, -1);
				t_vector V = vector_scalar_multiply(render->rays[i].direction, -1);
				dli_pixel(render, compute_lightning(render, P, N, V), i, render->plane[t].color);
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
		t = -1;
		while (++t < render->cylinder_nb)
		{
			double closest_c = cylinder_intersection(render->rays[i], render->cylinder[t]);
			if (closest_c > 0. && closest_c < z)
			{
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, closest_c));
				t_vector N = vector_sub(P, render->cylinder[t].center);
				N = cross_product(N, render->cylinder[t].direction);
				N = vector_normalize(cross_product(render->cylinder[t].center, N));
				t_vector V = vector_scalar_multiply(render->rays[i].direction, -1);
				if (dot_product(N, render->rays[i].direction) > 0)
						N = vector_scalar_multiply(N, -1);
				dli_pixel(render, compute_lightning(render, P, N, V), i, render->cylinder[t].color);
			}
		}
		t = -1;
		while (++t < render->cone_nb)
		{
			double closest_co = cone_intersection(render->rays[i], render->cone[t]);
			if (closest_co > 0. && closest_co < z)
			{
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, closest_co));
				double len = vector_length(vector_sub(P, render->cone[t].tip));
				t_vector C = vector_sum(render->cone[t].tip, vector_scalar_multiply(render->cone[t].direction, len));
				t_vector N = vector_normalize(vector_sub(P, C));
				
				//t_vector N = vector_normalize(vector_sub(P, vector_sum(render->cone[t].tip, vector_scalar_multiply(render->cone[t].direction, vector_length(vector_sub(P, render->cone[t].tip)) / cos(render->cone[t].angle)))));
				

				t_vector V = vector_scalar_multiply(render->rays[i].direction, -1);
				dli_pixel(render, compute_lightning(render, P, N, V), i, render->cone[t].color);
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}
