/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:35:53 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/03 12:50:29 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	i = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			counter++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static char		**ft_add(char const *s, char c, char **tab)
{
	size_t		i;
	size_t		start;
	size_t		index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[index] = ft_strsub(s, start, i - start);
			index++;
			tab[index] = NULL;
		}
	}
	tab[index] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	ft_bzero(tab, (ft_nb_words(s, c) + 1));
	return (ft_add(s, c, tab));
}
