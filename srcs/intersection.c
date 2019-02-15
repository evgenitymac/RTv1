/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:33 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 14:11:39 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

double				sphere_intersection(t_ray ray, t_sphere sphere)
{
	t_vector 		oc;
	double			k1;
	double			k2;
	double			k3;

	oc = vector_sub(ray.origin, sphere.center);
	k1 = dot_product(ray.direction, ray.direction);
	k2 = 2 * dot_product(oc, ray.direction);
	k3 = dot_product(oc, oc) - sphere.r * sphere.r;
	
	return (quandratic_solve(k1,k2,k3));
}

double				cylinder_intersection(t_ray ray, t_cylinder cylinder)
{
	t_vector 		e1;
	t_vector		e2;
	t_vector 		e3;
	double			k1;
	double			k2;
	double			k3;

	e1 = cross_product(ray.direction, cylinder.direction);
	e2 = vector_sub(ray.origin, cylinder.center);
	e3 = cross_product(e2, cylinder.direction);
	k1 = dot_product(e1, e1);
	k2 = 2 * dot_product(e1, e3);
	k3 = dot_product(e3, e3) - cylinder.r * cylinder.r;
	return (quandratic_solve(k1, k2, k3));
}

t_intersection			plane_intersection(t_ray ray, t_triangle triangle)
{
	t_vector			e1;
	t_vector			e2;
	t_vector			pvec;
	t_vector			tvec;
	t_vector			qvec;
	t_intersection		res;
	double				det;


	res = (t_intersection){0, 0, 0};
	e1 = vector_sub(triangle.a, triangle.b);
	e2 = vector_sub(triangle.c, triangle.a);
	pvec = cross_product(ray.direction, e2);
	det = dot_product(e1, pvec);
	if (det < 1e-8 && det > -1e-8)
		return (res);
	det = 1 / det;
	tvec = vector_sub(ray.origin, triangle.a);
	res.u = fmod(dot_product(tvec, pvec) * det, 1.);
	res.u < 0 ? res.u += 1 : 0;
	qvec = cross_product(tvec, e1);
	res.v = fmod(dot_product(ray.direction, qvec) * det, 1.);
	res.v < 0 ? res.v += 1 : 0;
	res.z = dot_product(e2, qvec) * det;
	return (res);
}
