/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:25:03 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/02/05 20:46:19 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	x_rotation_matrix(double alpha)
{
	t_matrix_4x4	res;
	double			sin_t;
	double			cos_t;

	sin_t = sin(alpha);
	cos_t = cos(alpha);
	res = identity_matrix();
	res.matrix[1][1] = cos_t;
	res.matrix[2][1] = sin_t;
	res.matrix[1][2] = -sin_t;
	res.matrix[2][2] = cos_t;
	return (res);
}

t_matrix_4x4	y_rotation_matrix(double alpha)
{
	t_matrix_4x4	res;
	double			sin_t;
	double			cos_t;

	sin_t = sin(alpha);
	cos_t = cos(alpha);
	res = identity_matrix();
	res.matrix[0][0] = cos_t;
	res.matrix[0][2] = sin_t;
	res.matrix[2][0] = -sin_t;
	res.matrix[2][2] = cos_t;
	return (res);
}

t_matrix_4x4	z_rotation_matrix(double alpha)
{
	t_matrix_4x4	res;
	double			sin_t;
	double			cos_t;

	sin_t = sin(alpha);
	cos_t = cos(alpha);
	res = identity_matrix();
	res.matrix[0][0] = cos_t;
	res.matrix[1][0] = sin_t;
	res.matrix[0][1] = -sin_t;
	res.matrix[1][1] = cos_t;
	return (res);
}

t_matrix_4x4	arbitrary_rotation_matrix(t_vector axis, double alpha)
{
	t_matrix_4x4	res;
	double			sin_t;
	double			cos_t;
	double			inv_cos_t;

	res = identity_matrix();
	axis = vector_normalize(axis);
	sin_t = sin(alpha);
	cos_t = cos(alpha);
	inv_cos_t = 1 - cos_t;
	res.matrix[0][0] = cos_t + inv_cos_t * axis.x * axis.x;
	res.matrix[0][1] = inv_cos_t * axis.x * axis.y - sin_t * axis.z;
	res.matrix[0][2] = inv_cos_t * axis.x * axis.z + sin_t * axis.y;
	res.matrix[1][0] = inv_cos_t * axis.y * axis.x + sin_t * axis.z;
	res.matrix[1][1] = cos_t + inv_cos_t * axis.y * axis.y;
	res.matrix[1][2] = inv_cos_t * axis.y * axis.z - sin_t * axis.x;
	res.matrix[2][0] = inv_cos_t * axis.z * axis.x - sin_t * axis.y;
	res.matrix[2][1] = inv_cos_t * axis.z * axis.y + sin_t * axis.x;
	res.matrix[2][2] = cos_t + inv_cos_t * axis.z * axis.z;
	return (res);
}
