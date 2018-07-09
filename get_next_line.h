/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:12:31 by hugsbord          #+#    #+#             */
/*   Updated: 2018/07/09 17:31:18 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft.h"

int		get_next_line(const int fd, char **line);

# define BUFF_SIZE		(32)
# define SUCCESS_READ   (1)
# define FINISH			(0)
# define ERROR			(-1)
# define EOF			('\n')

#endif
