/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:21:10 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/26 13:21:12 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_free(t_image *image, t_data *data)
{
	if (image->image)
		mlx_destroy_image(data->mlx, image->image);
	if (image->addr)
		free(image->addr);
	free(image);
	image = NULL;
}

void	free_wall(t_wall *image)
{
	if (image->hashtable)
		hashtable_delete(image->hashtable);
	if (image->pixels)
		free_intarray(image->pixels);
	free(image);
	image = NULL;
}

static void	free_walls(t_walls *walls)
{
	if (walls->n)
		free_wall(walls->n);
	if (walls->e)
		free_wall(walls->e);
	if (walls->s)
		free_wall(walls->s);
	if (walls->w)
		free_wall(walls->w);
	if (walls->door)
		free_wall(walls->door);
	if (walls->sprite)
		free_wall(walls->sprite);
	free(walls);
	walls = NULL;
}

static void	free_map(t_map *map)
{
	if (map->c_ceiling)
		free(map->c_ceiling);
	if (map->c_floor)
		free(map->c_floor);
	if (map->tiles)
		free_intarray(map->tiles);
	if (map->walls)
		free_walls(map->walls);
	free(map);
	map = NULL;
}

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->player)
		free(data->player);
	if (data->math)
		math_free(data->math);
	if (data->sprites)
		free_sprites(data->sprites);
	if (data->z_buffer)
		free(data->z_buffer);
	mlx_destroy(data);
	free(data);
	data = NULL;
}
