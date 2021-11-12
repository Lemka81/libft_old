/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:11:09 by cojacque          #+#    #+#             */
/*   Updated: 2021/10/31 11:11:09 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (d > size - 1)
		return (size + ft_strlen(src));
	while ((d + s < size - 1) && src[s])
	{
		dst[d + s] = src[s];
		s++;
	}
	dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
