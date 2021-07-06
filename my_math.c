/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:22:56 by demilan           #+#    #+#             */
/*   Updated: 2021/05/13 01:35:06 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	f_max(double one, double two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

double	f_min(double one, double two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

double	smoothstep(double min, double max, double value)
{
	double	x;
	
	x = f_max(0, f_min(1, (value-min)/(max-min)));
	return (x * x * (3 - 2 * x));
}