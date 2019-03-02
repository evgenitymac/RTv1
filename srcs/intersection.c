/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:33 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 15:10:35 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

double				sphere_intersection(t_ray ray, t_sphere sphere)
{
	t_vector		oc;
	double			k1;
	double			k2;
	double			k3;

	oc = vector_sub(ray.origin, sphere.center);
	k1 = dot_product(ray.direction, ray.direction);
	k2 = 2 * dot_product(oc, ray.direction);
	k3 = dot_product(oc, oc) - sphere.r * sphere.r;
	return (quandratic_solve(k1, k2, k3));
}

double				cone_intersection(t_ray ray, t_cone cone)
{
	t_vector		co;
	double			k1;
	double			k2;
	double			k3;

	co = vector_sub(ray.origin, cone.tip);
	k1 = dot_product(ray.direction, cone.direction) *
		dot_product(ray.direction, cone.direction) - cos(cone.angle)
		* cos(cone.angle);
	k2 = 2 * (dot_product(ray.direction, cone.direction) *
			dot_product(co, cone.direction)
			- dot_product(ray.direction, co) * cos(cone.angle)
			* cos(cone.angle));
	k3 = dot_product(co, cone.direction) * dot_product(co, cone.direction)
		- dot_product(co, co)
		* cos(cone.angle) * cos(cone.angle);
	return (quandratic_solve(k1, k2, k3));
}

double				cylinder_intersection(t_ray ray, t_cylinder cylinder)
{
	double			k1;
	double			k2;
	double			k3;

	k1 = dot_product(cross_product(ray.direction, cylinder.direction),
			cross_product(ray.direction, cylinder.direction));
	k2 = 2 * dot_product(cross_product(ray.direction, cylinder.direction),
			cross_product(vector_sub(ray.origin, cylinder.center),
				cylinder.direction));
	k3 = dot_product(cross_product(vector_sub(ray.origin, cylinder.center),
				cylinder.direction),
			cross_product(vector_sub(ray.origin, cylinder.center),
				cylinder.direction)) - cylinder.r * cylinder.r;
	return (quandratic_solve(k1, k2, k3));
}

double				plane_intersection(t_ray ray, t_triangle triangle)
{
	double				det;

	det = dot_product(vector_sub(triangle.a, triangle.b),
			cross_product(ray.direction, vector_sub(triangle.c, triangle.a)));
	if (det < 1e-8 && det > -1e-8)
		return (0);
	det = dot_product(vector_sub(triangle.c, triangle.a),
			cross_product(vector_sub(ray.origin, triangle.a),
				vector_sub(triangle.a, triangle.b))) * (1 / det);
	return (det);
}
