/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:15:45 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/17 16:15:46 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "../cub3d.h"

typedef struct s_hashlist
{
	struct s_hashlist	*next;
	char				*key;
	int					value;
}	t_hashlist;

t_hashlist	*hashlist_new(char *key, int value);
void		hashlist_addfront(t_hashlist **lst, t_hashlist *new);
void		hashlist_addback(t_hashlist **lst, t_hashlist *new);
void		hashlist_clear(t_hashlist **lst);
t_hashlist	***hashtable_init(int n_buckets);
void		hashtable_delete(t_hashlist	***hashtable);
void		hashtable_add(t_hashlist ***hashtable, int size, char *key, \
							int value);
int			hashtable_get(t_hashlist ***hashtable, int size, char *key);

#endif