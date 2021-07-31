/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:08:06 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:54:55 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	count;

	count = 0;
	while (n--)
	{
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
		if (((unsigned char *)src)[count] == (unsigned char)c)
			return ((unsigned char *)(dest + count + 1));
		count++;
	}
	return (NULL);
}
