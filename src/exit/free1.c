/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:54:31 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 12:54:33 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_sprite(t_sprite *sprite)
{
	free(sprite);
	sprite = NULL;
}

void	free_sprites(t_sprites *sprites)
{
	if (sprites->sprite)
		free_sprite(sprites->sprite);
	free(sprites);
	sprites = NULL;
}
