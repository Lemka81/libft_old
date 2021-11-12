/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:09:22 by cojacque          #+#    #+#             */
/*   Updated: 2021/10/31 11:09:22 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dst && !src)
		return (dst);
	d = dst;
	s = src;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	return (dst);
}
