/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:18:47 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/03/02 19:03:26 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct		s_matrix_4x4
{
	double			matrix[4][4];
}					t_matrix_4x4;

typedef	struct		s_cylinder
{
	t_vector	center;
	t_vector	direction;
	double		r;
	double		specular;
	int			color;
}					t_cylinder;

typedef struct		s_sphere
{
	t_vector		center;
	double			r;
	double			specular;
	int				color;

}					t_sphere;

typedef struct		s_triangle
{
	t_vector		a;
	t_vector		b;
	t_vector		c;
	double			specular;
	int				color;
}					t_triangle;

typedef	struct		s_cone
{
	t_vector		tip;
	t_vector		direction;
	double			angle;
	double			specular;
	int				color;
}					t_cone;

t_matrix_4x4		matrix_multiply(t_matrix_4x4 a, t_matrix_4x4 b);
t_matrix_4x4		identity_matrix();
t_matrix_4x4		scale_matrix(double a, double b, double c);
t_matrix_4x4		translation_matrix(t_vector v);
t_matrix_4x4		x_rotation_matrix(double alpha);
t_matrix_4x4		y_rotation_matrix(double alpha);
t_matrix_4x4		z_rotation_matrix(double alpha);
t_matrix_4x4		matrix_sum(t_matrix_4x4 a, t_matrix_4x4 b);
t_matrix_4x4		matrix_scalar(t_matrix_4x4 m, double n);
t_matrix_4x4		change_basis(t_vector y, t_vector z, t_vector pos);
t_matrix_4x4		arbitrary_rotation_matrix(t_vector axis, double alpha);

double				vectors_angle(t_vector a, t_vector b);
t_vector			matrix_vector_multiply(t_matrix_4x4 m, t_vector v);
t_vector			vector_matrix_multiply(t_vector v, t_matrix_4x4 m);
double				dot_product(t_vector a, t_vector b);
t_vector			cross_product(t_vector a, t_vector b);
t_vector			vector_sum(t_vector a, t_vector b);
t_vector			vector_sub(t_vector a, t_vector b);
t_vector			vector_scalar_multiply(t_vector v, double n);
t_vector			vector_normalize(t_vector v);
double				vector_length(t_vector v1);

t_vector			rotation_vector_by_x_z(t_vector v, double x, double z);

int					point_in_triangle_2d(t_triangle triangle, t_vector point);

#endif
