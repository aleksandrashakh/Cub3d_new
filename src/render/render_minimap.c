/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:24:08 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 13:24:09 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	color_select(t_data *data, int i, int j)
{
	if (i > data->map->height - 1 || j > data->map->width - 1)
		return (0xFFFFFF);
	else if (data->map->tiles[i][j] == tile_empty)
		return (0xFFFFFF);
	else if (data->map->tiles[i][j] == tile_wall)
		return (0x0);
	else if (data->map->tiles[i][j] == tile_door)
		return (0x00FF00);
	else if (data->map->tiles[i][j] == tile_door_open)
		return (0x0000FF);
	else if (data->map->tiles[i][j] == tile_sprite)
		return (0xFF00FF);
	else
		return (0xD3D3D3);
}

static void	draw_pixel(t_data *data, t_image *image, int *indexes)
{
	int	color;

	if (indexes[0] < 0 || indexes[1] < 0)
		color = 0xFFFFFF;
	else
		color = color_select(data, (indexes[0] / 10), (indexes[1] / 10));
	image_pix_put(image, indexes[3], indexes[2], color);
}

static void	draw_map(t_data *data, t_image *image, int *indexes)
{
	int		target_x;
	int		target_y;

	target_y = 10 * (data->player->y) + 100;
	target_x = 10 * (data->player->x) + 100;
	indexes[0] = 10 * (data->player->y) - 100;
	indexes[1] = 10 * (data->player->x) - 100;
	indexes[2] = 0;
	indexes[3] = 0;
	while (indexes[0] < target_y)
	{
		indexes[1] = 10 * (data->player->x) - 100;
		indexes[3] = 0;
		while (indexes[1] < target_x)
		{
			draw_pixel(data, image, indexes);
			indexes[1]++;
			indexes[3]++;
		}
		indexes[0]++;
		indexes[2]++;
	}
}

static void	draw_player(t_data *data, t_image *image)
{
	int	i;
	int	j;

	i = 97;
	while (i < 103)
	{
		j = 97;
		while (j < 103)
		{
			image_pix_put(image, i, j, 0xFF0000);
			j++;
		}
		i++;
	}
	(void) data;
}

void	render_minimap(t_data *data, t_image *image)
{
	int	*indexes;

	indexes = malloc(sizeof(int) * 4);
	if (!indexes)
	{
		image_free(image, data);
		error_msg_exit(data, "Error mallocing int array");
	}
	draw_map(data, image, indexes);
	draw_player(data, image);
	free(indexes);
}
