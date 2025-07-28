/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:17:59 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/21 12:18:00 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sort_sprites_by_distance(t_data *data)
{
	t_sprite	temp;
	int			i;
	int			j;

	i = 0;
	while (i < data->sprites->sprite_count - 1)
	{
		j = 0;
		while (j < data->sprites->sprite_count - i - 1)
		{
			if (data->sprites->sprite[j].distance
				< data->sprites->sprite[j + 1].distance)
			{
				temp = data->sprites->sprite[j];
				data->sprites->sprite[j] = data->sprites->sprite[j + 1];
				data->sprites->sprite[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	draw_stripe(t_data *data, t_image *image, t_sprite *sprite)
{
	int	stripe;
	int	y;
	int	color;
	int	**pixels;

	stripe = sprite->draw_start_x;
	while (stripe < sprite->draw_end_x)
	{
		check_tex_x(data, sprite, stripe);
		if (sprite->transform_y > 0 && sprite->transform_y
			< data->z_buffer[stripe])
		{
			y = sprite->draw_start_y;
			while (y < sprite->draw_end_y)
			{
				check_tex_y(data, sprite, y);
				pixels = data->map->walls->sprite->pixels;
				color = pixels[sprite->tex_y][sprite->tex_x];
				if ((color & 0xFFFFFF) != 0x000000)
					image_pix_put(image, stripe, y, color);
				y++;
			}
		}
		stripe++;
	}
}

static void	calcul_start_end(t_sprite *sprite)
{
	sprite->draw_start_y = -sprite->height / 2 + SCREEN_HEIGHT / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + SCREEN_HEIGHT / 2;
	if (sprite->draw_end_y >= SCREEN_HEIGHT)
		sprite->draw_end_y = SCREEN_HEIGHT - 1;
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= SCREEN_WIDTH)
		sprite->draw_end_x = SCREEN_WIDTH - 1;
}

static void	draw_sprite(t_data *data, t_image *image, t_sprite *sprite)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = sprite->x - data->player->x;
	sprite_y = sprite->y - data->player->y;
	inv_det = 1.0 / (data->player->plane_x * data->player->dir_y
			- data->player->dir_x * data->player->plane_y);
	sprite->transform_x = inv_det * (data->player->dir_y * sprite_x
			- data->player->dir_x * sprite_y);
	sprite->transform_y = inv_det * (-data->player->plane_y * sprite_x
			+ data->player->plane_x * sprite_y);
	if (sprite->transform_y <= 0)
		return ;
	sprite->screen_x = (int)((SCREEN_WIDTH / 2)
			* (1 + sprite->transform_x / sprite->transform_y));
	sprite->height = abs((int)(SCREEN_HEIGHT / sprite->transform_y));
	sprite->width = (sprite->height * data->map->walls->sprite->height)
		/ data->map->walls->sprite->width;
	calcul_start_end(sprite);
	draw_stripe(data, image, sprite);
}

void	render_sprites(t_data *data, t_image *image)
{
	int			i;
	double		dx;
	double		dy;
	t_sprite	*sprite;

	i = 0;
	while (i < data->sprites->sprite_count)
	{
		sprite = &data->sprites->sprite[i];
		dx = sprite->x - data->player->x;
		dy = sprite->y - data->player->y;
		sprite->distance = dx * dx + dy * dy;
		i++;
	}
	sort_sprites_by_distance(data);
	i = 0;
	while (i < data->sprites->sprite_count)
	{
		draw_sprite(data, image, &data->sprites->sprite[i]);
		i++;
	}
}
