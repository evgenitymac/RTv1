/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:49:03 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/23 18:55:13 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vectors_angle(t_vector a, t_vector b)
{
	t_vector	v1;
	t_vector	v2;

	v1 = vector_normalize(a);
	v2 = vector_normalize(b);
	return (acos(dot_product(v1, v2)));
}
