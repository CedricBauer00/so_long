/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:28:54 by ialiev            #+#    #+#             */
/*   Updated: 2025/02/03 23:00:25 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *line, char *buf)
{
	size_t	line_len;
	size_t	buf_len;
	size_t	i;
	char	*new_str;

	line_len = ft_strlen_gnl(line, 0, 0);
	buf_len = ft_strlen_gnl(buf, 1, 0);
	if (buf[buf_len] == '\n')
		buf_len += 1;
	new_str = (char *)malloc((line_len + buf_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < line_len)
		new_str[i] = line[i];
	i = -1;
	while (++i < buf_len)
		new_str[line_len + i] = buf[i];
	new_str[line_len + buf_len] = '\0';
	if (line != NULL)
		free(line);
	return (new_str);
}

int	ft_strlen_gnl(const char *buf, int indic, int linebreakpos)
{
	int	c;

	c = 0;
	if (indic == 2)
		c = linebreakpos + 1;
	while (buf[c] != '\0' && indic == 0)
		c++;
	while (buf[c] != '\n' && buf[c] != '\0' && indic != 0)
		c++;
	if (indic == 2 && buf[c] == '\n')
		c = c - linebreakpos;
	if (indic == 2 && buf[c] == '\0')
		c = c - linebreakpos -1;
	return (c);
}

char	*ft_writeremainder(char **buf, int *linebreakpos)
{
	char	*line;
	int		i;
	int		c;
	int		j;

	c = 0;
	if (linebreakpos > 0)
		c = linebreakpos[0] + 1;
	i = ft_strlen_gnl((*buf), 2, linebreakpos[0]);
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
	{
		ft_errorcase(buf, &line, 0);
		return (NULL);
	}
	j = 0;
	while (j < i)
		line[j++] = (*buf)[c++];
	line[i] = '\0';
	linebreakpos[0] = c - 1;
	return (line);
}
