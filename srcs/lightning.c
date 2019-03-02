/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:20:58 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 21:01:30 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int					shadow_figure_iteration_second(t_render *render,
		t_ray light_ray, double ray_len, double z)
{
	int				i;

	i = -1;
	while (++i < render->cone_nb)
	{
		z = cone_intersection(light_ray, render->cone[i]);
		if (z > 0 && z < ray_len - 1e-8)
			return (1);
	}
	while (++i < render->plane_nb)
	{
		z = plane_intersection(light_ray, render->plane[i]);
		if (z > 0 && z < ray_len - 1e-8)
			return (1);
	}
	return (0);
}

int					shadow_figure_iteration(t_render *render,
		t_ray light_ray, double ray_len)
{
	int				i;
	double			z;

	i = -1;
	z = 0;
	while (++i < render->cylinder_nb)
	{
		z = cylinder_intersection(light_ray, render->cylinder[i]);
		if (z > 0 && z < ray_len - 1e-8)
			return (1);
	}
	i = -1;
	while (++i < render->sphere_nb)
	{
		z = sphere_intersection(light_ray, render->sphere[i]);
		if (z > 0 && z < ray_len - 1e-8)
			return (1);
	}
	return (shadow_figure_iteration_second(render, light_ray, ray_len, z));
}

double				compute_lightning(t_render *render,
		t_cache_vectors *vectors, double specular)
{
	t_vector		light_vector;
	double			intensivity;
	int				j;

	intensivity = 0;
	j = -1;
	while (++j < render->light_nb)
	{
		if (is_shadow(render, vectors->point, j) != 0)
			continue;
		light_vector = vector_normalize(vector_sub(
					render->light[j].position, vectors->point));
		intensivity += light_intense_giver(vectors, light_vector,
				render->light[j]);
		if (specular > 0)
			intensivity += glare_intense_giver(vectors, light_vector,
					render->light[j], specular);
	}
	return (intensivity);
}
