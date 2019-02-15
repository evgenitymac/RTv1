/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:20:58 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 15:29:30 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

static	int			shadow_figure_iteration(t_render *render, t_ray light_ray, double ray_len)
{
	int		i;
	double	z;

	i = -1;
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
	return (0);
}


int		is_shadow(t_render *render, t_vector P, int j)
{
	t_vector			light_dir;
	t_ray				light_ray;
	double 				ray_len;

	light_dir = vector_sub(P, render->light[j].position);
	ray_len = vector_length(light_dir);
	light_ray.origin = render->light[j].position;
	light_ray.direction = vector_normalize(light_dir);
	return (shadow_figure_iteration(render, light_ray, ray_len));
}

double			compute_lightning(t_render *render, t_vector P, t_vector N, t_vector V)
{
	t_vector		L;
	double 		i = 0.0;
	int			j = 0;
	double		dot;

	while (j < render->light_nb)
	{
		if (is_shadow(render, P, j) != 0)
			break;
		L = vector_normalize(vector_sub(render->light[j].position, P));
		dot = dot_product(N, L);
		if (dot > 0)
			i += render->light[j].intensity * dot / (vector_length(N) * vector_length(L));
		if (render->sphere->specular != -1 || render->cylinder->specular != -1)
		{
			t_vector R = vector_scalar_multiply(N, 2.0);
			R = vector_scalar_multiply(R, dot_product(N, L));
			R = vector_sub(R, L);
			dot = dot_product(R, V);
			if (dot > 0)
				i+= render->light[j].intensity * pow((dot / (vector_length(R) * vector_length(V))), render->sphere->specular);
		}
		j++;
	}
	return (i);
}
