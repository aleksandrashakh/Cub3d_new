/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:24:31 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 13:24:32 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_pov(t_data *data, t_image *image)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray_cast(data, image, i);
		i++;
	}
}
