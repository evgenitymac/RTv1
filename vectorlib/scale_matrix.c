/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:12:15 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/21 19:16:31 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	scale_matrix(double a, double b, double c)
{
	t_matrix_4x4	res;

	res = identity_matrix();
	res.matrix[0][0] = a;
	res.matrix[1][1] = b;
	res.matrix[2][2] = c;
	return (res);
}
