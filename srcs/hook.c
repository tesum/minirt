/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:26:50 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 18:27:02 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_esc(int keycode, t_mlx *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx_p, img->win_p);
		exit(0);
	}
	return (0);
}

int	destroy(void)
{
	exit(1);
}
