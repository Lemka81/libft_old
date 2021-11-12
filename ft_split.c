/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:08:54 by cojacque          #+#    #+#             */
/*   Updated: 2021/10/31 14:08:54 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{	
			words ++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*ft_words_len(char const *s, char c)
{
	int		i;
	char	*len;

	i = 0;
	while (*s == c && *s)
		s++;
	while (s[i] != c && s[i])
		i++;
	len = malloc(sizeof(char) * (i + 1));
	if (len == 0)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		len[i] = s[i];
		i++;
	}
	len[i] = '\0';
	return (len);
}

static void	ft_failed_free(char **ptr, int i)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**ptr;

	if (!s)
		return (NULL);
	words = ft_words_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (ptr == 0)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && (*s == c))
			s++;
		ptr[i] = ft_words_len(s, c);
		if (ptr[i] == 0)
			ft_failed_free(ptr, i);
		while (*s && (*s != c))
			s++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
