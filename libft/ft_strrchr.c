/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:52:55 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:37:22 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		count;

	count = ft_strlen(str);
	if (c == 0)
		return ((char *)str + count);
	while (count--)
		if (str[count] == c)
			return ((char *)str + count);
	return (0);
}
