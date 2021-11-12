/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:13:27 by cojacque          #+#    #+#             */
/*   Updated: 2021/10/31 14:13:27 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int c)
{
	int	len;

	len = 0;
	if (c <= 0)
		len++;
	while (c != 0)
	{
		len++;
		c = c / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	len = ft_len(n);
	num = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
