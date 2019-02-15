/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:15:48 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 14:14:21 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	ray_cast(t_render *render)
{
	int		i;

	i =  -1;
	while (++i < render->win_width * render->win_height)
	{
		render->rays[i].origin = render->cam.position;
		render->rays[i].direction = vector_normalize((t_vector)
				{
				(i % render->win_width - render->win_width / 2),
				 render->cam.focus,
				 -(i / render->win_width - render->win_height / 2),
				 0.
				});
	}
}

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
				double dli = compute_lightning(render, P, N, (t_vector){0, 0, 0, 0});
				if (dli < 1)
					set_pixel(render->surface, i % render->win_width, i / render->win_width, get_color(0x0, 0xFFFF00, dli));
				else 
					set_pixel(render->surface, i % render->win_width, i / render->win_width, get_color(0xFFFF00, 0xFFFFFF, dli - 1));
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
				double dli = compute_lightning(render, P, N, V);
	//				if (dli > 2)
	//					dli = 2;
				if (dli < 1)
					set_pixel(render->surface, i % render->win_width, i / render->win_width, get_color(0x0, 0xFF0000, dli));
				else 
					set_pixel(render->surface, i % render->win_width, i / render->win_width, get_color(0xFF0000, 0xFFFFFF, dli - 1));
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}
