/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:09:19 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/03/02 19:02:20 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix_4x4	identity_matrix(void)
{
	t_matrix_4x4	res;
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res.matrix[i][j] = 0;
	}
	res.matrix[0][0] = 1;
	res.matrix[1][1] = 1;
	res.matrix[2][2] = 1;
	res.matrix[3][3] = 1;
	return (res);
}
