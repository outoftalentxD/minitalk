/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:12:12 by melaena           #+#    #+#             */
/*   Updated: 2020/11/02 17:04:58 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*ptr;
	unsigned int	count;

	count = -1;
	ptr = (unsigned char *)src;
	chr = (unsigned char)c;
	while (++count < n)
		if (ptr[count] == chr)
			return (ptr + count);
	return (0);
}
