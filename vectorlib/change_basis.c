/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_basis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:39:40 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/02/08 16:47:32 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	change_basis(t_vector y, t_vector z, t_vector pos)
{
	t_matrix_4x4	res;
	t_vector		x;

	res = identity_matrix();
	x = cross_product(y, z);
	res.matrix[0][0] = x.x;
	res.matrix[0][1] = x.y;
	res.matrix[0][2] = x.z;
	res.matrix[1][0] = y.x;
	res.matrix[1][1] = y.y;
	res.matrix[1][2] = y.z;
	res.matrix[2][0] = z.x;
	res.matrix[2][1] = z.y;
	res.matrix[2][2] = z.z;
	pos = vector_scalar_multiply(pos, -1.);
	return (matrix_multiply(translation_matrix(pos), res));
}
