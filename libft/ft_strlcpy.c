/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:43:01 by melaena           #+#    #+#             */
/*   Updated: 2020/11/02 15:49:55 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	len;
	unsigned int	count;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	count = 0;
	if (destsize == 0)
		return (len);
	while (count < destsize - 1 && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (len);
}
