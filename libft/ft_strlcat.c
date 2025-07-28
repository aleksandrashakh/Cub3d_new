/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:39:37 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 12:39:45 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const	char *src, size_t dstsize)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;

	dest_l = 0;
	src_l = 0;
	i = 0;
	while (src[src_l] != '\0')
	{
		src_l++;
	}
	while (dest[dest_l] != '\0')
	{
		dest_l++;
	}
	if (dest_l >= dstsize)
		return (dstsize + src_l);
	while (i < (dstsize - dest_l) - 1 && src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
