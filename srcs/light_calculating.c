/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calculating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:02:26 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 21:03:45 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int				is_shadow(t_render *render, t_vector point, int j)
{
	t_vector	light_dir;
	t_ray		light_ray;
	double		ray_len;

	light_dir = vector_sub(point, render->light[j].position);
	ray_len = vector_length(light_dir);
	light_ray.origin = render->light[j].position;
	light_ray.direction = vector_normalize(light_dir);
	return (shadow_figure_iteration(render, light_ray, ray_len));
}

double			specular_dot(t_cache_vectors *vectors, t_vector light_vector)
{
	return (dot_product(vector_sub(vector_scalar_multiply(
vector_scalar_multiply(vectors->normal, 2.0), dot_product(vectors->normal,
	light_vector)), light_vector), vectors->redirection));
}

double			light_intense_giver(t_cache_vectors *vectors,
		t_vector light_vector, t_light light)
{
	if (dot_product(vectors->normal, light_vector) > 0)
		return (light.intensity * dot_product(vectors->normal,
					light_vector) / (vector_length(vectors->normal) *
	vector_length(light_vector)));
		return (0);
}

double			glare_intense_giver(t_cache_vectors *vectors,
		t_vector light_vector, t_light light, double specular)
{
	if (specular_dot(vectors, light_vector) > 0)
		return (light.intensity * pow((specular_dot(vectors,
		light_vector) / (vector_length(vector_sub(
		vector_scalar_multiply(vector_scalar_multiply(
		vectors->normal, 2.0), dot_product(vectors->normal,
		light_vector)), light_vector)) * vector_length(
		vectors->redirection))), specular));
		return (0);
}
