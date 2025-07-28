/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:25:28 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 13:25:29 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	get_dir_x(float dir)
{
	return (cos(dir / 180 * M_PI));
}

float	get_dir_y(float dir)
{
	return (sin(dir / 180 * M_PI));
}

void	math_free(t_math *math)
{
	if (math->sin)
		free(math->sin);
	if (math->cos)
		free(math->cos);
	if (math->tan)
		free(math->tan);
	free(math);
	math = NULL;
}

t_math	*math_init(void)
{
	t_math	*math;
	int		i;

	math = malloc(sizeof(t_math));
	if (!math)
		return (NULL);
	math->sin = malloc(sizeof(double) * 360);
	math->cos = malloc(sizeof(double) * 360);
	math->tan = malloc(sizeof(double) * 360);
	if (!(math->sin) || !(math->cos) || !(math->tan))
	{
		math_free(math);
		return (NULL);
	}
	i = 0;
	while (i < 360)
	{
		math->sin[i] = fabs(sin((double)i / 180 * M_PI));
		math->cos[i] = fabs(cos((double)i / 180 * M_PI));
		math->tan[i] = fabs(tan((double)i / 180 * M_PI));
		i++;
	}
	return (math);
}
