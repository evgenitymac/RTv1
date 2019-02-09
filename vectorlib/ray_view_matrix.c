/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_view_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:57:36 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 18:45:27 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	ray_view_matrix(t_ray ray)
{
	t_matrix_4x4	rotation;
	t_matrix_4x4	translation;
	t_vector		axis;

	axis = (t_vector){0, 0, -1, 0};
	ray.direction = vector_normalize(ray.direction);
	translation = translation_matrix(vector_scalar_multiply(ray.origin, -1.));
	rotation = arbitrary_rotation_matrix(
			cross_product(ray.direction, axis),
			vectors_angle(ray.direction, axis));
	return (matrix_multiply(translation, rotation));
}
