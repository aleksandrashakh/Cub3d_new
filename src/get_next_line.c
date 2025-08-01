/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:51:50 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/03 12:51:53 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut_line_from_memory(char *mem)
{
	char	*cut_mem;
	int		len;

	len = ft_linelen(mem);
	cut_mem = ft_substr(mem, len + 1, ft_strlen(mem + len));
	free(mem);
	return (cut_mem);
}

static char	*get_line_from_memory(char *mem)
{
	char	*line;
	int		len;

	len = ft_linelen(mem);
	line = ft_substr(mem, 0, len + 1);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*read_into_memory(int fd, char *mem)
{
	int		read_valid;
	char	*buf;
	char	*helper;

	read_valid = 1;
	buf = malloc(BUFFER_SIZE + 1);
	while (read_valid > 0 && !ft_strchr(mem, '\n'))
	{
		read_valid = read(fd, buf, BUFFER_SIZE);
		if (read_valid == -1)
		{
			free(buf);
			free(mem);
			return (NULL);
		}
		buf[read_valid] = '\0';
		helper = ft_strjoin(mem, buf);
		free(mem);
		mem = helper;
	}
	free(buf);
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!mem)
	{
		mem = malloc(1);
		*mem = '\0';
	}
	if (!mem)
		return (NULL);
	mem = read_into_memory(fd, mem);
	if (!mem)
		return (NULL);
	line = get_line_from_memory(mem);
	mem = cut_line_from_memory(mem);
	if (*mem == '\0')
	{
		free(mem);
		mem = NULL;
	}
	return (line);
}
