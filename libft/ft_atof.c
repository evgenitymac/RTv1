/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:27:39 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/27 13:27:41 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		exponent(const char **s, int *e, int *c)
{
	int			sign;
	int			i;

	if (*c == 'e' || *c == 'E')
	{
		sign = 1;
		i = 0;
		*c = *(*s)++;
		if (*c == '+')
			*c = *(*s)++;
		else if (*c == '-')
		{
			*c = *(*s)++;
			sign = -1;
		}
		while (ft_isdigit(*c))
		{
			i = i * 10 + (*c - '0');
			*c = *(*s)++;
		}
		*e += i * sign;
	}
}

static void		exponent_to_d(double *a, int *e)
{
	while (*e > 0)
	{
		*a *= 10.0;
		(*e)--;
	}
	while (*e < 0)
	{
		*a *= 0.1;
		(*e)++;
	}
}

static double	ft_atof2(char const *src, int p, double a)
{
	int			e;
	int			c;

	e = 0;
	if (*src == '-')
	{
		p = -1;
		++src;
	}
	if (*src == '+')
		++src;
	while (*src == ' ')
		++src;
	while ((c = *src++) != '\0' && ft_isdigit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
		while ((c = *src++) != '\0' && ft_isdigit(c))
		{
			a = a * 10.0 + (c - '0');
			e = e - 1;
		}
	exponent(&src, &e, &c);
	exponent_to_d(&a, &e);
	return (p * a);
}

double			ft_atof(char const *src)
{
	int		p;

	p = 1;
	if (!ft_isdigit(src[0]) && src[0] != '-')
		ft_putstr("Not a number\n");
	return (ft_atof2(src, p, 0.0));
}
