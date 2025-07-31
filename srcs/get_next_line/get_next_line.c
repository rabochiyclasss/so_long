/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:49:38 by ibudko            #+#    #+#             */
/*   Updated: 2025/07/31 18:51:25 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	read_from_fd(int fd, char **pointing, char *buff)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && *pointing)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*pointing);
			*pointing = NULL;
			break ;
		}
		buff[bytes_read] = '\0';
		temp = *pointing;
		*pointing = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
}

static void	get_line(char *pointing, char **line)
{
	char	*temp;
	size_t	index;

	index = 0;
	if (!pointing || !pointing[index])
		return ;
	while (pointing[index] && pointing[index] != '\n')
		index++;
	temp = ft_substr(pointing, 0, index + (pointing[index] == '\n'));
	if (temp)
	{
		*line = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (!*line)
		{
			free(temp);
			return ;
		}
	}
	ft_strlcpy(*line, temp, ft_strlen(temp) + 1);
	free(temp);
}

static void	next_pointer(char **pointing, char *line)
{
	char	*temp;

	temp = NULL;
	if (*pointing && line)
		temp = ft_strdup(*pointing + ft_strlen(line));
	free(*pointing);
	*pointing = temp;
}

char	*get_next_line(int fd)
{
	static char	*pointing;
	char		*line;
	char		*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!pointing)
		pointing = ft_strdup("");
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(pointing), pointing = NULL, NULL);
	read_from_fd(fd, &pointing, buff);
	get_line(pointing, &line);
	next_pointer(&pointing, line);
	return (line);
}
