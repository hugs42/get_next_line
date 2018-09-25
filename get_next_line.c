/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:30 by hugsbord          #+#    #+#             */
/*   Updated: 2018/09/25 17:02:20 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*check_buf(char *buf)
{
	char			*tmp;
	char			*new;

	if (buf == NULL)
		return (NULL);
	tmp = ft_strchr(buf, ENDLINE);
	if (tmp != NULL)
	{
		if ((new = malloc((size_t)(tmp - buf))) == NULL)
			return (NULL);
		ft_memcpy(new, buf, (tmp - buf));
		ft_memmove(buf, tmp + 1, ft_strlen(tmp));
		return (new);
	}
	return (NULL);
}

static int		ft_strjoin_free(char **buf, char *tmp)
{
	char			*new;

	if (*buf == NULL)
	{
		if ((*buf = ft_strdup(tmp)) == NULL)
			return (ERROR);
	}
	else
	{
		if ((new = ft_strjoin(*buf, tmp)) == NULL)
			return (ERROR);
		free(*buf);
		*buf = new;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buf = NULL;
	char			tmp[BUFF_SIZE + 1];
	ssize_t			read_ret;

	if (fd < 0 || line == NULL)
		return (ERROR);
	if ((*line = check_buf(buf)) != NULL)
		return (SUCCESS_READ);
	while ((read_ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[read_ret] = '\0';
		if (ft_strjoin_free(&buf, tmp) == ERROR)
			return (ERROR);
		if ((*line = check_buf(buf)) != NULL)
			return (SUCCESS_READ);
	}
	if (read_ret == -1)
		return (ERROR);
	if (buf != NULL)
	{
		*line = ft_strdup(buf);
		free(buf);
		buf = NULL;
	}
	return (FINISH);
}
