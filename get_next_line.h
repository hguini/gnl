/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:00:15 by hguini            #+#    #+#             */
/*   Updated: 2020/12/01 18:49:28 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int sym);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
