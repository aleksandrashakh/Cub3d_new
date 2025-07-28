/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:30:08 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/13 13:30:10 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	all;
	void	*ptr;

	all = nmemb * size;
	ptr = malloc(all);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, all);
	return (ptr);
}
