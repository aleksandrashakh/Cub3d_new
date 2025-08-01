/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:08:14 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/11 11:08:17 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	size_t		i;
	size_t		c;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			b = big + i;
			c = 0;
			while (b[c] == little[c] && (i + c) < len)
			{
				if (little[c + 1] == '\0')
					return ((char *)(big + i));
				c++;
			}
		}
		i++;
	}
	return (NULL);
}
