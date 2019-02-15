/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:19 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 14:09:51 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

double				quandratic_solve(double k1, double k2, double k3)
{
	double 			diskr;
	double			t1;
	double			t2;
	double			tmp;

	diskr = k2 * k2 - 4 * k1 * k3;
	if (diskr < 0)
		return (0);
	t1 = (-k2 + sqrt(diskr)) / (2 * k1);
	t2 = (-k2 - sqrt(diskr)) / (2 * k1);
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 < 0)
		t1 = t2;
	if (t1 < 0)
		return (-1.);
	return (t1);
}
