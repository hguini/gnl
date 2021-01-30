/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:57:00 by hguini            #+#    #+#             */
/*   Updated: 2020/12/06 17:06:12 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*check_remainder(char **remainder, char **line)
{
	char				*p_n;
	char				*tmp;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			tmp = *remainder;
			*line = ft_strdup(*remainder);
			*remainder = ft_strdup(++p_n);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int				cleaning_company(char *p_n, char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (p_n)
		return (1);
	else
		return (0);
}

static int				clear_buf(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (-1);
}

int						get_next_line(int fd, char **line)
{
	static char			*remainder;
	char				*buf;
	char				*p_n;
	char				*tmp;
	int					reading;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	p_n = check_remainder(&remainder, line);
	while (!p_n && (reading = read(fd, buf, BUFFER_SIZE)))
	{
		buf[reading] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if (!(remainder = ft_strdup(++p_n)))
				return (clear_buf(buf));
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (clear_buf(buf));
		free(tmp);
	}
	return (cleaning_company(p_n, buf));
}
