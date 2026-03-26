/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:54:46 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/04 18:54:51 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\n' && s[len])
		len++;
	if (s[len] == '\n')
		len++;
	return (ft_substr(s, 0, len));
}

static char	*ft_trim(char *s)
{
	char	*nl;

	if (!s)
		return (NULL);
	nl = ft_strchr(s, '\n');
	if (!nl || nl[1] == '\0')
		return (NULL);
	return (ft_substr(nl + 1, 0, ft_strlen((nl + 1))));
}

static char	*ft_read_loop(int fd, char *remainder, char *buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		if (!remainder)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (remainder);
}

static char	*ft_read(int fd, char *remainder)
{
	char	*buffer;

	if (remainder && ft_strchr(remainder, '\n'))
		return (remainder);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(remainder);
		return (NULL);
	}
	if (!remainder)
		remainder = ft_strjoin("", "");
	if (!remainder)
	{
		free(buffer);
		return (NULL);
	}
	return (ft_read_loop(fd, remainder, buffer));
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_read(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	temp = remainder;
	remainder = ft_trim(remainder);
	free(temp);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
