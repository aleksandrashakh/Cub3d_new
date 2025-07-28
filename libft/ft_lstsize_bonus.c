/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:29:59 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:30:01 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
*/

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}
