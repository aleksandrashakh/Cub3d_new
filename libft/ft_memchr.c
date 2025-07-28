/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:45:48 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/11 10:45:50 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p1 = s;
	unsigned char		p2;
	unsigned char		i;

	p2 = c;
	i = 0;
	while (i < n)
	{
		if (p1[i] == p2)
			return ((void *)(p1 + i));
		i++;
	}
	return (0);
}
