/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:21:31 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/23 17:45:06 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_plane		plane_equation(t_vector normal, t_vector point)
{
	t_plane	res;

	res.a = normal.x;
	res.b = normal.y;
	res.c = normal.z;
	res.d = -(normal.x * point.x) -
		(normal.y * point.y) -
		(normal.z * point.z);
	return (res);
}

double		solve_plane_x(t_plane pl, double y, double z)
{
	return (-(pl.d + pl.b * y + pl.c * z) / pl.a);
}

double		solve_plane_y(t_plane pl, double x, double z)
{
	return (-(pl.d + pl.a * x + pl.c * z) / pl.b);
}

double		solve_plane_z(t_plane pl, double x, double y)
{
	return (-(pl.d + pl.a * x + pl.b * y) / pl.c);
}
