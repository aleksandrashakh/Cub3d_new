/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:30:32 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 13:30:33 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_tex_x(t_data *data, t_sprite *sprite, int stripe)
{
	sprite->tex_x = (stripe - sprite->draw_start_x)
		* data->map->walls->sprite->width / sprite->width;
	if (sprite->tex_x < 0)
		sprite->tex_x = 0;
	if (sprite->tex_x >= data->map->walls->sprite->width)
		sprite->tex_x = data->map->walls->sprite->width - 1;
}

void	check_tex_y(t_data *data, t_sprite *sprite, int y)
{
	int	d;

	d = y - sprite->draw_start_y;
	sprite->tex_y = d * data->map->walls->sprite->height / sprite->height;
	if (sprite->tex_y < 0)
		sprite->tex_y = 0;
	if (sprite->tex_y >= data->map->walls->sprite->height)
		sprite->tex_x = data->map->walls->sprite->height - 1;
}

void	image_pix_put(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	i = image->bpp - 8;
	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

t_image	*image_init(void *mlx, int height, int width)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->bpp = 0;
	image->endian = 0;
	image->line_len = 0;
	image->addr = 0;
	image->image = mlx_new_image(mlx, width, height);
	image->addr = mlx_get_data_addr(image->image, &image->bpp, \
									&image->line_len, &image->endian);
	image->height = SCREEN_HEIGHT;
	image->width = SCREEN_WIDTH;
	return (image);
}
