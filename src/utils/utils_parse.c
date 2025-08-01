/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:04:03 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/17 16:04:05 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	int	*ret;

	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = red << 16 | green << 8 | blue;
	return (ret);
}

int	is_map_line(char *str)
{
	if (!ft_strncmp(str, " ", 1))
		return (1);
	if (!ft_strncmp(str, "1", 1))
		return (1);
	if (!ft_strncmp(str, "2", 1))
		return (1);
	if (!ft_strncmp(str, "\n", 1))
		return (1);
	return (0);
}

int	is_no_ea_so_we_do(char *str)
{
	if (!ft_strncmp(str, "NO", 3))
		return (1);
	if (!ft_strncmp(str, "EA", 3))
		return (1);
	if (!ft_strncmp(str, "SO", 3))
		return (1);
	if (!ft_strncmp(str, "WE", 3))
		return (1);
	if (!ft_strncmp(str, "DO", 3))
		return (1);
	if (!ft_strncmp(str, "S", 2))
		return (1);
	return (0);
}

void	process_the_wall(t_data *data, t_wall *wall_to_parse, char *arr)
{
	if (!ft_strncmp(arr, "DO", 3))
		data->map->walls->door = wall_to_parse;
	else if (!ft_strncmp(arr, "NO", 3))
		data->map->walls->n = wall_to_parse;
	else if (!ft_strncmp(arr, "EA", 3))
		data->map->walls->e = wall_to_parse;
	else if (!ft_strncmp(arr, "SO", 3))
		data->map->walls->s = wall_to_parse;
	else if (!ft_strncmp(arr, "WE", 3))
		data->map->walls->w = wall_to_parse;
	else if (!ft_strncmp(arr, "S", 2))
		data->map->walls->sprite = wall_to_parse;
}
