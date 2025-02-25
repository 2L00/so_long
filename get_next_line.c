/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:03:28 by abddahma          #+#    #+#             */
/*   Updated: 2024/12/10 10:10:44 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ptr_c;

	i = 0;
	ptr_c = (char)c;
	if (!s && ptr_c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ptr_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ptr_c)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*ft_ft(char *string)
{
	free(string);
	string = NULL;
	return (NULL);
}

static char	*fill_buffer(int fd, char *string, char *buffer)
{
	ssize_t	bite_read;
	char	*tmp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	bite_read = 1;
	while (bite_read > 0)
	{
		bite_read = read(fd, buffer, BUFFER_SIZE);
		if (bite_read == -1)
			return (ft_ft(string));
		if (bite_read == 0)
			break ;
		buffer[bite_read] = '\0';
		if (!string)
			string = ft_strdup("");
		tmp = string;
		string = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (string);
}

static char	*set_buffer(char *write)
{
	ssize_t	i;
	char	*string;

	i = 0;
	while (write[i] != '\n' && write[i] != '\0')
		i++;
	if (write[0] == '\0')
		return (NULL);
	string = ft_substr(write, i + 1, ft_strlen(write) - i);
	if (!string[0])
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	write [i + 1] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*buffer;
	char		*write;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (string);
		string = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	write = fill_buffer(fd, string, buffer);
	free(buffer);
	buffer = NULL;
	if (!write)
		return (NULL);
	string = set_buffer(write);
	return (write);
}
