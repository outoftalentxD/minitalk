/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:26:24 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:51:44 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dt;
	unsigned char	*sc;

	dt = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dt <= sc)
		ft_memcpy(dt, sc, len);
	else
		while (len--)
			dt[len] = sc[len];
	return (dest);
}
