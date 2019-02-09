/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:17:02 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/21 19:21:35 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	translation_matrix(t_vector v)
{
	t_matrix_4x4	res;

	res = identity_matrix();
	res.matrix[3][0] = v.x;
	res.matrix[3][1] = v.y;
	res.matrix[3][2] = v.z;
	return (res);
}
